//
// Created by lizgao on 3/30/18.
//
#include <cstdint>
#include <numeric>
#include <string>
#include <vector>
#include <glog/logging.h>

namespace {

void for_loop_solution(const std::vector<std::string> &values) {
  std::size_t total_length = 0;
  std::size_t cnt = values.size();
  LOG(INFO) << "Begin for_loop_solution";
  for (std::size_t i = 0; i < cnt; ++i) {
    total_length += values[i].size();
  }
  LOG(INFO) << "End for_loop_solution = " << total_length;
}
void for_loop_solution_it(const std::vector<std::string> &values) {
  std::size_t total_length = 0;
  LOG(INFO) << "Begin for_loop_solution_it";
  for (const auto & str : values ) {
    total_length += str.size();
  }
  LOG(INFO) << "End for_loop_solution_it = " << total_length;
}

void accumulate_solution(const std::vector<std::string> &values) {
  LOG(INFO) << "Begin accumulate_solution";
  std::size_t total_length = std::accumulate(
        values.begin(), values.end(), 0ULL,
        [](uint64_t sum, const std::string& str) { return sum + str.size(); });
  LOG(INFO) << "End accumulate_solution = " << total_length;
}
}

void accumulate_lambda_performance_test() {
  std::vector<std::string> str_list(100000000, std::string(80, '*'));
  for_loop_solution(str_list);
  accumulate_solution(str_list);
  for_loop_solution_it(str_list);
}