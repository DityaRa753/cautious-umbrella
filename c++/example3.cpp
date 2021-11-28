#include <stdio.h>

class A {
  public:
    void operator++() { printf("first\n"); }
    void operator--() { printf("second\n"); }
    void operator++(int) { printf("third\n"); }
    void operator--(int) { printf("fourth\n"); }
};

class MyInt {
  int i;
public:
  MyInt(int x) : i(x) {}
  const MyInt& operator++() { i++; return *this; }
  MyInt operator++(int)
  { MyInt tmp(*this); i++; return tmp; }
};

int main()
{
  /*A test;
  ++test; // first
  test++; // third
  --test; // second
  test--; // fourth
  */
  MyInt i(10);
  printf("%d\n", i);
  ++i;
  printf("%d\n", i);
  return 0;
}
