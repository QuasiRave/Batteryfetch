#include <stdio.h>
#include <stdlib.h>
#include "battery_info.h"
#include "utils.h"
#include "colors.h"

void cycle_count(char* battery){
	//Number of battery charge cycles (0 if not supported)
	
	char* key = "cycle_count";
	int n = 4;
	char* str = fileread(battery,key,n);
	int count = atoi(str);

	printf(CYAN "Charge cycles: " RESET);
	printf(BLUE "%d" RESET,count);

	if(count == 0){
		printf(" (or not supported)\n");
	}

	free(str);
	str = NULL;
}

float calculate_battery_health(char* battery){
	//Battery health: (present full charge capacity)/(default full charge capacity)

	float now = charge_full(battery);
	float full = charge_full_cap(battery);
	float perc = (now/full)*100;

	return perc;
}

void battery_health(char* battery){
	//Displaying battery health (percentage)

	float perc = calculate_battery_health(battery);

	printf(CYAN "Battery health: " RESET);

	if(perc<=25){
			printf(RED "%.2f%%" RESET,perc);
	}
	else if(perc<=50) {
			printf(YELLOW "%.2f%%" RESET,perc);
	}
	else if(perc<=65) {
			printf(BLUE "%.2f%%" RESET,perc);
	}
	else{
			printf(GREEN "%.2f%%" RESET,perc);
	}

	printf("\t");

}
void show_battery_health(char* battery){
	//Displaying battery health (graph)

	float perc = calculate_battery_health(battery);
	float val = perc/10;

	printf("[");

	for (int i=0;i<val-1;i++){
		if(perc<=30){
			printf(RED "#" RESET);
		}
		else if(perc<=50) {
			printf(YELLOW "#" RESET);
		}
		else if(perc<=60) {
			printf(BLUE "#" RESET);
		}
		else{
			printf(GREEN "#" RESET);
		}
	}
	for (int j=0;j<10-val;j++){
		if(perc<=30){
			printf(RED "*" RESET);
		}
		else{
			printf(CYAN "*" RESET);
		}
	}

	printf("]\n");

}
