#include <stdio.h>
#include <stdlib.h>
#include "battery.h"
#include "battery_info.h"
#include "charging_info.h"
#include "bat_ls.h"
#include "health_info.h"

void bat_list(){
	// Displaying details of each batteries
	char **bat = list_batteries();
	
	if(bat[0]==NULL){
		puts("Battery not found!");
	}

	for(int i=0;bat[i]!=NULL;i++){
		printf("--- %s ---\n\n",bat[i]);
		battery_charge(bat[i]);
		show_capacity(bat[i]);
		ac_connected();
		charging(bat[i]);
		current_now(bat[i]);
		charge_now(bat[i]);
		show_full_charge(bat[i]);
		battery_health(bat[i]);
		show_battery_health(bat[i]);
		cycle_count(bat[i]);
	}
 
	for(int i=0;bat[i]!=NULL;i++){
		free(bat[i]);
	}

	free(bat);
}

int main(){
	bat_list();
}
