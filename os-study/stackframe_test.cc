//
// Created by lizgao on 3/3/19.
//

namespace{
int functionA(int a) {
  int num[20] = {0};
    return ++a;
  }

int functionB(int b) {
  int num[200] = {0};
  return functionA(++b);

}

int functionC(int c) {
  int num[2000] = {0};
  return functionB(++c);

}


}

void stackframe_test() {
  functionC(0);
}

