EESchema Schematic File Version 4
LIBS:Arduino_Uno_R3_From_Scratch-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 11
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
L power:GND #PWR?
U 1 1 5C78928F
P 2575 3450
AR Path="/5C6DA90A/5C78928F" Ref="#PWR?"  Part="1" 
AR Path="/5C6DD8AC/5C78928F" Ref="#PWR0105"  Part="1" 
AR Path="/5C6FDA9D/5C78928F" Ref="#PWR?"  Part="1" 
F 0 "#PWR0105" H 2575 3200 50  0001 C CNN
F 1 "GND" H 2580 3277 50  0000 C CNN
F 2 "" H 2575 3450 50  0001 C CNN
F 3 "" H 2575 3450 50  0001 C CNN
	1    2575 3450
	1    0    0    -1  
$EndComp
$Comp
L Arduino_Uno_R3_From_Scratch:5V_LDO #PWR?
U 1 1 5C789290
P 2575 2175
AR Path="/5C6DA90A/5C789290" Ref="#PWR?"  Part="1" 
AR Path="/5C6DD8AC/5C789290" Ref="#PWR0106"  Part="1" 
AR Path="/5C6FDA9D/5C789290" Ref="#PWR?"  Part="1" 
F 0 "#PWR0106" H 2575 2265 20  0001 C CNN
F 1 "5V_LDO" H 2571 2313 30  0000 C CNN
F 2 "" H 2575 2175 60  0000 C CNN
F 3 "" H 2575 2175 60  0000 C CNN
	1    2575 2175
	1    0    0    -1  
$EndComp
$Comp
L Device:C C11
U 1 1 5C6DE2F5
P 2575 2900
AR Path="/5C6DD8AC/5C6DE2F5" Ref="C11"  Part="1" 
AR Path="/5C6FDA9D/5C6DE2F5" Ref="C?"  Part="1" 
F 0 "C11" H 2690 2946 50  0000 L CNN
F 1 "10u" H 2690 2855 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 2613 2750 50  0001 C CNN
F 3 "~" H 2575 2900 50  0001 C CNN
	1    2575 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C12
U 1 1 5C6DE373
P 3050 2900
AR Path="/5C6DD8AC/5C6DE373" Ref="C12"  Part="1" 
AR Path="/5C6FDA9D/5C6DE373" Ref="C?"  Part="1" 
F 0 "C12" H 3165 2946 50  0000 L CNN
F 1 "10u" H 3165 2855 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 3088 2750 50  0001 C CNN
F 3 "~" H 3050 2900 50  0001 C CNN
	1    3050 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2575 3450 2575 3225
Wire Wire Line
	2575 2750 2575 2450
Wire Wire Line
	3050 2750 3050 2450
Wire Wire Line
	2575 2450 3050 2450
Wire Wire Line
	3050 3050 3050 3225
Wire Wire Line
	3050 3225 2575 3225
Connection ~ 2575 3225
Wire Wire Line
	2575 3225 2575 3050
$Comp
L power:GND #PWR?
U 1 1 5C6DE536
P 3850 3450
AR Path="/5C6DA90A/5C6DE536" Ref="#PWR?"  Part="1" 
AR Path="/5C6DD8AC/5C6DE536" Ref="#PWR0107"  Part="1" 
AR Path="/5C6FDA9D/5C6DE536" Ref="#PWR?"  Part="1" 
F 0 "#PWR0107" H 3850 3200 50  0001 C CNN
F 1 "GND" H 3855 3277 50  0000 C CNN
F 2 "" H 3850 3450 50  0001 C CNN
F 3 "" H 3850 3450 50  0001 C CNN
	1    3850 3450
	1    0    0    -1  
$EndComp
$Comp
L Arduino_Uno_R3_From_Scratch:5V_LDO #PWR?
U 1 1 5C6DE53C
P 4475 2275
AR Path="/5C6DA90A/5C6DE53C" Ref="#PWR?"  Part="1" 
AR Path="/5C6DD8AC/5C6DE53C" Ref="#PWR0108"  Part="1" 
AR Path="/5C6FDA9D/5C6DE53C" Ref="#PWR?"  Part="1" 
F 0 "#PWR0108" H 4475 2365 20  0001 C CNN
F 1 "5V_LDO" H 4471 2413 30  0000 C CNN
F 2 "" H 4475 2275 60  0000 C CNN
F 3 "" H 4475 2275 60  0000 C CNN
	1    4475 2275
	1    0    0    -1  
$EndComp
Wire Wire Line
	4475 2275 4475 2450
