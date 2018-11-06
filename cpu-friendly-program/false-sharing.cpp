//
// Created by lizgao on 10/30/18.
//

#include <glog/logging.h>
#include <memory>
namespace {

struct AioArgs {
  void *loophandle;
  int lc_id[100];
};

}

void free_crash() {
  auto args = new AioArgs();
  //delete args;
  auto guard = std::unique_ptr<AioArgs>(args);
  LOG(INFO) << "size=" << sizeof(AioArgs);
}