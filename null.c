#include <stdio.h>
#include <stdlib.h>

int null_ptr(FILE *fptr){
	if(fptr==NULL){
		perror("Error opening file");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;


}


