#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "null.h"
#include "colors.h"

void charge_now(char* battery){
	//Present electric charge of battery (in milliampere hours)
	
	FILE *fptr;
	char path[256];

	snprintf(path,sizeof(path),"/sys/class/power_supply/%s/charge_now",battery);

	fptr = fopen(path,"r");
	null_ptr(fptr);

	int n = 15;
	char str[n];

	fgets(str,n,fptr);
	float charge = atof(str);

	printf(CYAN "Charge now: " RESET);
	printf(BLUE "%.3f mAh\n" RESET,charge/1000);

	fclose(fptr);
	fptr = NULL;
}

float charge_full(char* battery){
	//Present full charge of battery (in milliampere hours)

	FILE *fptr;
	char path[256];

	snprintf(path,sizeof(path),"/sys/class/power_supply/%s/charge_full",battery);

	fptr = fopen(path,"r");
	null_ptr(fptr);

	int n = 15;
	char str[n];
	fgets(str,n,fptr);
	float charge_full = atof(str);
	
	fclose(fptr);
	fptr = NULL;

	return charge_full;
}

float charge_full_cap(char* battery){
	//Full charge capacity of battery by design (in milliampere hours)

	FILE *fptr;
	char path[256];

	snprintf(path,sizeof(path),"/sys/class/power_supply/%s/charge_full_design",battery);

	fptr = fopen(path,"r");
	null_ptr(fptr);

	int n = 15;
	char str[n];
	fgets(str,n,fptr);
	float charge_full_design = atof(str);

	fclose(fptr);
	fptr =  NULL;

	return charge_full_design;
}

void show_full_charge(char* battery){
	//Show present full charge capacity and default full charge capacity

	float full_now = charge_full(battery);
	float full = charge_full_cap(battery);

	printf(CYAN "Charge full: " RESET);
	printf(BLUE "%.3f mAh\n" RESET,full_now/1000);	

	printf(CYAN "Design capacity: " RESET);
	printf(BLUE "%.3f mAh\n" RESET,full/1000);	
}



void current_now(char* battery){
	//Present electric current (in milliamphere)
	
	FILE *fptr;
	char path[256];
	
	snprintf(path,sizeof(path),"/sys/class/power_supply/%s/current_now",battery);

	fptr = fopen(path,"r");
	null_ptr(fptr);

	int n = 15;
	char str[n];
	fgets(str,n,fptr);
	float charge = atof(str);

	printf(CYAN "Current: " RESET);
	printf(BLUE "%.3f mA\n" RESET,charge/1000);

	fclose(fptr);
	fptr = NULL;
}


