#include <stdio.h>
#include <stdlib.h>
#include "charging_info.h"
#include "null.h"
#include "colors.h"


void show(float charge,int charging_status){
	//Showing battery percentage with an ASCII art

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
	//Check if AC connected

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

void battery_charge(char* battery){

	float charge = capacity(battery);

	int charging_status = status();
	show(charge,charging_status);

}


