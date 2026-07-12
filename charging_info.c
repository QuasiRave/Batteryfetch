#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "null.h"
#include "colors.h"

void charging(char* battery){
	//Charging or discharging

	FILE *fptr;
	char path[256];

	snprintf(path,sizeof(path),"/sys/class/power_supply/%s/status",battery);

	fptr = fopen(path,"r");
	null_ptr(fptr);

	int n = 9;
	char str[n];
	fgets(str,n,fptr);

	printf(CYAN "Status: " RESET);

	if(strcmp(str,"Charging")==0){
		printf(YELLOW "Charging\n" RESET);
	}
	else{
		printf(RED "Discharging\n" RESET);
	}

	fclose(fptr);
	fptr = NULL;
}

void ac_connected(){
	//If connected to AC (main)

	FILE *fptr;
	char path[256];

	fptr = fopen("/sys/class/power_supply/AC/online","r");
	null_ptr(fptr);

	int n = 2;
	char str[n];
	fgets(str,n,fptr);
	int charging = atoi(str);

	printf(CYAN "AC: " RESET);

	if(charging==0){
		printf(BLUE "Unplugged\n" RESET);
	}
	else{
		printf(YELLOW "Plugged\n" RESET);
	}

	fclose(fptr);
	fptr = NULL;
}

float capacity(char* battery){
	//Present charge (percentage)
	
	FILE *fptr;
	char path[256];
	
	snprintf(path,sizeof(path),"/sys/class/power_supply/%s/capacity",battery);

	fptr = fopen(path,"r");
	null_ptr(fptr);

	int n = 4;
	char str[n];
	fgets(str,n,fptr);
	float charge = atof(str);

	fclose(fptr);
	fptr = NULL;

	return charge;
}


void show_capacity(char* battery){

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
