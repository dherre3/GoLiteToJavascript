#include <string.h>
#include <stdio.h>
#include "string.h"
#include "stdlib.h"

int main(int argc, char **argv)
{
	char *da;
	int offset = sprintf(da,"%s","david");
	da+=offset;
	sprintf(da,"%s","herrera");
	printf("%s",da);	
	return 0;
}
