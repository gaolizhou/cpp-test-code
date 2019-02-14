cmake_minimum_required(VERSION 3.5)
project(cmake_test)

set(CMAKE_CXX_STANDARD 11)
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -ggdb3" )

#SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=leak" )
#SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O3" )
add_executable(cmake_test main.cpp Foo.cc Foo.h my_enable_if.cc temlate_spec.cc ThreadPool.h thread_pool_test.cc
        accmulate-lambda-performance.cc cyclic-ref-shared_ptr.cc binary2hex.cc shared_ptr_test.cc sanitize-test.cc
        std-array-test.cc is-class-traits.cc atomic-test.cc vector-unique-ptr.cc bind-rvalue-reference.cc
        using-base-constructor.cpp using-base-function.cpp unique-ptr-nullptr.cpp move-vector-test.cpp
        move-string-test.cpp memory-leak.cpp shr-mem.cpp thread-pool-memory-leak.cpp memory-pool-memory-leak.cpp
        mmap-malloc-test.cpp jiyou-problem.cpp zombie-process.cpp virtual-fun-class-size.cpp thread-local-variable.cpp
        bind-inside.cpp epoll-test-normal-file.cpp enable_from_this-test.cpp forward-list-test.cpp zombie-test.cpp
        lock-free-link-list.cpp leveldb-test.cpp atomic-op-test.cpp atomic_op_test2.cpp multiple-thread-cpu-cache-volatile.cpp
        slab-benchmark.cpp get_clock.c get_clock.h lru-cache.cpp rand-test.cpp bind-lambda-performance-test.cpp
        libevent-bufferevent-client.cpp libevent_empty_loop_test.cpp thundering-herd/socket-accept-fork.cpp sfinae-test.cpp mutex_futex-test.cpp dup-fd-test.cpp
        libevent-sockpair.cpp clone-test.cpp static_cast-test.cpp vptr-test.cpp alloctor-test.cpp thread-local-test.cpp page-cache-test.cpp vfork-test.cpp
        fork-test.cpp vector-gdb-test.cpp malloc-info-test.cpp shared-ptr-size.cpp coroutine-test.cpp dead-loop.cpp template/var-args.cpp page-table.cpp
        performance/bind-performance.cpp pod_init.cpp performance/huge-lambda-callback.cpp algorithms/time-wheel.cpp io/direct-io-test.cpp io/libaio-test.cpp
        framework/loop.cpp framework/loop.h io/bash_test.cpp io/pip-test.cpp cpu-friendly-program/false-sharing.cpp stl/vector-size-test.cpp stl/map-test.cpp
        mmhash/mmhash_test.cpp mmhash/hash_ring_test.cpp udisk-opt/int2str.cpp io/unlink-test.cc cstyle-init.cc signal-handle/signal_thread_context.cc
        performance/bind_malloc_free.cc performance/crtp-bind.cc performance/fixed_size_function.h performance/fix_size_function_test.cc
        performance/unordered_map_alloctor.cc lambda_delay_call.cc performance/derived-inline-virtual-function.cc restful/http-server-test.cc
        performance/atomic-cost.cc performance/memory-copy-performance.cc io/atimic-write-multithread.cc atomic/atomic-bw.cc mmap/mmap-pagefault.cc memlayout/multithread-memlayout.cc lockfree/cas-test.cc lockfree/lockfree-linklist.cc lockfree/lockfree-stack.cc algorithms/eb.cc co-routine/setjmp-longjmp.cc algorithms/rehash-test.cc mmap/mlock-test.cc mmap/shared-memory.cc cast-test/static-cast-test.cc multithread/async-test.cc multithread/async-pattern.cc multithread/coro.cc multithread/coroutine-test.cc multithread/ucontext-test.cc shm/shm-test.cc memory-mangement/buddy-test.cc multithread/promise-future.cc multithread/temp-obj-dtor.cc string-test/substr-test.cc signal-handle/signal-pipe-test.cc os-study/thread-scheduler.cc os-study/malloc-mmap-test.cc cisco/longest-prefix-match.cc template/sfinae-test.cc)
#target_link_libraries(cmake_test glog gflags unwind lzma pthread)
add_subdirectory(mmhash)
target_link_libraries(cmake_test glog gflags leveldb pthread event event_core hash_ring)


add_executable(bm benchmark/bm_string_copy.cpp benchmark/bm_main.cpp benchmark/bm_slab.cpp benchmark/bm_unorder_set_map.cpp libs/bm_glog.cpp
               benchmark/bm_function_bind.cpp benchmark/bm_stringstream.cpp)
target_link_libraries(bm glog gflags benchmark pthread)
