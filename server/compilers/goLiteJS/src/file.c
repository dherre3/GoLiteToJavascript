#include <libgen.h>
#include "file.h"

char *cleanFileName(char *filepath) {
  char *filename = basename(filepath);

  for (int i = strlen(filename) - 1; i >= 0; i--) {
    if (filename[i] == '.') {
      filename[i] = '\0';
      break;
    }
  }

  return filename;
}

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
