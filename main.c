#include "battery.h"
#include "battery_info.h"
#include "charging_info.h"

int main(){
	battery_charge();
	capacity();
 	charging();
	ac_connected();
	cycle_count();
	charge_now();
	show_full_charge();
	battery_health();
	current_now();
}
