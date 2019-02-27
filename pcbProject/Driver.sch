EESchema Schematic File Version 4
LIBS:Arduino_Uno_R3_From_Scratch-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 9
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
L Driver_Motor:L298P U6
U 1 1 5BE448DC
P 5625 3900
F 0 "U6" H 5625 4778 50  0000 C CNN
F 1 "L298P" H 5625 4687 50  0000 C CNN
F 2 "" H 5775 4150 50  0001 C CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00000240.pdf" H 5775 4150 50  0001 C CNN
	1    5625 3900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR015
U 1 1 5BE4498B
P 5725 4850
F 0 "#PWR015" H 5725 4600 50  0001 C CNN
F 1 "GND" H 5730 4677 50  0000 C CNN
F 2 "" H 5725 4850 50  0001 C CNN
F 3 "" H 5725 4850 50  0001 C CNN
	1    5725 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5525 4600 5625 4600
Wire Wire Line
	5825 4600 5725 4600
Wire Wire Line
	5725 4600 5625 4600
Connection ~ 5725 4600
Connection ~ 5625 4600
Wire Wire Line
	5725 4600 5725 4850
Wire Wire Line
	5225 4600 5325 4600
Wire Wire Line
	5325 4600 5525 4600
Connection ~ 5325 4600
Connection ~ 5525 4600
$Comp
L Device:CP1 C4
U 1 1 5BE44A99
P 4225 4275
F 0 "C4" H 4340 4321 50  0000 L CNN
F 1 "100uF,25V" H 4340 4230 50  0000 L CNN
F 2 "" H 4225 4275 50  0001 C CNN
F 3 "~" H 4225 4275 50  0001 C CNN
	1    4225 4275
	1    0    0    -1  
$EndComp
Wire Wire Line
	5725 3200 5725 2800
Wire Wire Line
	5725 2800 4225 2800
Wire Wire Line
	4225 2800 4225 4125
$Comp
L power:GND #PWR011
U 1 1 5BE44D52
P 4225 4850
F 0 "#PWR011" H 4225 4600 50  0001 C CNN
F 1 "GND" H 4230 4677 50  0000 C CNN
F 2 "" H 4225 4850 50  0001 C CNN
F 3 "" H 4225 4850 50  0001 C CNN
	1    4225 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4225 4425 4225 4850
$Comp
L Device:C C8
U 1 1 5BE44F23
P 7775 3250
F 0 "C8" V 7523 3250 50  0000 C CNN
F 1 "0.1uF" V 7614 3250 50  0000 C CNN
F 2 "" H 7813 3100 50  0001 C CNN
F 3 "~" H 7775 3250 50  0001 C CNN
	1    7775 3250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR018
U 1 1 5BE45174
P 8525 3475
F 0 "#PWR018" H 8525 3225 50  0001 C CNN
F 1 "GND" H 8530 3302 50  0000 C CNN
F 2 "" H 8525 3475 50  0001 C CNN
F 3 "" H 8525 3475 50  0001 C CNN
	1    8525 3475
	1    0    0    -1  
$EndComp
Wire Wire Line
	7925 3250 8525 3250
Wire Wire Line
	8525 3250 8525 3475
$Comp
L Device:C C5
U 1 1 5BE4524F
P 2050 3275
F 0 "C5" V 1798 3275 50  0000 C CNN
F 1 "0.1uF" V 1889 3275 50  0000 C CNN
F 2 "" H 2088 3125 50  0001 C CNN
F 3 "~" H 2050 3275 50  0001 C CNN
	1    2050 3275
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5BE4556B
P 1525 3425
F 0 "#PWR03" H 1525 3175 50  0001 C CNN
F 1 "GND" H 1530 3252 50  0000 C CNN
F 2 "" H 1525 3425 50  0001 C CNN
F 3 "" H 1525 3425 50  0001 C CNN
	1    1525 3425
	1    0    0    -1  
$EndComp
Wire Wire Line
	1525 3425 1525 3275
Wire Wire Line
	1525 3275 1900 3275
$Comp
L Arduino_Uno_R3_From_Scratch:5V_LDO #PWR012
U 1 1 5BE46854
P 5625 2525
F 0 "#PWR012" H 5625 2615 20  0001 C CNN
F 1 "5V_LDO" H 5621 2663 30  0000 C CNN
F 2 "" H 5625 2525 60  0000 C CNN
F 3 "" H 5625 2525 60  0000 C CNN
	1    5625 2525
	1    0    0    -1  
$EndComp
Wire Wire Line
	5625 3200 5625 2525
Text HLabel 6350 4000 2    50   Output ~ 0
OUT3
Text HLabel 6350 4100 2    50   Output ~ 0
OUT4
Text HLabel 6350 3800 2    50   Output ~ 0
OUT2
Text HLabel 6350 3700 2    50   Output ~ 0
OUT1
Wire Wire Line
	6225 4100 6350 4100
