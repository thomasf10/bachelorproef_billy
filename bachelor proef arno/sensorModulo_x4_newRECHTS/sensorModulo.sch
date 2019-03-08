EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:tcrt5000
LIBS:sensorModulo-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L R R2
U 1 1 5A0472AF
P 3000 4050
F 0 "R2" V 3080 4050 50  0000 C CNN
F 1 "R56k" V 3000 4050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2930 4050 50  0001 C CNN
F 3 "" H 3000 4050 50  0001 C CNN
	1    3000 4050
	1    0    0    -1  
$EndComp
$Comp
L TCRT5000 U2
U 1 1 5A047469
P 3850 4400
F 0 "U2" H 3850 4400 60  0000 C CNN
F 1 "TCRT5000" H 3850 4550 60  0000 C CNN
F 2 "lib:TRTC5000" H 3850 4400 60  0001 C CNN
F 3 "" H 3850 4400 60  0001 C CNN
	1    3850 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 4350 5150 4350
$Comp
L R R1
U 1 1 5A047E13
P 3000 2450
F 0 "R1" V 3080 2450 50  0000 C CNN
F 1 "R56k" V 3000 2450 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2930 2450 50  0001 C CNN
F 3 "" H 3000 2450 50  0001 C CNN
	1    3000 2450
	1    0    0    -1  
$EndComp
$Comp
L TCRT5000 U1
U 1 1 5A047E19
P 3850 2800
F 0 "U1" H 3850 2800 60  0000 C CNN
F 1 "TCRT5000" H 3850 2950 60  0000 C CNN
F 2 "lib:TRTC5000" H 3850 2800 60  0001 C CNN
F 3 "" H 3850 2800 60  0001 C CNN
	1    3850 2800
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 5A047E29
P 3950 5300
F 0 "R3" V 4030 5300 50  0000 C CNN
F 1 "R220k" V 3950 5300 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 3880 5300 50  0001 C CNN
F 3 "" H 3950 5300 50  0001 C CNN
	1    3950 5300
	0    1    1    0   
$EndComp
Wire Wire Line
	4450 2750 5150 2750
Wire Wire Line
	4450 2850 4850 2850
Wire Wire Line
	4850 2850 4850 7275
Wire Wire Line
	4450 4450 4850 4450
Connection ~ 4850 4450
Wire Wire Line
	2350 2750 3200 2750
Wire Wire Line
	3000 2750 3000 2600
Wire Wire Line
	2425 4350 3200 4350
Wire Wire Line
	3000 4350 3000 4200
Connection ~ 3000 4350
Wire Wire Line
	3000 3750 3000 3900
Text Label 1975 5375 2    60   ~ 0
VDD
Text Label 2050 4975 2    60   ~ 0
sens1
Text Label 2050 5075 2    60   ~ 0
sens2
Connection ~ 3000 2750
Wire Wire Line
	3200 2850 3050 2850
Wire Wire Line
	3050 2850 3050 3000
Wire Wire Line
	3050 3000 4850 3000
Connection ~ 4850 3000
Wire Wire Line
	3200 4450 3000 4450
$Comp
L R R5
U 1 1 5A9FF324
P 3075 5450
F 0 "R5" V 3155 5450 50  0000 C CNN
F 1 "R56k" V 3075 5450 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 3005 5450 50  0001 C CNN
F 3 "" H 3075 5450 50  0001 C CNN
	1    3075 5450
	1    0    0    -1  
$EndComp
$Comp
L TCRT5000 U3
U 1 1 5A9FF32A
P 3925 5800
F 0 "U3" H 3925 5800 60  0000 C CNN
F 1 "TCRT5000" H 3925 5950 60  0000 C CNN
F 2 "lib:TRTC5000" H 3925 5800 60  0001 C CNN
F 3 "" H 3925 5800 60  0001 C CNN
	1    3925 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4525 5750 5150 5750
Wire Wire Line
	2425 5750 3275 5750
Wire Wire Line
	3075 5750 3075 5600
Connection ~ 3075 5750
Wire Wire Line
	3275 5850 3125 5850
Wire Wire Line
	3125 5850 3125 6000
$Comp
L R R7
U 1 1 5A9FF4E3
P 2975 6675
F 0 "R7" V 3055 6675 50  0000 C CNN
F 1 "R56k" V 2975 6675 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2905 6675 50  0001 C CNN
F 3 "" H 2975 6675 50  0001 C CNN
	1    2975 6675
	1    0    0    -1  
$EndComp
$Comp
L TCRT5000 U4
U 1 1 5A9FF4E9
P 3825 7025
F 0 "U4" H 3825 7025 60  0000 C CNN
F 1 "TCRT5000" H 3825 7175 60  0000 C CNN
F 2 "lib:TRTC5000" H 3825 7025 60  0001 C CNN
F 3 "" H 3825 7025 60  0001 C CNN
	1    3825 7025
	1    0    0    -1  
$EndComp
Wire Wire Line
	4425 6975 5150 6975
Wire Wire Line
	4850 7075 4425 7075
Wire Wire Line
	2350 6975 3175 6975
Wire Wire Line
	2975 6975 2975 6825
Connection ~ 2975 6975
Wire Wire Line
	2100 7075 3175 7075
Connection ~ 4850 5850
$Comp
L Conn_01x06_Female J1
U 1 1 5AA00219
P 1550 5275
F 0 "J1" H 1550 5575 50  0000 C CNN
F 1 "Conn_01x06_Female" H 1550 4875 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x06_Pitch2.54mm" H 1550 5275 50  0001 C CNN
F 3 "" H 1550 5275 50  0001 C CNN
	1    1550 5275
	-1   0    0    1   
$EndComp
Wire Wire Line
	2100 7075 2100 5475
Text Label 1975 5475 2    60   ~ 0
GND
Wire Wire Line
	3000 4450 3000 4625
Wire Wire Line
	3000 4625 4850 4625
Connection ~ 4850 4625
Wire Wire Line
	3125 6000 4850 6000
Connection ~ 4850 6000
Wire Wire Line
	4525 5850 4850 5850
Wire Wire Line
	2975 7075 2975 7275
Wire Wire Line
	2975 7275 4850 7275
Connection ~ 4850 7075
Connection ~ 2975 7075
Wire Wire Line
	2225 2275 2225 6525
Wire Wire Line
	1750 5375 2550 5375
Connection ~ 2225 5375
Connection ~ 2225 3750
Wire Wire Line
	2350 4975 2350 2750
Wire Wire Line
	1750 4975 2350 4975
Wire Wire Line
	2425 5075 2425 4350
Wire Wire Line
	1750 5075 2425 5075
Wire Wire Line
	2425 5175 2425 5750
Wire Wire Line
	1750 5175 2425 5175
Wire Wire Line
	2550 5375 2550 5300
Wire Wire Line
	2350 5275 2350 6975
Wire Wire Line
	1750 5275 2350 5275
Text Label 2050 5175 2    60   ~ 0
sens3
Text Label 2050 5275 2    60   ~ 0
sens4
Wire Wire Line
	2100 5475 1750 5475
Wire Wire Line
	3000 2275 2225 2275
Wire Wire Line
	3000 2300 3000 2275
Wire Wire Line
	5150 6975 5150 2750
Wire Wire Line
	2225 6525 2975 6525
Wire Wire Line
	2550 5300 3800 5300
Wire Wire Line
	3000 3750 2225 3750
Connection ~ 5150 4350
Connection ~ 5150 5750
Connection ~ 3075 5300
Wire Wire Line
	4100 5300 5150 5300
Connection ~ 5150 5300
$EndSCHEMATC
