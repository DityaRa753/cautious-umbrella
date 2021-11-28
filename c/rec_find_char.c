#include <stdio.h>
char find_char(char str[], char chr) 
{
  printf("%d %c: chr %c\n", str, *str, chr);
  if (*str == chr) {
    return 'Y'; 
  }
  else if(*str == '\0') {
    return 'N';
  }
  else {
    find_char(++str, chr);
  }
}

int main (int argc, char* argv[])
{
  printf("%c\n", find_char(argv[1], *argv[2]));
  return 0;
}
