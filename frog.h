typedef struct Time_cycle
{
	int size;
	int capacity;
	int* arr;
}time;

typedef struct Grass
{
	int size;
	int capacity;
	int* arr;
}grass1;

typedef struct frog
{
	time t;
	grass1 g;
}fr;

void set_time_cycle(fr* f);
void reset_time(fr* f);
void clear_time(fr* f);
void set_grass(fr* f);
void reset_grass(fr* f);
void clear_grass(fr* f);
int sun(fr* f);
int sleep_night(fr* f);
void move(fr* f);
int tree(fr* f);
int grass(fr* f);

void eat(fr*);
void sleep(fr*);
void air(fr*);
void walk(fr*);
void clear(fr*);