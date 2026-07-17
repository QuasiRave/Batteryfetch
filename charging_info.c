#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "colors.h"

void charging(char* battery){
	//Charging or discharging
	
	char* key = "status";
	int n = 9;
	char* str = fileread(battery,key,n);

	printf(CYAN "Status: " RESET);

	if(strcmp(str,"Charging")==0){
		printf(YELLOW "Charging\n" RESET);
	}
	else{
		printf(RED "Discharging\n" RESET);
	}

	free(str);
}

int ac_connected(){
	//If connected to AC (main)

	FILE *fptr;
	char path[256];

	fptr = fopen("/sys/class/power_supply/AC/online","r");
	null_ptr(fptr);

	int n = 2;
	char str[n];
	fgets(str,n,fptr);
	
	if(str[0]=='\0'){
		perror(RED "File is empty" RESET);
	}

	int status = atoi(str);

	fclose(fptr);
	fptr = NULL;
	return status;
}

void show_ac_connected(){
	//Show if plugged

	int status = ac_connected();

	printf(CYAN "AC: " RESET);

	if(status==0){
		printf(BLUE "Unplugged\n" RESET);
	}
	else{
		printf(YELLOW "Plugged\n" RESET);
	}
}

float capacity(char* battery){
	//Charge (percentage)
	
	char* key = "capacity";
	int n = 4;
	char* str = fileread(battery,key,n);
	float cap = atof(str);

	free(str);
	str = NULL;

	return cap;
}


void show_capacity(char* battery){
	//Show charge (percentage)

	float charge = capacity(battery);

	printf(CYAN "Capacity: " RESET);

	if(charge<=20){
			printf(RED "%.2f%%\n" RESET,charge);
	}
	else if(charge<=80) {
			printf(YELLOW "%.2f%%\n" RESET,charge);
	}
	else if(charge<100) {
			printf(GREEN "%.2f%%\n" RESET,charge);
	}
	else{
			printf(BLUE "%.2f%%\n" RESET,charge);
	}

}
