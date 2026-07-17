#include <stdio.h>
#include <stdlib.h>
#include "colors.h"

int null_ptr(FILE *fptr){
	if(fptr==NULL){
		perror(RED "Error opening file" RESET);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}


char* fileread(char *battery,char* key,int n){
	FILE *fptr;
	char path[256];
	snprintf(path,sizeof(path),"/sys/class/power_supply/%s/%s",battery,key);

	fptr = fopen(path,"r");

	if(fptr==NULL){
		perror(RED "Error opening file" RESET);
		return NULL;
	}

	char *str = malloc(n);

	if(str==NULL){
		fclose(fptr);
		return NULL;
	}

	fgets(str,n,fptr);

	if(str[0]=='\0'){
		perror(RED "File is empty" RESET);
	}

	fclose(fptr);
	return str;

}
