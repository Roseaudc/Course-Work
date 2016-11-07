#include "dpsim.h"
#include <signal.h>

static const unsigned int NUM_PHILOSOPHERS = 5;
static const unsigned int NUM_CHOPSTICKS = 5;
static int chopsticks[5];
static pthread_mutex_t mutex[5];
static pthread_t philosphers[5];
int newchopsticks[5];
int infinite = 1;
int temp[5];

void* th_main( void* th_main_args ) {

	// ---------------------------------------
	// TODO: you add your implementation here
	
	//Initialize each chopstick to -1
	for(int i = 0; i < NUM_CHOPSTICKS; i++)
	{
		chopsticks[i] = -1;
		
	}

	//Create thread for each philosopher
	for(int j = 0; j < NUM_PHILOSOPHERS; j++)
	{
		//delay(10000);
		temp[j] = j;
		if(pthread_create(&philosphers[j],NULL,th_phil,(void *)&temp[j]))
		{
			exit(1);
		}	
	}
	while(infinite == 1)
	{
		memcpy(newchopsticks,chopsticks,sizeof(chopsticks));
		if(newchopsticks[0] == 0 && newchopsticks[1] == 1 && newchopsticks[2] == 2 && newchopsticks[3] == 3 && newchopsticks[4] == 4)
		{
			printf("Deadlock condition (0,1,2,3,4) ... terminating\n");
			infinite = 0;
		}
		else
		{
			printf("Philosopher(s) ");
			delay(10000);
			for(int i = 0; i < NUM_CHOPSTICKS; i++)
			{
				if(newchopsticks[i] == newchopsticks[(i + 1) % 5] && newchopsticks[i] != -1)
				{
					printf("%d, ",i);
				}	
			}
			printf("are eating...\n");
		}
		
	}
	
	//Kill Threads
	for(int i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		pthread_kill(philosphers[i],0);
	}
	pthread_exit(0);
	

} // end th_main function


void* th_phil( void* th_phil_args ) {

	// ---------------------------------------
	// TODO: you add your implementation here
	int id = *(int *)th_phil_args;
	while(infinite == 1)
	{
		delay(10000);
		eat(id);
	}

	return 0;
} 
// end th_phil function


void delay( long nanosec ) {

	struct timespec t_spec;

	t_spec.tv_sec = 0;
	t_spec.tv_nsec = nanosec;

	nanosleep( &t_spec, NULL );

} // end think function


void eat( int phil_id ) {

	// ----------------------------------------
	// TODO: you add your implementation here
	pthread_mutex_lock(&mutex[phil_id]);
	chopsticks[phil_id] = phil_id;
	pthread_mutex_lock(&mutex[(phil_id + 1) % 5]);
	chopsticks[(phil_id + 1) % 5] = phil_id;
	delay(10000);
	pthread_mutex_unlock(&mutex[(phil_id + 1) % 5]);
	chopsticks[(phil_id + 1) % 5] = -1;
	pthread_mutex_unlock(&mutex[phil_id]);
	chopsticks[phil_id] = -1;
	delay(10000);
	
	//Grab left chopstick
	/*if(phil_id == 4) {
		pthread_mutex_lock(&mutex[0]);
		chopsticks[0] = phil_id;
	}
	else{
		pthread_mutex_lock(&mutex[phil_id + 1]);
		chopsticks[phil_id + 1] = phil_id;
	}

	delay(10000);

	//Put chopsticks back
	if(phil_id == 4)
		pthread_mutex_unlock(&mutex[0]);
	else
		pthread_mutex_unlock(&mutex[phil_id + 1]);

	pthread_mutex_unlock(&mutex[phil_id]);*/
	

} // end eat function
