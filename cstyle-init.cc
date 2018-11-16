//
// Created by lizgao on 11/9/18.
//

namespace {
typedef struct FOO
{
  int a;
  int b;
  int c;
} FOO;

FOO foo   = {.a = 1, .b = 2}; // OK
FOO foo1  = {.a = 1};         // OK
extern "C" {
//FOO foo2 = {.b = 2, .a = 1}; // Error sorry, unimplemented: non-trivial designated initializers not supported
//FOO foo3 = {.a = 1, .c = 2}; // Error sorry, unimplemented: non-trivial designated initializers not supported
}
}

void cstyle_init() {

}
