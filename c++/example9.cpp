#include <stdio.h>

struct person {
  char name[64];
  char sex;
  int year_of_birth;
};

struct student : person {
  int code;
  int year;
  float average;
};

int main()
{
  student s1;
  strcpy(s1.name, "John Doe");
  s1.sex = 'm';
  s1.year_or_birth = 1989;
  s1.code = 51311;
  s1.year = 2;
  s1.average = 4.75;
  
  return 0;
}
