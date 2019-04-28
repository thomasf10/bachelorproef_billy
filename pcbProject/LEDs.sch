EESchema Schematic File Version 4
LIBS:Arduino_Uno_R3_From_Scratch-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 10 11
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
L Device:R R?
U 1 1 5C6DCC06
P 3450 3125
AR Path="/5BE519F1/5C6DCC06" Ref="R?"  Part="1" 
AR Path="/5C6DA90A/5C6DCC06" Ref="R10"  Part="1" 
AR Path="/5C6DD8AC/5C6DCC06" Ref="R?"  Part="1" 
F 0 "R10" V 3550 3125 50  0000 C CNN
F 1 "470" V 3334 3125 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 3380 3125 50  0001 C CNN
F 3 "~" H 3450 3125 50  0001 C CNN
	1    3450 3125
	-1   0    0    1   
$EndComp
$Comp
L Arduino_Uno_R3_From_Scratch-rescue:LED LED1
U 1 1 5C6DCC0F
P 3450 2725
AR Path="/5C6DA90A/5C6DCC0F" Ref="LED1"  Part="1" 
AR Path="/5C6DD8AC/5C6DCC0F" Ref="LED?"  Part="1" 
F 0 "LED1" H 3450 2600 50  0000 C CNN
F 1 "GREEN" H 3425 2850 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 3450 2725 60  0001 C CNN
F 3 "" H 3450 2725 60  0000 C CNN
	1    3450 2725
	0    -1   -1   0   
$EndComp
$Comp
L Arduino_Uno_R3_From_Scratch:5V_LDO #PWR0104
U 1 1 5C6DD332
P 3450 2350
AR Path="/5C6DA90A/5C6DD332" Ref="#PWR0104"  Part="1" 
AR Path="/5C6DD8AC/5C6DD332" Ref="#PWR?"  Part="1" 
F 0 "#PWR0104" H 3450 2440 20  0001 C CNN
F 1 "5V_LDO" H 3446 2488 30  0000 C CNN
F 2 "" H 3450 2350 60  0000 C CNN
F 3 "" H 3450 2350 60  0000 C CNN
	1    3450 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 2350 3450 2525
$Comp
L power:GND #PWR0103
U 1 1 5C6DAF20
P 3450 3350
AR Path="/5C6DA90A/5C6DAF20" Ref="#PWR0103"  Part="1" 
AR Path="/5C6DD8AC/5C6DAF20" Ref="#PWR?"  Part="1" 
F 0 "#PWR0103" H 3450 3100 50  0001 C CNN
F 1 "GND" H 3455 3177 50  0000 C CNN
F 2 "" H 3450 3350 50  0001 C CNN
F 3 "" H 3450 3350 50  0001 C CNN
	1    3450 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 3350 3450 3275
Wire Wire Line
	3450 2975 3450 2925
$EndSCHEMATC
