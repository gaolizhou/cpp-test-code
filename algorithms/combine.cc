//
// Created by lizgao on 4/13/19.
//
#include <glog/logging.h>
#include <vector>
#include <iostream>


namespace {

std::vector<std::vector<int>> combile(int n, int m, int a[]) {
  if (m==0) {
    return {{}};
  }
  //LOG(INFO) << n<<","<<m;
  std::vector<std::vector<int>> result;
  if (m == n) {
    std::vector<int> res;
    for (int i = 0; i < n; ++i) {
      res.push_back(a[i]);
    }
    result.push_back(res);
    return result;
  }

  auto result_1 = combile(n-1, m, a);
  auto result_2 = combile(n-1, m-1, a);

  result = result_1;
  for (auto &res : result_2) {
    res.push_back(a[n-1]);
    result.push_back(res);
  }
  return result;

}

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}


}



void combine_test() {

  constexpr int N = 10;
  constexpr int M = 5;
  int a[N];
  for (int i=0;i<N;i++) {
    a[i] = i;
  }

  auto result =  combile(N, M, a);
  for (auto &res: result) {
    for(auto v : res) {
      std::cout << v << " ";
    }
    std::cout << std::endl;
  }

  LOG(INFO) << "Total = " << result.size() << ", correct=" << factorial(N)/(factorial(M)*factorial(N-M));

}