Wire Wire Line
	6225 4000 6350 4000
Wire Wire Line
	6225 3800 6350 3800
Wire Wire Line
	6225 3700 6350 3700
Text HLabel 4825 3400 0    50   Input ~ 0
DIRA
Wire Wire Line
	4825 3400 5025 3400
Text HLabel 4825 3600 0    50   Input ~ 0
PWMA
Wire Wire Line
	4825 3600 5025 3600
Text HLabel 4825 3800 0    50   Input ~ 0
DIRB
Wire Wire Line
	4825 3800 5025 3800
Text HLabel 4825 4000 0    50   Input ~ 0
PWMB
Wire Wire Line
	4825 4000 5025 4000
$Comp
L Arduino_Uno_R3_From_Scratch:5V_LDO #PWR08
U 1 1 5BE48E9E
P 2525 2675
F 0 "#PWR08" H 2525 2765 20  0001 C CNN
F 1 "5V_LDO" H 2521 2813 30  0000 C CNN
F 2 "" H 2525 2675 60  0000 C CNN
F 3 "" H 2525 2675 60  0000 C CNN
	1    2525 2675
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 3275 2525 3275
Wire Wire Line
	2525 3275 2525 2675
$Comp
L Arduino_Uno_R3_From_Scratch:5V_LDO #PWR016
U 1 1 5BE494B2
P 7050 2525
F 0 "#PWR016" H 7050 2615 20  0001 C CNN
F 1 "5V_LDO" H 7046 2663 30  0000 C CNN
F 2 "" H 7050 2525 60  0000 C CNN
F 3 "" H 7050 2525 60  0000 C CNN
	1    7050 2525
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 2525 7050 3250
Wire Wire Line
	7050 3250 7625 3250
$Comp
L power:GND #PWR017
U 1 1 5BE49B6A
P 8100 4450
F 0 "#PWR017" H 8100 4200 50  0001 C CNN
F 1 "GND" H 8105 4277 50  0000 C CNN
F 2 "" H 8100 4450 50  0001 C CNN
F 3 "" H 8100 4450 50  0001 C CNN
	1    8100 4450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 5BE49BD0
P 2775 4450
F 0 "#PWR010" H 2775 4200 50  0001 C CNN
F 1 "GND" H 2780 4277 50  0000 C CNN
F 2 "" H 2775 4450 50  0001 C CNN
F 3 "" H 2775 4450 50  0001 C CNN
	1    2775 4450
	1    0    0    -1  
$EndComp
$Comp
L 74HC1G04:74HC1G04 U4
U 1 1 5BE4A21D
P 7675 3775
F 0 "U4" H 7800 3940 50  0000 C CNN
F 1 "74HC1G04" H 7800 3849 50  0000 C CNN
F 2 "" H 7625 3925 50  0001 C CNN
F 3 "" H 7625 3925 50  0001 C CNN
	1    7675 3775
	1    0    0    -1  
$EndComp
$Comp
L 74HC1G04:74HC1G04 U2
U 1 1 5BE4A42F
P 2250 3775
F 0 "U2" H 2375 3940 50  0000 C CNN
F 1 "74HC1G04" H 2375 3849 50  0000 C CNN
F 2 "" H 2200 3925 50  0001 C CNN
F 3 "" H 2200 3925 50  0001 C CNN
	1    2250 3775
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 4225 2775 4225
Wire Wire Line
	2775 4225 2775 4450
Wire Wire Line
	2100 4175 1850 4175
Wire Wire Line
	1850 4175 1850 4875
Wire Wire Line
	1850 4875 3800 4875
Wire Wire Line
	2100 3875 2050 3875
Wire Wire Line
	2050 3875 2050 3450
Wire Wire Line
	2050 3450 2525 3450
Wire Wire Line
	2525 3450 2525 3275
Connection ~ 2525 3275
Text HLabel 2850 4075 2    50   Input ~ 0
DIRA
Wire Wire Line
	2650 4075 2850 4075
Wire Wire Line
	8075 4225 8100 4225
Wire Wire Line
	8100 4225 8100 4450
Text HLabel 8275 4075 2    50   Input ~ 0
DIRB
Wire Wire Line
	8075 4075 8275 4075
Wire Wire Line
	7525 4175 6775 4175
Wire Wire Line
	6775 4175 6775 4750
Wire Wire Line
	6775 4750 4875 4750
Wire Wire Line
	4875 4750 4875 3900
Wire Wire Line
	4875 3900 5025 3900
Wire Wire Line
	3800 3500 5025 3500
Wire Wire Line
	3800 3500 3800 4875
Wire Wire Line
	7525 3875 7050 3875
Wire Wire Line
	7050 3875 7050 3250
Connection ~ 7050 3250
Text HLabel 4075 2800 0    50   Input ~ 0
PWRIN
Wire Wire Line
	4075 2800 4225 2800
Connection ~ 4225 2800
$EndSCHEMATC
