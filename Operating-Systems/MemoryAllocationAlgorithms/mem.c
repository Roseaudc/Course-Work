#include <stdlib.h>   // for malloc() and free()
#include "mem.h"
#include <stdio.h>

/*
  Physical memory array. This is a static global array for all functions in this file.  
  An element in the array with a value of zero represents a free unit of memory.
*/
static unsigned int* memory;

/*
 The size (i.e. number of units) of the physical memory array. This is a static global 
 variable used by functions in this file.  

 */
static unsigned int mem_size;


/*
 The last_placement_position variable contains the end position of the last 
 allocated unit used by the next fit placement algorithm.  
 */
static unsigned int last_placement_position;

/*
Finds the first empty memory block in the memory array
*/

void allocate(int size, int duration, int startindex)
{
	int x;
	for (x = 0; x < size; x++)
	{
		memory[startindex + x] = duration;
	}
	
}

int firstFit(int size, int duration)
{
	int i = 0;
	int j = 0;
	int probes = 0;
	int done = 1;
	int tempSize = 0;
	while (i < mem_size && done != 0 )
	{
		if(memory[i] == 0)
		{
			j = i; // Start of fragSize
			while(memory[j] == 0)
			{
				tempSize++;
				j++;
			}
			if(tempSize >= size)
			{
				//allocate(size,duration,i);
				done = 0;
			}
			else
			{
				i = j;
				tempSize = 0;
				probes++;
			}
			
		}
		else
		{
			i++;
		}

		
	}
	if(done == 0)
	{
		allocate(size,duration,i);
	}
	else
	{
		probes = -1;
	}
	return probes;
		
		
		
}

int nextFit(int size, int duration)
{
	
	int i = last_placement_position;
	int j = 0;
	int probes = 0;
	int done = 1;
	int tempSize = 0;
	int end = 1;
	while (i < mem_size && done != 0 )
	{
		if(memory[i] == 0)
		{
			j = i; // Start of fragSize
			while(memory[j] == 0)
			{
				tempSize++;
				j++;
			}
			if(tempSize >= size)
			{
				last_placement_position = i;
				//allocate(size,duration,i);
				done = 0;
			}
			else
			{
				i = j;
				tempSize = 0;
				probes++;
				
				
			}
			
		}
		else
		{
			i++;

		}
		if(i >= mem_size && end != 0)
			{
				i = i % mem_size;
				end = 0;
			}

				

		
	}
	if(done == 0)
	{
		allocate(size,duration,i);
		//last_placement_position = i;
	}
	else
	{
		probes = -1;
	}
	return probes;
	
	
}

int bestFit(int size, int duration)
{
	int i = 0;
	int j = 0;
	int probes = 0;
	int done = 1;
	int tempSize = 0;
	int bestFitIndex = 0;
	int bestFitSize = 0;
	int first = 1;
	
	while(i < mem_size && done != 0)
	{
		if(memory[i] == 0)
		{
			j = i;
			while(memory[j] == 0)
			{
				tempSize++;
				j++;
			}
			if(tempSize == size)
			{
				done = 0;
			}
			else if(tempSize > size && tempSize < bestFitSize)
			{
				bestFitIndex = i;
				bestFitSize = tempSize;
				tempSize = 0;
				probes++;
				i = j;
				
			}
			else if(tempSize >= size && first != 0)
			{
				bestFitIndex = i;
				bestFitSize = tempSize;
				tempSize = 0;
				i = j;
				first = 0;
				return first;
			}
			else
			{
				i = j;
				probes++;
			}
		}
		else
		{
			i++;
		}
	}
	if (done == 0)
	{
		allocate(size,duration,i);
	}
	else if(first == 0)
	{
		allocate(size,duration,bestFitIndex);
	} 
	else
	{
		probes = -1;
	}
	return probes;

}

/*
  Using the memory placement algorithm, strategy, allocate size
  units of memory that will reside in memory for duration time units.

  If successful, this function returns the number of contiguous blocks
  (a block is a contiguous "chuck" of units) of free memory probed while 
  searching for a suitable block of memory according to the placement 
  strategy specified.  If unsuccessful, return -1.

  If a suitable contiguous block of memory is found, the units of this 
  block must be set to the value, duration.
 */
int mem_allocate(mem_strategy_t strategy, unsigned int size, unsigned int duration)
{
	int result;
	switch (strategy){
		case FIRST:
			result = firstFit(size, duration);
			break;
		case NEXT:
			result = nextFit(size, duration);
			break;
		case BEST:
			result = bestFit(size, duration);
			break;
		default:
			fprintf(stderr, "please use a strategy in set {FIRST, NEXT, BEST}\n");
			exit(1);
	}
	return result;
}

/*
  Go through all of memory and decrement all positive-valued entries.
  This simulates one unit of time having transpired.
 */
int mem_single_time_unit_transpired()
{
	for(int i = 0; i < mem_size; i++)
	{
		if(memory[i] > 0)
		{
			memory[i] = memory[i] - 1;

		}
	}
	return 0;
	
}

/*
  Return the number of fragments in memory.  A fragment is a
  contiguous free block of memory of size less than or equal to
  frag_size.
 */
int mem_fragment_count(int frag_size)
{
	int fragCount = 0;
	int i = 0;
	int tempSize = 0;
	while(i < mem_size)
	{
		if(memory[i] == 0)
		{
			while(memory[i] == 0)
			{
				tempSize++;
				i++;
			}
			if(tempSize <= frag_size)
			{
				fragCount++;
			}
			else
			{
				tempSize = 0;
			}
		}
		else
		{
			i++;
		}
	}
	return fragCount;
}

/*
  Set the value of zero to all entries of memory.
 */
void mem_clear()
{
	int i;
	for(i = 0; i < mem_size; i++)
	{
		memory[i] = 0;
	}
	last_placement_position = 0;
	
}

/*
 Allocate physical memory to size. This function should 
 only be called once near the beginning of your main function.
 */
void mem_init( unsigned int size )
{
	memory = malloc( sizeof(unsigned int)*size );
	mem_size = size;
	last_placement_position = 0;
	mem_clear();
}

/*
 Deallocate physical memory. This function should 
 only be called once near the end of your main function.
 */
void mem_free()
{
	free( memory );
}

/*
 Use to debug your program.
 */
void mem_print()
{
	
}

