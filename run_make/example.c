#include "str_len.h"
int sys_write(int fd, const void *buf, int size);
const char hello[] = "Hello, World!\n";
const char idk[] = "simple text\n";
int test()
{
  sys_write(1, hello, sizeof(hello)-1);
  sys_write(1, idk, sizeof(idk)-1);
  return 0;
}
