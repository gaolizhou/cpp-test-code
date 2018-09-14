//
// Created by lizgao on 9/11/18.
//

#include <unistd.h>
#include <sys/mman.h>
#include <glog/logging.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <memory>
#include <vector>
#include <string>

void page_cache_test() {
  const char *fname = "1.txt";
  int fd = open(fname, O_RDONLY);
  if (fd == -1) {
    LOG(ERROR) << "open fail " << fname;
    return;
  }
  struct stat sb;
  if (fstat(fd, &sb) == -1)    {
    LOG(ERROR) << "fstat fail " << fname;
    return;
  }
  auto offset = 0;
  auto pa_offset = offset & ~(sysconf(_SC_PAGE_SIZE) - 1);
  /* offset for mmap() must be page aligned */
  if (offset >= sb.st_size) {
    LOG(ERROR) << "offset is past end of file";
    return;
  }

  auto length = sb.st_size - offset;

  LOG(INFO) << "size=" << sb.st_size << ", pa_offset=" << pa_offset;
  auto addr = mmap(NULL, length + offset - pa_offset, PROT_READ,
              MAP_SHARED, fd, pa_offset);
  if (addr == MAP_FAILED) {
    LOG(ERROR) << "mmap fail" << strerror(errno);
    return;
  }

  auto page_size = sysconf(_SC_PAGESIZE);
  auto vec_size = (length+page_size-1) / page_size;
  LOG(INFO) << "vec-size="<<vec_size;
  std::vector<unsigned char> vec(vec_size);
  auto ret = mincore(addr, sb.st_size, &vec[0]);

  std::string result;
  for (auto v : vec) {
    result.append(std::to_string((int)v));
  }

  LOG(INFO) << result;


  munmap(addr, length + offset - pa_offset);
}