$Comp
L Device:C C16
U 1 1 5C6DE543
P 3850 2900
AR Path="/5C6DD8AC/5C6DE543" Ref="C16"  Part="1" 
AR Path="/5C6FDA9D/5C6DE543" Ref="C?"  Part="1" 
F 0 "C16" H 3965 2946 50  0000 L CNN
F 1 "100n" H 3965 2855 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 3888 2750 50  0001 C CNN
F 3 "~" H 3850 2900 50  0001 C CNN
	1    3850 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C17
U 1 1 5C6DE54A
P 4325 2900
AR Path="/5C6DD8AC/5C6DE54A" Ref="C17"  Part="1" 
AR Path="/5C6FDA9D/5C6DE54A" Ref="C?"  Part="1" 
F 0 "C17" H 4440 2946 50  0000 L CNN
F 1 "100n" H 4440 2855 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 4363 2750 50  0001 C CNN
F 3 "~" H 4325 2900 50  0001 C CNN
	1    4325 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 3450 3850 3225
Wire Wire Line
	3850 2750 3850 2450
Wire Wire Line
	4325 2750 4325 2450
Wire Wire Line
	3850 2450 4325 2450
Connection ~ 4325 2450
Wire Wire Line
	4325 2450 4475 2450
Wire Wire Line
	4325 3050 4325 3225
Wire Wire Line
	4325 3225 3850 3225
Connection ~ 3850 3225
Wire Wire Line
	3850 3225 3850 3050
$Comp
L Device:C C18
U 1 1 5C6DE722
P 4800 2900
AR Path="/5C6DD8AC/5C6DE722" Ref="C18"  Part="1" 
AR Path="/5C6FDA9D/5C6DE722" Ref="C?"  Part="1" 
F 0 "C18" H 4915 2946 50  0000 L CNN
F 1 "100n" H 4915 2855 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 4838 2750 50  0001 C CNN
F 3 "~" H 4800 2900 50  0001 C CNN
	1    4800 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 2750 4800 2450
Wire Wire Line
	4800 3050 4800 3225
$Comp
L Device:C C4
U 1 1 5C6DE8B0
P 5250 2900
AR Path="/5C6DD8AC/5C6DE8B0" Ref="C4"  Part="1" 
AR Path="/5C6FDA9D/5C6DE8B0" Ref="C?"  Part="1" 
F 0 "C4" H 5365 2946 50  0000 L CNN
F 1 "100n" H 5365 2855 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 5288 2750 50  0001 C CNN
F 3 "~" H 5250 2900 50  0001 C CNN
	1    5250 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 2750 5250 2450
Wire Wire Line
	5250 3050 5250 3225
Wire Wire Line
	4475 2450 4800 2450
Connection ~ 4475 2450
Wire Wire Line
	4800 2450 5250 2450
Connection ~ 4800 2450
Wire Wire Line
	4800 3225 4325 3225
Connection ~ 4325 3225
Wire Wire Line
	5250 3225 4800 3225
Connection ~ 4800 3225
Wire Wire Line
	2575 2175 2575 2450
Connection ~ 2575 2450
Text HLabel 2250 4175 0    50   Input ~ 0
VM
$Comp
L Device:R R11
U 1 1 5C6E0A60
P 2500 4450
AR Path="/5C6DD8AC/5C6E0A60" Ref="R11"  Part="1" 
AR Path="/5C6FDA9D/5C6E0A60" Ref="R?"  Part="1" 
F 0 "R11" H 2570 4496 50  0000 L CNN
F 1 "1" H 2570 4405 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 2430 4450 50  0001 C CNN
F 3 "~" H 2500 4450 50  0001 C CNN
	1    2500 4450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R12
U 1 1 5C6E0AB8
P 2900 4450
AR Path="/5C6DD8AC/5C6E0AB8" Ref="R12"  Part="1" 
AR Path="/5C6FDA9D/5C6E0AB8" Ref="R?"  Part="1" 
F 0 "R12" H 2970 4496 50  0000 L CNN
F 1 "1" H 2970 4405 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 2830 4450 50  0001 C CNN
F 3 "~" H 2900 4450 50  0001 C CNN
	1    2900 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 4175 2500 4175
Wire Wire Line
	2500 4175 2500 4300
Wire Wire Line
	2500 4175 2900 4175
Wire Wire Line
	2900 4175 2900 4300
Connection ~ 2500 4175
$Comp
L Device:C C5
U 1 1 5C6E1148
P 2500 4925
AR Path="/5C6DD8AC/5C6E1148" Ref="C5"  Part="1" 
AR Path="/5C6FDA9D/5C6E1148" Ref="C?"  Part="1" 
F 0 "C5" H 2615 4971 50  0000 L CNN
F 1 "10u" H 2615 4880 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 2538 4775 50  0001 C CNN
F 3 "~" H 2500 4925 50  0001 C CNN
	1    2500 4925
	1    0    0    -1  
