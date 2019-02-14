//
// Created by lizgao on 1/29/19.
//

class Buddy {
 public:
  Buddy() {

  }
  ~Buddy() {

  }
 public:
  void *Alloc(int len);
  void Free(void *ptr);
 private:

 private:
  void *memory_;
  int size_;
  int page_size_;
};