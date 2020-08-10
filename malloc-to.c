#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
	const int MAXALLOCMEGS = 64 << 10; /* Max memory to allocate: 64 GiB */
	const int alloc_size = 1 << 20;    /* Size to allocate in each iteration: 1 MiB */
	int alloc_megs = 0;		   /* Receive the command line argument */
	int allocated = 0;                 /* Allocated counter, in MiBs */
	int i=0;
	char *mem;

	if(argc != 2){
		printf("**ERROR**\nUsage: %s <memory to allocate in MiB>\nExample: %s 123\n", argv[0], argv[0]);
		return 9;
	}
	alloc_megs = atoi(argv[1]); 
	if(alloc_megs > MAXALLOCMEGS){
		printf("**WARNING: This program was designed to never try to allocate more than %d MiB (%d GiB) of RAM.\n", MAXALLOCMEGS, MAXALLOCMEGS >> 10);
		printf("**WARNING: Requested more than the maximum allocation limit (%d Mebibytes). Using %d instead of %s.\n", MAXALLOCMEGS, MAXALLOCMEGS, argv[1]);
		alloc_megs = MAXALLOCMEGS;
	}
	for(allocated=1; allocated <= alloc_megs; allocated++){
		//printf("Allocating %d bytes but not using them yet.", alloc_size);
		mem = malloc(alloc_size); /* Allocate 1 MiB */
		//printf("Allocated %d bytes.", alloc_size);
		for(i=0; i<alloc_size; i++){
			//printf("DEBUG: allocating at i=%d\n", i);
			mem[i] = 'Z';
		}
		printf("\r>  Total allocated size: %6d MiB.", allocated);
	}
	printf("\nHit ENTER to quit. ");
	getchar();
	return 0;
}
