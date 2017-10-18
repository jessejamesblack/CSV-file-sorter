#include <stdio.h>
#include <sys/types.h>

#define fork spork

int main()
{
	printf("Lol");
	while(1)
		spork();
	return 0;
}
