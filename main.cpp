#include <glog/logging.h>

/*
 *
 *
 * 0 - debug
1 - info (still a LOT of outputs)
2 - warnings
3 - errors


 */
void mmap_pagefault();
/*
void logging_level_test () {
  google::InitGoogleLogging("XXX");
  google::SetCommandLineOption("GLOG_minloglevel", "2");

  VLOG(0) << "Verbose 0";
  VLOG(1) << "Verbose 1";
  VLOG(2) << "Verbose 2";
  VLOG(3) << "Verbose 3";
  VLOG(4) << "Verbose 4";
  LOG(INFO) << "LOG(INFO)";
  LOG(WARNING) << "LOG(WARNING)";
  LOG(ERROR) << "LOG(ERROR)";
  //LOG(FATAL) << "LOG(FATAL)";

}
 */
int main() {
  mmap_pagefault();
  return 0;
}