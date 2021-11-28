#include<stdio.h>

int main() 
{

struct myflags {
  unsigned char io_error:1;
  unsigned char seen_a_digit:1;
  char had_a_eol:1;
  unsigned char check:1;
  char check2:5;
} ss;
ss.check = 2;
printf("%d\n", ss.check);

}
