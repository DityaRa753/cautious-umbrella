#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int num;
  struct list *next;
} item;

int str_to_int(const char *str)
{
  int num = 0;
  while(*str) {
    num = num * 10 + *str - '0';
    str++;
  }
  return num;
}

item *create_item(int len)
{
  item *tmp, *next = NULL;
  for(int i = 0; i < len; i++) {
    tmp = malloc(sizeof *tmp);
    tmp->num = i;
    tmp->next = next;
    next = tmp;
  }
  return tmp;
}

int main(int argc, char **argv)
{
  if(argc < 1) {
    printf("Too few arguments!\n");
    return 1;
  }
  int num = str_to_int(argv[1]);
  item *first = create_item(num);
  item *temp = first;
  while(temp) {
    printf("%d ", temp->num);
    temp = temp->next;
  }
  printf("\n");
  return 0;
}
