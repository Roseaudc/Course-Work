#include "mem.h"
#include "stdio.h"
#include "stdlib.h"

/* minimum and maximum duration of use for an allocated block of memory */
#define MIN_DURATION      3
#define MAX_DURATION     25

/* minimum and maximum allocation request size */
#define MIN_REQUEST_SIZE    3
#define MAX_REQUEST_SIZE  100

/*
  The main program will accept four paramemters on the command line.
  The first parameter is the memory size.  The second parameter is the
  number of times to repeat each experiment (ie. number of runs).  The
  third parameter is the duration of the each simulation run. The
  forth parameter is a random number seed. Here is an example command
  line:

  ./hw7 10000 100 2000 1234

  This means that your program should initialize physical memory to
  10,000 units, perform 100 runs with each run taking 2000 units of
  time, and the random number generator should be seeded (one time)
  with the value 1234.
*/

int main(int argc, char** argv)
{
	enum mem_strategies strategy;
	char *strat;
	int memSize;
	int runs;
	int dur_of_sim;
	int seed;
	int i;
	int j;
	int algo_method;
	int frags;
	int probes;	
	int misses;
	int dur;
	int siz;
	int range_of_size = MAX_REQUEST_SIZE - MIN_REQUEST_SIZE;
	int range_of_duration = MAX_DURATION - MIN_DURATION;
	int result;
	if(argc != 5)
	{
		printf("I NEED 5 ARGUMENTS!!!");
		exit(1);
	}
	memSize = atoi(argv[1]);
	runs = atoi(argv[2]);
	dur_of_sim = atoi(argv[3]);
	seed = atoi(argv[4]);
	mem_init(memSize);
	srand(seed);
	for(algo_method = 0; algo_method <= 2; algo_method++)
	{
		frags = 0;
		misses = 0;
		probes  = 0;
		mem_clear();
		switch (algo_method)
		{
			case 0:
				strategy = FIRST;
				strat = "FIRST\0";
				break;
			case 1:
				strategy = NEXT;
				strat = "NEXT\0";
				break;
			case 2:
				strategy = BEST;
				strat = "BEST\0";
				break;
			default:
				fprintf(stderr,"Enumerator not working!\n");
				exit(1);
		}
		for(i = 0; i < runs; i++)
		{
			for(j = 0; j < dur_of_sim; j++)
			{
				dur = (rand() % (range_of_duration + 1)) + MIN_DURATION;
   				siz = (rand() % (range_of_size + 1)) + MIN_REQUEST_SIZE;
				result = mem_allocate(strategy, siz, dur);
				if(result == -1)
				{
					misses += 1;
				}
				else
				{
					probes += result;
				}
				mem_single_time_unit_transpired();	
			}
			frags += mem_fragment_count(3);
		}
		printf("%s:\tavg fragmentation: %.3f\tavg failures: %.3f\tavg probes: %.5f\n", strat, ((double) frags) / ((double) runs), ((double) misses)/((double) runs), ((double) probes)/((double) runs));	
	}
	mem_free();
  return 0;
}
