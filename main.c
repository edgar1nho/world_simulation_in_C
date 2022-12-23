#include <stdio.h>
#include "frog.h"

void call_everything()
{
	fr f;
	set_time_cycle(&f);
	set_grass(&f);
	walk(&f);
	eat(&f);
	air(&f);
	walk(&f);
	eat(&f);
	air(&f);
	walk(&f);
	air(&f);
	sleep(&f);
	clear_time(&f);
	clear_grass(&f);
	printf("\n");
	char s;
	printf("if you want to see the world simulation again enter 'y' otherwise 'n'\n");
	scanf_s(" %c", &s);
	if (s == 'y')
	{
		call_everything();
	}
	else
	{
		printf("goodbye\n");
	}
}

int main()
{
	call_everything();
}