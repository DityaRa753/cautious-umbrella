#include <stdio.h>

class Test {
  int g;
public:
  Test(int var1) { g = var1; }
  Test(int var) { g = var; }
  int operator+(int var) {
    return var - g; 
  }
};

int main()
{
  Test g(2);
  printf("%d\n", 10 - g);
  return 0;
}
