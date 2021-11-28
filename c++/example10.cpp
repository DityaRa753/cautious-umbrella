#include <stdio.h>

int main()
{
  char var = '0';
  const char *p1 = 0;
  char* const p2 = 0;

  p1 = &var;
  printf("%d %d\n", *p1, p1);
  p1 = p2;
  printf("p1:%d ; p2:%d\n", p1, p2);
  p1 = &var;
  //p2 = p1;
  printf("p1:%d ; p2:%d\n%d\n", p1, p2, *p2);
}
