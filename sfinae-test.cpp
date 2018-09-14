//
// Created by lizgao on 8/21/18.
//
#include <type_traits>
#include <glog/logging.h>
namespace {

class Base {
 public:
  virtual ~Base() = default;
  virtual void fun() = 0;
};

class D : Base {
 public:
  ~D() override = default;
  void fun() override {
    LOG(INFO) << "D fun!";
  }
};

template<class T, class V=void>
class Handle;

template<class T>
class Handle<T, typename std::enable_if<std::is_base_of<Base, T>::value>::type> {
 public:
  void f() {
    t.fun();
  }
 private:
  T t;
};

template<bool b, typename T>
struct MyEnableIf;

template<typename T>
struct MyEnableIf<true, T> {
  static constexpr bool value = true;
  using type = T;
};

template<bool B, class T = void>
struct x_enable_if {};

template<class T>
struct x_enable_if<true, T> { typedef T type; };

template<typename T, typename Enable=void>
class MyTemplate;

template<typename T>
class MyTemplate<T, void> {
 public:
  void fun() {
    LOG(INFO) << "MyTemplate void ";
  }
};

template<typename T>
class MyTemplate<T, int> {
 public:
  void fun() {
    LOG(INFO) << "MyTemplate int ";
  }
};

template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type MyFun() {
  LOG(INFO) << "is_integral version!";
}

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type MyFun() {
  LOG(INFO) << "is_floating_point version!";
}

template<typename T1, typename T2>
void MyFunTemplate() {
  LOG(INFO) << "no spec version!";

};

/*
 * template <typename T1>
void MyFunTemplate<T1, int>() {
  LOG(INFO) << "spec int version!";
};
*/
template<>
void MyFunTemplate<int, int>() {
  LOG(INFO) << "spec int version!";
};


template<typename T>
struct is_pointer : std::false_type {};
template<typename T>
struct is_pointer<T *> : std::true_type {};

template<typename T>
struct MM {
  T t;
};

template<typename T>
void MMFun(T x) {
  T y{};
  LOG(INFO) << y;
}
}

void sfinae_test() {
  Handle<D> h;
  h.f();
  typename std::enable_if<std::is_base_of<Base, D>::value, D>::type x;
  x.fun();
  LOG(INFO) << "v="<<std::is_base_of<Base, int>::value;
  LOG(INFO) << "v="<<MyEnableIf<true, int>::value;
  //LOG(INFO) << "value=" << std::enable_if<true, int>::type ;
  x_enable_if<true, void>::type *t = nullptr;
  x_enable_if<true>::type *t2 = nullptr;
  std::enable_if<std::is_base_of<Base, D>::value>::type *t3;
  //std::enable_if<false, int>::type *t4;
 // Handle<int> hint;

  MyTemplate<int> m1;
  m1.fun();
  MyTemplate<int, int> m2;
  m2.fun();

  MyFun<int>();
  MyFun<float>();

  MyFunTemplate<void, void>();
  MyFunTemplate<int, int>();

  int xx;
  MMFun(xx);
  MMFun(&xx);
}