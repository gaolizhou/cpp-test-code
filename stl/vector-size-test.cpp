//
// Created by lizgao on 10/31/18.
//

#include <string>
#include <vector>
#include <glog/logging.h>
void vector_size_test()
{
  {
    std::vector<int> v{3};
    LOG(INFO) << "vector<int> v{3} size() "<< v.size();
  }
  {
    std::vector<std::string> v{3};
    LOG(INFO) << "vector<string> v{3} size() " << v.size();
  }
  {
    std::vector<int> v{0};
    LOG(INFO) << "vector<int> v{0} size() " << v.size();
  }
  {
    // for extra goodness
    std::vector<std::string> v{10};
    LOG(INFO) << "vector<string> v{0} size() " << v.size();
  }
}

