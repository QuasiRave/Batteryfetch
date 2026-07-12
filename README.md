# Batteryfetch
A simple command-line battery information tool written in C for Linux.

## Features
- Shows battery percentage, charging status, battery capacity and other related information
- Shows a coloured output interface
- Display a simple ASCII battery indicator based on charge level
- Read information from '*/sys/class/power_supply*'

### Build
*gcc main.c battery.c battery_info.c charging_info.c bat_ls.c health_info.c null.c -o batteryfetch*   

#### Usage
./batteryfetch

#### Screenshot
![Batteryfetch screenshot]
(https://github.com/QuasiRave/Batteryfetch/blob/main/screenshots/batteryfetch1.1.png)
