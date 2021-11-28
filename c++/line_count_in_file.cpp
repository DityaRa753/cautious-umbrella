#include <stdio.h>
#include <stdlib.h>

unsigned int line_count_in_file(const char *file_name)
{
  FILE *f = fopen(file_name, "r");
    if(!f)
      throw "couldn't open the file..."; // const *char
    //if(!f)
      //throw 27; //... int
  int n = 0;
  int c = 0;
  while((c = fgetc(f)) != EOF)
    if(c == '\n')
      n++;
  fclose(f);
  return n;
}

int main(int argc, char** argv)
{
  try {
    int g = line_count_in_file(argv[1]);
    printf("The file %s contains %d lines\n", argv[1], g);
  } catch(char const *exception) {
    fprintf(stderr, "Exception (string): %s\n", exception);
    return 2;
  }
  return 0;
}
