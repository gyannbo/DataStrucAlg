#include <stdio.h>

int main()
{
	char s[100];
	sprintf(s, "%d", 4560 % 111);
	printf("%s\n", s);
	return 0;
}
