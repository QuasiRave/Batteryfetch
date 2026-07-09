#include <stdio.h>
#include <stdlib.h>
#include "null.h"
 
#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"



void show(float charge,int charging_status){
	int conv = charge/10;
	int num = 10;
	printf("  ");
	for (int i=0;i<num-4;i++){
		printf("*");
	}
	printf("\n");
	for (int i=0;i<10-conv;i++){
		for (int j=0;j<num;j++) {
			if(charge>=20){
				printf(BLUE "*" RESET);
			}
			else{
				printf(RED "*" RESET);
			}
		}
		printf("\n");
	}
		
	for (int i=0;i<conv;i++){
		for (int j=0;j<num;j++) {
			if (charging_status==0){
				if (charge<=20){
					printf(RED "#" RESET);
				}
				else{
					printf(GREEN "#" RESET);
				}
			}
			else{
				printf(YELLOW "#" RESET);
			}
		}
		printf("\n");
	}




	printf("\n");
}

int status(){
	FILE *fptr;
	fptr = fopen("/sys/class/power_supply/AC/online","r");
	int n = 2;
	char str[n];
	fgets(str,n,fptr);
	int charging = atoi(str);
	fclose(fptr);
	fptr = NULL;
	return charging;
}

void battery_charge(){
	FILE *fptr;
	fptr = fopen("/sys/class/power_supply/BAT0/capacity","r");
	null_ptr(fptr);
	int n = 4;
	char str[n];
	fgets(str,n,fptr);
	float charge = atof(str);
	int charging_status = status();
	show(charge,charging_status);
	fclose(fptr);
	fptr = NULL;

}


