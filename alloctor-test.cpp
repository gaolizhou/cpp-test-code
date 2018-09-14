//
// Created by lizgao on 9/10/18.
//

#include <memory>
#include <iostream>
#include <string>
#include <glog/logging.h>

void alloctor_test()
{
    std::allocator<int> a1;   // default allocator for ints
    int* a = a1.allocate(1);  // space for one int
    a1.construct(a, 7);       // construct the int
    std::cout << a[0] << '\n';
    a1.deallocate(a, 1);      // deallocate space for one int

    // default allocator for strings
    std::allocator<std::string> a2;

    // same, but obtained by rebinding from the type of a1
    decltype(a1)::rebind<std::string>::other a2_1;

    // same, but obtained by rebinding from the type of a1 via allocator_traits
    std::allocator_traits<decltype(a1)>::rebind_alloc<std::string> a2_2;

    std::string* s = a2.allocate(2); // space for 2 strings

    a2.construct(s, "foo");
    a2.construct(s + 1, "bar");

    std::cout << s[0] << ' ' << s[1] << '\n';

    a2.destroy(s);
    a2.destroy(s + 1);
    a2.deallocate(s, 2);
}


void alloctor_test2()
{
  struct Data {
    Data(int x, int y) : x_(x), y_(y){
      LOG(INFO) << "ctor";
      fun();
    }
    ~Data() { LOG(INFO) << "dtor"; fun();}
    void fun() {LOG(INFO) << "x="<<x_<<",y="<<y_;}
    int x_;
    int y_;
  };

  std::allocator<Data> pool;
  auto data = pool.allocate(2);
  pool.construct(data, 1, 1);
  data[0].fun();
  pool.construct(data+1, 2, 2);
  data[1].fun();

  pool.destroy(data+1);
  pool.destroy(data);
  pool.deallocate(data, 2);


  Data *p = (Data*)(malloc(sizeof(Data)));
  new (p) Data(1,2);
  new (p) Data(1,2);
  p->fun();
  delete p;



}