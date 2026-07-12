#include <stddef.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include "null.h"

int filetype(char type){
	//Determining file type

	if(type==DT_REG){
		return 0;
	}
	else if(type==DT_DIR){
		return 1;
	}
	else{
		return -1;
	}
}


char** list_batteries(){
	//Finding batteries

	char **batteries = (char**)malloc(100*sizeof(char*));
	int battery_count = 0;

	char *dirname = "/sys/class/power_supply";
	DIR *dirptr = opendir(dirname);
	struct dirent *dir;

	if(dirptr==NULL){
		perror("Couldn't access the file!");
		batteries[0] = NULL;
		return batteries;
	}

	while((dir = readdir(dirptr))!=NULL){

		if (strcmp(dir->d_name,".")==0 || strcmp(dir->d_name,"..")==0){
			continue;
		}

		char subdirname[256];
		snprintf(subdirname,sizeof(subdirname),"%s/%s/type",dirname,dir->d_name);
		
		char str[8];
		
		FILE *fptr;
		fptr = fopen(subdirname,"r");
		null_ptr(fptr);

		if(fgets(str,sizeof(str),fptr)!=NULL && (strcmp(str,"Battery")==0)){
			batteries[battery_count] = strdup(dir->d_name);
			battery_count++;
		}
		fclose(fptr);
		fptr = NULL;
	}

	closedir(dirptr);
	dirptr = NULL;

	batteries[battery_count] = NULL;

	return batteries;

}

