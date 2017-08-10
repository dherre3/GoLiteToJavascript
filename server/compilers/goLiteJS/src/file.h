#ifndef FILE_H
#define FILE_H
#include "tree.h"
#include "string.h"
#include <stdio.h>
#include "stdlib.h"
#include "memory.h"
extern char *filename;
char *cleanFileName(char *path);
char* concat(const char *s1, const char *s2);
#endif /* !FILE_H */
