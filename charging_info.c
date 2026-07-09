#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "null.h"

#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define YELLOW "\x1b[33m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"


void charging(){
	FILE *fptr;
	fptr = fopen("/sys/class/power_supply/BAT0/status","r");
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
	FILE *fptr;
	fptr = fopen("/sys/class/power_supply/AC/online","r");
	null_ptr(fptr);
	int n = 2;
	char str[n];
	fgets(str,n,fptr);
	int charging = atoi(str);
	printf(CYAN "AC: " RESET);
	if(charging==0){
		printf(GREEN "Unplugged\n" RESET);
	}
	else{
		printf(YELLOW "Plugged\n" RESET);
	}
	fclose(fptr);
	fptr = NULL;
}

void capacity(){
	FILE *fptr;
	fptr = fopen("/sys/class/power_supply/BAT0/capacity","r");
	null_ptr(fptr);
	int n = 4;
	char str[n];
	fgets(str,n,fptr);
	float charge = atof(str);
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
	
	fclose(fptr);
	fptr = NULL;
}

void cycle_count(){
	FILE *fptr;
	fptr = fopen("/sys/class/power_supply/BAT0/cycle_count","r");
	null_ptr(fptr);
	int n = 4;
	char str[n];
	fgets(str,n,fptr);
	int count = atoi(str);
	printf(CYAN "Charge cycles: " RESET);
	printf(BLUE "%d\n" RESET,count);
	fclose(fptr);
	fptr = NULL;
}