$EndComp
$Comp
L Device:C C13
U 1 1 5C6E11B4
P 2900 4925
AR Path="/5C6DD8AC/5C6E11B4" Ref="C13"  Part="1" 
AR Path="/5C6FDA9D/5C6E11B4" Ref="C?"  Part="1" 
F 0 "C13" H 3015 4971 50  0000 L CNN
F 1 "10u" H 3015 4880 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 2938 4775 50  0001 C CNN
F 3 "~" H 2900 4925 50  0001 C CNN
	1    2900 4925
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 4775 2500 4600
Wire Wire Line
	2900 4775 2900 4600
$Comp
L power:GND #PWR0109
U 1 1 5C6E1E21
P 2700 5250
AR Path="/5C6DD8AC/5C6E1E21" Ref="#PWR0109"  Part="1" 
AR Path="/5C6FDA9D/5C6E1E21" Ref="#PWR?"  Part="1" 
F 0 "#PWR0109" H 2700 5000 50  0001 C CNN
F 1 "GND" H 2705 5077 50  0000 C CNN
F 2 "" H 2700 5250 50  0001 C CNN
F 3 "" H 2700 5250 50  0001 C CNN
	1    2700 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 5075 2500 5250
Wire Wire Line
	2500 5250 2700 5250
Wire Wire Line
	2900 5075 2900 5250
Wire Wire Line
	2900 5250 2700 5250
Connection ~ 2700 5250
$Comp
L Device:C C7
U 1 1 5C6E28A2
P 3900 4575
AR Path="/5C6DD8AC/5C6E28A2" Ref="C7"  Part="1" 
AR Path="/5C6FDA9D/5C6E28A2" Ref="C?"  Part="1" 
F 0 "C7" H 4015 4621 50  0000 L CNN
F 1 "100n" H 4015 4530 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 3938 4425 50  0001 C CNN
F 3 "~" H 3900 4575 50  0001 C CNN
	1    3900 4575
	1    0    0    -1  
$EndComp
$Comp
L Device:C C8
U 1 1 5C6E2FCE
P 4475 4575
AR Path="/5C6DD8AC/5C6E2FCE" Ref="C8"  Part="1" 
AR Path="/5C6FDA9D/5C6E2FCE" Ref="C?"  Part="1" 
F 0 "C8" H 4590 4621 50  0000 L CNN
F 1 "100n" H 4590 4530 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 4513 4425 50  0001 C CNN
F 3 "~" H 4475 4575 50  0001 C CNN
	1    4475 4575
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 4175 3900 4175
Wire Wire Line
	3900 4175 3900 4425
Connection ~ 2900 4175
Wire Wire Line
	3900 4175 4475 4175
Wire Wire Line
	4475 4175 4475 4425
Connection ~ 3900 4175
Wire Wire Line
	3900 4725 3900 5250
Wire Wire Line
	3900 5250 2900 5250
Connection ~ 2900 5250
Wire Wire Line
	4475 4725 4475 5250
Wire Wire Line
	4475 5250 3900 5250
Connection ~ 3900 5250
$Comp
L Device:CP C9
U 1 1 5C6E51B5
P 5125 4575
AR Path="/5C6DD8AC/5C6E51B5" Ref="C9"  Part="1" 
AR Path="/5C6FDA9D/5C6E51B5" Ref="C?"  Part="1" 
F 0 "C9" H 5243 4621 50  0000 L CNN
F 1 "0.47u" H 5243 4530 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_4x3.9" H 5163 4425 50  0001 C CNN
F 3 "~" H 5125 4575 50  0001 C CNN
	1    5125 4575
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C10
U 1 1 5C6E6266
P 5625 4575
AR Path="/5C6DD8AC/5C6E6266" Ref="C10"  Part="1" 
AR Path="/5C6FDA9D/5C6E6266" Ref="C?"  Part="1" 
F 0 "C10" H 5743 4621 50  0000 L CNN
F 1 "0.47u" H 5743 4530 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_4x3.9" H 5663 4425 50  0001 C CNN
F 3 "~" H 5625 4575 50  0001 C CNN
	1    5625 4575
	1    0    0    -1  
$EndComp
Wire Wire Line
	5125 4425 5125 4175
Connection ~ 4475 4175
Wire Wire Line
	5625 4175 5625 4425
Wire Wire Line
	4475 4175 5125 4175
Connection ~ 5125 4175
Wire Wire Line
	5125 4175 5625 4175
Wire Wire Line
	5125 4725 5125 5250
Wire Wire Line
	5125 5250 4475 5250
Connection ~ 4475 5250
Wire Wire Line
	5625 4725 5625 5250
Wire Wire Line
	5625 5250 5125 5250
Connection ~ 5125 5250
$EndSCHEMATC
