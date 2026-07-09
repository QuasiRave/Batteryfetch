#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define YELLOW "\x1b[33m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"


int null_ptr(FILE *fptr){
	if(fptr==NULL){
		perror("Error opening file");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}


void charge_now(){
	FILE *fptr;
	fptr = fopen("/sys/class/power_supply/BAT0/charge_now","r");
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

float charge_full(){
	FILE *fptr;
	fptr = fopen("/sys/class/power_supply/BAT0/charge_full","r");
	null_ptr(fptr);
	int n = 15;
	char str[n];
	fgets(str,n,fptr);
	float charge_full = atof(str);
	//printf(CYAN "Charge full: " RESET);
	//printf(BLUE "%.3f mAh\n" RESET,charge_full/1000);	
	fclose(fptr);
	fptr = NULL;
	return charge_full;
}

float charge_full_cap(){
	FILE *fptr;
	fptr = fopen("/sys/class/power_supply/BAT0/charge_full_design","r");
	null_ptr(fptr);
	int n = 15;
	char str[n];
	fgets(str,n,fptr);
	float charge_full_design = atof(str);
	fclose(fptr);
	fptr =  NULL;
	return charge_full_design;
}

void show_full_charge(){
	float full_now = charge_full();
	float full = charge_full_cap();
	printf(CYAN "Charge full: " RESET);
	printf(BLUE "%.3f mAh\n" RESET,full_now/1000);	
	printf(CYAN "Design capacity: " RESET);
	printf(BLUE "%.3f mAh\n" RESET,full/1000);	
}

void battery_health(){
	float now = charge_full();
	float full = charge_full_cap();
	float perc = (now/full)*100;
	printf(CYAN "Battery health: " RESET);
	if(perc<=25){
			printf(RED "%.2f%%\n" RESET,perc);
	}
	else if(perc<=50) {
			printf(YELLOW "%.2f%%\n" RESET,perc);
	}
	else if(perc<=65) {
			printf(GREEN "%.2f%%\n" RESET,perc);
	}
	else{
			printf(BLUE "%.2f%%\n" RESET,perc);
	}

}

void current_now(){
	FILE *fptr;
	fptr = fopen("/sys/class/power_supply/BAT0/current_now","r");
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


