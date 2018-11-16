//
// Created by lizgao on 11/14/18.
//
#include <memory>
namespace {

template<class T>
class UConnection : public std::enable_shared_from_this<UConnection<T>> {
 public:
  template <class FUN>
  int SendDataZeroCopy(FUN cb) {
    static_cast<T&>(*this).DoSendDataZeroCopy(cb);
  }

};

class ConnectionRdma : public UConnection<ConnectionRdma> {
 public:
  template <class FUN>
  int DoSendDataZeroCopy(FUN cb) {
    return cb() + 2;
  }
};

}

void crtp_bind_test() {
  ConnectionRdma conn_rdma;
  int data[100];
  int len = 100;
  for (int i = 0; i < len; ++i) {
    data [i] = i;
  }
  auto f = [=]() -> int {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
      sum += data [i];
    }
    return sum;
  };

  conn_rdma.SendDataZeroCopy(f);
}