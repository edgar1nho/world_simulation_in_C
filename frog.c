#include <stdio.h>
#include <stdlib.h>
#include "frog.h"

void eat(fr* f)
{
	if (grass(f) == 1)
	{
		printf("frog has eaten some grass\n");
	}
}

void sleep(fr* f)
{
	if (sleep_night(f) == 1)
	{
		printf("frog is sleeeping\n");
	}
}

void air(fr* f)
{
	if (tree(f) == 1)
	{
		printf("frog breathes air\n");
	}
}

void walk(fr* f)
{
	move(f);
}


void set_time_cycle(fr* f)
{
	f->t.size = 0;
	f->t.capacity = 24;
	int* tmp;
	tmp = (int*)malloc(f->t.capacity * sizeof(int));
	for (int i = 0; i < f->t.capacity; ++i)
	{
		tmp[i] = i;
	}
	f->t.arr = tmp;
	tmp = NULL;
}

void reset_time(fr* f)
{
	f->t.size = 0;
}

void clear_time(fr* f)
{
	free(f->t.arr);
	f->t.arr = NULL;
}


void set_grass(fr* f)
{
	f->g.size = 0;
	f->g.capacity = 10;
	int* tmp;
	tmp = (int*)malloc(f->g.capacity * sizeof(int));
	for (int i = 0; i < f->g.capacity; ++i)
	{
		tmp[i] = 1;
	}
	f->g.arr = tmp;
	tmp = NULL;
}

void reset_grass(fr* f)
{
	f->g.size = 0;
}

void clear_grass(fr* f)
{
	free(f->g.arr);
	f->g.arr = NULL;
}

int sun(fr* f)
{
	if (f->t.size >= f->t.capacity)
	{
		reset_time(f);
	}
	if (f->t.size < 16)
	{
		printf("its %d", f->t.size);
		printf(" am\n");
		printf("sun is shining now\n");
		return 1;
	}
	else
	{
		printf("its %d", f->t.size);
		printf(" am\n");
		printf("its night time\n");
		return 0;
	}
}

int sleep_night(fr* f)
{
	if (f->t.size > f->t.capacity)
	{
		reset_time(f);
	}
	if (sun(f) == 0)
	{
		f->t.size += 8;
		return 1;
	}
	else
	{
		printf("its not time for sleeping\n");
		return 0;
	}
}

void move(fr* f)
{
	if (sun(f) == 1)
	{
		printf("frog is walking\n");
	}
	f->t.size += 2;
}

int tree(fr* f)
{
	if (f->t.size >= f->t.capacity)
	{
		reset_time(f);
	}
	if (sun(f) == 1)
	{
		printf("tree produces air\n");
		f->t.size += 2;
		return 1;
	}
	else
	{
		printf("tree does not produce air\n");
		return 0;
	}
}

int grass(fr* f)
{
	if (f->g.size >= f->g.capacity)
	{
		reset_grass(f);
	}
	printf("frog eating grass\n");
	f->g.size += 5;
	f->t.size += 2;
	return 1;
}
