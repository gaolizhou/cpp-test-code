cmake_minimum_required(VERSION 3.5)
project(cmake_test)

set(CMAKE_CXX_STANDARD 11)

#SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=leak" )
#SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O3" )
set(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)
include_directories(BEFORE /usr/local/include)
link_directories(BEFORE /usr/local/libs)
add_executable(cmake_test main.cpp Foo.cc Foo.h my_enable_if.cc temlate_spec.cc ThreadPool.h thread_pool_test.cc accmulate-lambda-performance.cc cyclic-ref-shared_ptr.cc binary2hex.cc shared_ptr_test.cc sanitize-test.cc std-array-test.cc is-class-traits.cc atomic-test.cc vector-unique-ptr.cc bind-rvalue-reference.cc using-base-constructor.cpp using-base-function.cpp unique-ptr-nullptr.cpp move-vector-test.cpp move-string-test.cpp memory-leak.cpp shr-mem.cpp thread-pool-memory-leak.cpp memory-pool-memory-leak.cpp mmap-malloc-test.cpp jiyou-problem.cpp zombie-process.cpp virtual-fun-class-size.cpp thread-local-variable.cpp bind-inside.cpp epoll-test-normal-file.cpp enable_from_this-test.cpp forward-list-test.cpp zombie-test.cpp lock-free-link-list.cpp leveldb-test.cpp atomic-op-test.cpp atomic_op_test2.cpp multiple-thread-cpu-cache-volatile.cpp slab-benchmark.cpp get_clock.c get_clock.h lru-cache.cpp rand-test.cpp bind-lambda-performance-test.cpp libevent-bufferevent-client.cpp libevent_empty_loop_test.cpp)
#target_link_libraries(cmake_test glog gflags unwind lzma pthread)
target_link_libraries(cmake_test glog gflags leveldb pthread event event_core)


add_executable(bm bm_string_copy.cpp bm_main.cpp  bm_slab.cpp bm_unorder_set_map.cpp libs/bm_glog.cpp)
target_link_libraries(bm glog gflags benchmark pthread)
