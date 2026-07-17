#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "battery.h"
#include "battery_info.h"
#include "charging_info.h"
#include "bat_ls.h"
#include "health_info.h"
#include "colors.h"

#define VERSION "batteryfetch 1.0.2"

#define UNDERLINE "\033[4m"
#define ITALIC "\033[3m"
#define FONT_RESET "\033[0m"

void show_info(){
	// Displaying details of each batteries
	char **bat = list_batteries();
	
	if(bat[0]==NULL){
		puts("Battery not found!");
	}

	for(int i=0;bat[i]!=NULL;i++){
		printf(CYAN "Battery: " RESET);
		printf("%s\n\n",bat[i]);
		battery_charge(bat[i]);
		show_capacity(bat[i]);
		show_ac_connected();
		charging(bat[i]);
		current_now(bat[i]);
		charge_now(bat[i]);
		show_full_charge(bat[i]);
		battery_health(bat[i]);
		show_battery_health(bat[i]);
		cycle_count(bat[i]);
		printf("\n");
	}
 
	for(int i=0;bat[i]!=NULL;i++){
		free(bat[i]);
	}

	free(bat);
}

void help(){
	//help

	printf("Batteryfetch is a simple Linux command-line tool for fetching battery-related information and displaying them in a pretty way\n\n");

	printf(UNDERLINE "Usage\t" FONT_RESET);
	printf("batteryfetch");
	printf(ITALIC " <?options>\n\n" FONT_RESET);

	printf(UNDERLINE "Options\n" FONT_RESET);

	printf("-%c\t\tShow this help\n",'h');
	printf("-%c\t\tShow version\n",'v');
	printf("-%c\t\tShow all\n\n",'a');

	printf("For more, please visit:\n\t<https://github.com/QuasiRave/Batteryfetch>\n");
}

void version(){
	//version

	printf("%s\n",VERSION);
}

int main(int argc,char **argv){

	int opt;

	if(argc==1){
		show_info();
	}

	while((opt=getopt(argc,argv,"if:hva"))!=-1){
		switch (opt){
			case 'h':
				help();
				break;
			case 'v':
				version();
				break;
			case 'a':
				show_info();
				break;
			case '?':
				printf("Unknown option: %c\n",optopt);
				puts("Try 'batteryfetch -h' for more information");
				break;
		}
		if(argc>1){
			break;
		}
	}
}
