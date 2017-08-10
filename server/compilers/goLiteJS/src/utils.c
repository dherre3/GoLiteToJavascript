#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

char *strf(const char *formatted_str, ...) {
  va_list args1;
  va_list args2;

  va_start(args1, formatted_str);
  va_start(args2, formatted_str);

  int len = vsnprintf(NULL, 0, formatted_str, args1) + 1;

  char *str = (char *)malloc(len * sizeof(char));
  vsnprintf(str, len, formatted_str, args2);

  va_end(args1);
  va_end(args2);

  return str;
}
