
#include <stdio.h>	// IO functions
#include <stdlib.h> 	// std lib function
#include <unistd.h>	// close function
#include <pthread.h>	// creating, running, joining threads
#include <string.h>	// string processing 
#include "web.h"	// our code :)



/*

HW3: CSCI 340 Operating Systems

Developing a client that creates a thread for each
URL specified in the url.txt file. In each thread: 
1) a TCP/IP socket will be established, 2) read all
the characters in the webpage, and 3) count the number 
of anchor tags.

After all threads have been joined, the number of anchor 
tags will be written to a file named "url_a_num.txt".

*/

// ---------------------------------------------
// Global variable shared by all threads
// This is not thread safe.
web_t* web_array;


// ---------------------------------------------
// Function prototypes to read and write url files
int read_url_file( char* file_path, web_t* web_array );
int write_url_file( char* file_path, web_t* web_array, int num_urls );

void th_run( int* i );

int main( int argc, char *argv[] ) {

	int i = 0;

	// malloc web_t array with 100 elements
	web_array = malloc( sizeof( web_t )*100 );
	pthread_t thread[100];

	// -------------------------------------------------
	// Verify the correct number of arguments are provided
	// when the application is executed.

	if ( argc == 2 ) { 

		int num_urls = read_url_file( argv[1], web_array );

		if ( DEBUG )  { 

			printf("Number of urls in text file = %d\n", num_urls);

			for ( i=0; i<num_urls; i++ ) {

				printf("URL=%s\n", web_array[i].url ); 
				printf("CNT=%d\n", web_array[i].anchor_cnt );
				printf("FD=%d\n", web_array[i].socket_fd );

			}
		}

		int temp_arg[num_urls];
		for(int j=0; j < num_urls; j++)
		{
			temp_arg[j] = j;
			if(pthread_create(&thread[j],NULL,(void *)th_run,(void *)&temp_arg[j])!=0)
			{
				perror("ERROR!"),exit(1);
			}
		
		}

		for(int j = 0; j < num_urls; j++)
		{
			if(pthread_join(thread[j],NULL) != 0)
			{
				printf("ERROR!");
			}
			else
			{
				write_url_file(argv[1], web_array, num_urls);
			}
			
		}
		// -----------------------------------------
		// TODO:
		// 
		// You write the code to:
		//	1) Create a new thread for each web_t structure and run it
		//	2) The joining of each newly created thread. 
		//
		// If either the thread create or join fails, you may exit the entire
		// program.
		// 
		// Hint: you will loop through an array of threads

		

	} else {
		printf( "URL file is not specified!\n" );
		printf( "Example usage: %s %s\n", argv[0], "url.txt" );
	}

	return OK;
     
} // end main function


void th_run( int* i ) {

	// -------------------------------------
	// Please do not modify this code
	// -------------------------------------

	if ( open_sock( &web_array[ (*i) ] ) == OK ) {

		parse( &web_array[ (*i) ] );
		close_sock( &web_array[ (*i) ] );

	} else printf( "[%s] network connection failed\n", web_array[ (*i) ].url );

	pthread_exit( NULL );

} // end th_run function


int write_url_file( char* file_path, web_t* web_array, int num_urls ) {

	// -----------------------------------------
	// TODO:
	// 
	// Fully implement this function to create
	// url_a_num.txt file. The format of this 
	// file is shown below. 
	// 
	// <url>, <total_num_anchor_tags>\n
	//
	//
	// For example,
	//
	//	google.com, 25
	//	msn.com, 55
	//
	// The function will return an error code:
	//	OK - no errors creating or writing file
	//	FAIL - failed to creat or write file
	
	FILE* fp;
	fp = fopen("url_a_num.txt","a");
		for(int i = 0; i < num_urls; i++)
		{
			fprintf(fp,"%s, %d\n",web_array[i].url + 4,web_array[i].anchor_cnt);
		}
	fclose(fp);
	return OK;

} // end write_url_file function




int read_url_file( char* file_path, web_t* web_array ) {

	// -------------------------------------
	// Please do not modify this code
	// -------------------------------------

	int url_cnt = 0;

	FILE* fhnd;

	fhnd = fopen( file_path, "r" );

	char line[50];

	if ( fhnd != NULL ) {

    	while ( fgets( line, sizeof( line ), fhnd ) != NULL ) {
			line[strlen(line)-1] = '\0';
			web_array[url_cnt].url = malloc(sizeof(char)*100);
			sprintf( web_array[url_cnt].url, "www.%s", line );
			web_array[url_cnt].anchor_cnt = 0;
			web_array[url_cnt++].socket_fd = -1;
    	}

	} else url_cnt = FAIL;

	fclose( fhnd );

	return url_cnt;

} // end read_url_file function
