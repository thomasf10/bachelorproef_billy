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
P 6150 5400
AR Path="/5C6DA90A/5C78928F" Ref="#PWR?"  Part="1" 
AR Path="/5C6DD8AC/5C78928F" Ref="#PWR0105"  Part="1" 
AR Path="/5C6FDA9D/5C78928F" Ref="#PWR?"  Part="1" 
F 0 "#PWR0105" H 6150 5150 50  0001 C CNN
F 1 "GND" H 6155 5227 50  0000 C CNN
F 2 "" H 6150 5400 50  0001 C CNN
F 3 "" H 6150 5400 50  0001 C CNN
	1    6150 5400
	1    0    0    -1  
$EndComp
$Comp
L Arduino_Uno_R3_From_Scratch:5V_LDO #PWR?
U 1 1 5C789290
P 6150 4125
AR Path="/5C6DA90A/5C789290" Ref="#PWR?"  Part="1" 
AR Path="/5C6DD8AC/5C789290" Ref="#PWR0106"  Part="1" 
AR Path="/5C6FDA9D/5C789290" Ref="#PWR?"  Part="1" 
F 0 "#PWR0106" H 6150 4215 20  0001 C CNN
F 1 "5V_LDO" H 6146 4263 30  0000 C CNN
F 2 "" H 6150 4125 60  0000 C CNN
F 3 "" H 6150 4125 60  0000 C CNN
	1    6150 4125
	1    0    0    -1  
$EndComp
$Comp
L Device:C C11
U 1 1 5C6DE2F5
P 6150 4850
AR Path="/5C6DD8AC/5C6DE2F5" Ref="C11"  Part="1" 
AR Path="/5C6FDA9D/5C6DE2F5" Ref="C?"  Part="1" 
F 0 "C11" H 6265 4896 50  0000 L CNN
F 1 "10u" H 6265 4805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 6188 4700 50  0001 C CNN
F 3 "~" H 6150 4850 50  0001 C CNN
	1    6150 4850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C12
U 1 1 5C6DE373
P 6625 4850
AR Path="/5C6DD8AC/5C6DE373" Ref="C12"  Part="1" 
AR Path="/5C6FDA9D/5C6DE373" Ref="C?"  Part="1" 
F 0 "C12" H 6740 4896 50  0000 L CNN
F 1 "10u" H 6740 4805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 6663 4700 50  0001 C CNN
F 3 "~" H 6625 4850 50  0001 C CNN
	1    6625 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 5400 6150 5175
Wire Wire Line
	6150 4700 6150 4400
Wire Wire Line
	6625 4700 6625 4400
Wire Wire Line
	6150 4400 6625 4400
Wire Wire Line
	6625 5000 6625 5175
Wire Wire Line
	6625 5175 6150 5175
Connection ~ 6150 5175
Wire Wire Line
	6150 5175 6150 5000
$Comp
L power:GND #PWR?
U 1 1 5C6DE536
P 7425 5400
AR Path="/5C6DA90A/5C6DE536" Ref="#PWR?"  Part="1" 
AR Path="/5C6DD8AC/5C6DE536" Ref="#PWR0107"  Part="1" 
AR Path="/5C6FDA9D/5C6DE536" Ref="#PWR?"  Part="1" 
F 0 "#PWR0107" H 7425 5150 50  0001 C CNN
F 1 "GND" H 7430 5227 50  0000 C CNN
F 2 "" H 7425 5400 50  0001 C CNN
F 3 "" H 7425 5400 50  0001 C CNN
	1    7425 5400
	1    0    0    -1  
$EndComp
$Comp
L Arduino_Uno_R3_From_Scratch:5V_LDO #PWR?
U 1 1 5C6DE53C
P 8050 4225
AR Path="/5C6DA90A/5C6DE53C" Ref="#PWR?"  Part="1" 
AR Path="/5C6DD8AC/5C6DE53C" Ref="#PWR0108"  Part="1" 
AR Path="/5C6FDA9D/5C6DE53C" Ref="#PWR?"  Part="1" 
F 0 "#PWR0108" H 8050 4315 20  0001 C CNN
F 1 "5V_LDO" H 8046 4363 30  0000 C CNN
F 2 "" H 8050 4225 60  0000 C CNN
F 3 "" H 8050 4225 60  0000 C CNN
	1    8050 4225
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 4225 8050 4400
$Comp
L Device:C C16
U 1 1 5C6DE543
P 7425 4850
AR Path="/5C6DD8AC/5C6DE543" Ref="C16"  Part="1" 
AR Path="/5C6FDA9D/5C6DE543" Ref="C?"  Part="1" 
F 0 "C16" H 7540 4896 50  0000 L CNN
F 1 "100n" H 7540 4805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 7463 4700 50  0001 C CNN
F 3 "~" H 7425 4850 50  0001 C CNN
	1    7425 4850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C17
U 1 1 5C6DE54A
P 7900 4850
AR Path="/5C6DD8AC/5C6DE54A" Ref="C17"  Part="1" 
AR Path="/5C6FDA9D/5C6DE54A" Ref="C?"  Part="1" 
F 0 "C17" H 8015 4896 50  0000 L CNN
F 1 "100n" H 8015 4805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 7938 4700 50  0001 C CNN
F 3 "~" H 7900 4850 50  0001 C CNN
	1    7900 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7425 5400 7425 5175
Wire Wire Line
	7425 4700 7425 4400
Wire Wire Line
	7900 4700 7900 4400
Wire Wire Line
	7425 4400 7900 4400
Connection ~ 7900 4400
Wire Wire Line
	7900 4400 8050 4400
Wire Wire Line
	7900 5000 7900 5175
Wire Wire Line
	7900 5175 7425 5175
Connection ~ 7425 5175
Wire Wire Line
	7425 5175 7425 5000
$Comp
L Device:C C18
U 1 1 5C6DE722
P 8375 4850
AR Path="/5C6DD8AC/5C6DE722" Ref="C18"  Part="1" 
AR Path="/5C6FDA9D/5C6DE722" Ref="C?"  Part="1" 
F 0 "C18" H 8490 4896 50  0000 L CNN
F 1 "100n" H 8490 4805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 8413 4700 50  0001 C CNN
F 3 "~" H 8375 4850 50  0001 C CNN
	1    8375 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8375 4700 8375 4400
Wire Wire Line
	8375 5000 8375 5175
$Comp
L Device:C C4
U 1 1 5C6DE8B0
P 8825 4850
AR Path="/5C6DD8AC/5C6DE8B0" Ref="C4"  Part="1" 
AR Path="/5C6FDA9D/5C6DE8B0" Ref="C?"  Part="1" 
F 0 "C4" H 8940 4896 50  0000 L CNN
F 1 "100n" H 8940 4805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 8863 4700 50  0001 C CNN
F 3 "~" H 8825 4850 50  0001 C CNN
	1    8825 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8825 4700 8825 4400
Wire Wire Line
	8825 5000 8825 5175
Wire Wire Line
	8050 4400 8375 4400
Connection ~ 8050 4400
Wire Wire Line
	8375 4400 8825 4400
Connection ~ 8375 4400
Wire Wire Line
	8375 5175 7900 5175
Connection ~ 7900 5175
Wire Wire Line
	8825 5175 8375 5175
Connection ~ 8375 5175
Wire Wire Line
	6150 4125 6150 4400
Connection ~ 6150 4400
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
