//
// Created by lizgao on 11/14/18.
//

#include <glog/logging.h>
#include <unordered_map>

namespace {
/*
template <class T>
struct MyAlloctor {
  typedef T value_type;
  MyAlloctor() = default;
  template <class U> constexpr MyAlloctor(const MyAlloctor<U>&) noexcept {}
  T* allocate(std::size_t n) {
    if(n > std::size_t(-1) / sizeof(T)) throw std::bad_alloc();
    if(auto p = static_cast<T*>(std::malloc(n*sizeof(T)))) {
      LOG(INFO) << "allocate";
      return p;
    }
    throw std::bad_alloc();
  }
  void deallocate(T* p, std::size_t) noexcept {
    LOG(INFO) << "deallocate";
    std::free(p);
  }
};
template <class T, class U>
bool operator==(const MyAlloctor<T>&, const MyAlloctor<U>&) { return true; }
template <class T, class U>
bool operator!=(const MyAlloctor<T>&, const MyAlloctor<U>&) { return false; }
*/
template <class T>
struct Mallocator {

 public:
  typedef size_t     size_type;
  //typedef ptrdiff_t  difference_type;
  typedef T*       pointer;
  typedef const T* const_pointer;
  typedef T&       reference;
  typedef const T& const_reference;
  typedef T        value_type;

  Mallocator() = default;
  template <class U> constexpr Mallocator(const Mallocator<U>&) noexcept {}
  T* allocate(std::size_t n) {
    if(n > std::size_t(-1) / sizeof(T)) throw std::bad_alloc();
    if(auto p = static_cast<T*>(std::malloc(n*sizeof(T)))) return p;
    throw std::bad_alloc();
  }
  void deallocate(T* p, std::size_t) noexcept { std::free(p); }
  template<typename _Tp1>
  struct rebind
  { typedef Mallocator<_Tp1> other; };

};
template <class T, class U>
bool operator==(const Mallocator<T>&, const Mallocator<U>&) { return true; }
template <class T, class U>
bool operator!=(const Mallocator<T>&, const Mallocator<U>&) { return false; }



}
namespace {
struct Data {
  int x;
  int y;
  int z;
};
}

void unordered_map_alloctor_test() {
 // std::unordered_map<int, int, std::hash<int>, std::equal_to<int>, Mallocator< std::pair<const int, int>> > my_map;
  std::unordered_map<int, Data*> data_map;
  data_map.reserve(100);
  Data data[10];
  for (int i = 0; i < 10; ++i) {
    data_map.insert({i, &data[i]});
  }

}