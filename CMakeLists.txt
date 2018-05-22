cmake_minimum_required(VERSION 3.5)
project(cmake_test)

set(CMAKE_CXX_STANDARD 11)

#SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=leak" )
#SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O3" )

include_directories(include)
link_directories(libs)
add_executable(cmake_test main.cpp Foo.cc Foo.h my_enable_if.cc temlate_spec.cc ThreadPool.h thread_pool_test.cc accmulate-lambda-performance.cc cyclic-ref-shared_ptr.cc binary2hex.cc shared_ptr_test.cc sanitize-test.cc std-array-test.cc is-class-traits.cc atomic-test.cc vector-unique-ptr.cc bind-rvalue-reference.cc using-base-constructor.cpp using-base-function.cpp unique-ptr-nullptr.cpp move-vector-test.cpp move-string-test.cpp memory-leak.cpp shr-mem.cpp thread-pool-memory-leak.cpp memory-pool-memory-leak.cpp mmap-malloc-test.cpp jiyou-problem.cpp zombie-process.cpp virtual-fun-class-size.cpp thread-local-variable.cpp bind-inside.cpp)
target_link_libraries(cmake_test glog gflags unwind lzma pthread)