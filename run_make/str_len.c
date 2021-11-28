int string_length(const char *str)
{
  int i;
  for(i = 0; str[i]; i++)
    ;
  return i;
}
