//
// Created by lizgao on 2/25/19.
//

#include <glog/logging.h>

void signal_handle_no_syscall() {
  int sum = 0;
  while(true) {
    for(int i=0;i<1000;i++) {
      sum += i;
    }
  }
  LOG(INFO) << "sum = " << sum;
}

/*
17:08:57 0   22655   22655   cmake_test      do_exit
        do_exit+0x1 [kernel]
        get_signal+0x27b [kernel]
        do_signal+0x37 [kernel]
        exit_to_usermode_loop+0x73 [kernel]
        prepare_exit_to_usermode+0x77 [kernel]
        swapgs_restore_regs_and_return_to_usermode+0x0 [kernel]
        [unknown]
        [unknown]
        [unknown]
        [unknown]

^C
ubuntu@10-25-189-161:~/bcc/tools$ sudo ./trace.py -T -C -U -K do_exit
TIME     CPU PID     TID     COMM            FUNC

17:09:39 0   22676   22676   cmake_test      do_exit
        do_exit+0x1 [kernel]
        get_signal+0x27b [kernel]
        do_signal+0x37 [kernel]
        exit_to_usermode_loop+0x73 [kernel]
        prepare_exit_to_usermode+0x77 [kernel]
        swapgs_restore_regs_and_return_to_usermode+0x0 [kernel]
        [unknown]
        [unknown]
        [unknown]
        [unknown]


 */



void signal_handle_with_syscall() {
  int sum = 0;
  while(true) {
    for(int i=0;i<1000;i++) {
      sum += i;
    }
  }
  LOG(INFO) << "sum = " << sum;
}
