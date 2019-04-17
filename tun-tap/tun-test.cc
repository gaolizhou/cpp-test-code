//
// Created by lizgao on 4/16/19.
//
#include <sys/socket.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <glog/logging.h>
#include <fcntl.h>
#include <sys/ioctl.h>

namespace {
int tun_create(char *dev, int flags) {
  struct ifreq ifr;
  int fd, err;

  if (!dev) {
    LOG(ERROR) << "dev == null!";
    return -1;
  }

  if ((fd = open("/dev/net/tun", O_RDWR)) < 0)
    return fd;

  memset(&ifr, 0, sizeof(ifr));
  ifr.ifr_flags |= flags;
  if (*dev != '\0')
    strncpy(ifr.ifr_name, dev, IFNAMSIZ);
  if ((err = ioctl(fd, TUNSETIFF, (void *) &ifr)) < 0) {
    close(fd);
    return err;
  }
  strcpy(dev, ifr.ifr_name);

  return fd;
}
}

void tun_test()
{
  int tun, ret;
  char tun_name[IFNAMSIZ];
  unsigned char buf[4096];

  tun_name[0] = '\0';
  tun = tun_create(tun_name, IFF_TUN | IFF_NO_PI);
  if (tun < 0) {
    perror("tun_create");
    return;
  }
  printf("TUN name is %s\n", tun_name);

  while (1) {
    unsigned char ip[4];

    ret = read(tun, buf, sizeof(buf));
    if (ret < 0)
      break;
    memcpy(ip, &buf[12], 4);
    memcpy(&buf[12], &buf[16], 4);
    memcpy(&buf[16], ip, 4);
    buf[20] = 0;
    *((unsigned short*)&buf[22]) += 8;
    printf("read %d bytes\n", ret);
    ret = write(tun, buf, ret);
    printf("write %d bytes\n", ret);
  }
}