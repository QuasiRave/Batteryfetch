#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "colors.h"

void charge_now(char* battery){
	//Present electric charge of battery (in milliampere hours)
		
	char* key = "charge_now";
	int n = 15;
	char* str = fileread(battery,key,n);
	float charge = atof(str);

	printf(CYAN "Charge now: " RESET);
	printf(BLUE "%.3f mAh\n" RESET,charge/1000);

	free(str);
	str = NULL;
}

float charge_full(char* battery){
	//Present full charge of battery (in milliampere hours)
	
	char* key = "charge_full";
	int n = 15;
	char* str = fileread(battery,key,n);
	float charge_full = atof(str);
	
	free(str);
	str = NULL;

	return charge_full;
}

float charge_full_cap(char* battery){
	//Full charge capacity of battery by design (in milliampere hours)
	
	char* key = "charge_full_design";
	int n = 15;
	char* str = fileread(battery,key,n);
	float charge_full_design = atof(str);

	free(str);
	str =  NULL;

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
	
	char* key = "current_now";
	int n = 15;
	char* str = fileread(battery,key,n);
	float current = atof(str);

	printf(CYAN "Current: " RESET);
	printf(BLUE "%.3f mA\n" RESET,current/1000);

	free(str);
	str = NULL;
}


