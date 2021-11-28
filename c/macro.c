#include<stdio.h>
#define square(x) x * x
#define MAX(A, B) ((A) > (B) ? (A) : (B))

int f(int x) {return x * 2;}

int g(int x) {return x + 1;}

int main() 
{

  printf("%d\n", MAX(f(2), g(2)));
  return 0;
}
