EESchema Schematic File Version 4
LIBS:Arduino_Uno_R3_From_Scratch-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 7 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	3275 2575 3600 2575
$Comp
L Connector:Screw_Terminal_01x04 J?
U 1 1 5BE4141B
P 3075 2775
F 0 "J?" H 2995 2350 50  0000 C CNN
F 1 "Screw_Terminal_01x04" H 2995 2441 50  0000 C CNN
F 2 "" H 3075 2775 50  0001 C CNN
F 3 "~" H 3075 2775 50  0001 C CNN
	1    3075 2775
	-1   0    0    1   
$EndComp
Wire Wire Line
	3275 2675 3925 2675
Wire Wire Line
	3275 2775 4300 2775
Wire Wire Line
	3275 2875 4775 2875
$Comp
L pspice:DIODE D?
U 1 1 5BE4158E
P 3600 2375
F 0 "D?" V 3646 2247 50  0000 R CNN
F 1 "DIODE" V 3555 2247 50  0000 R CNN
F 2 "" H 3600 2375 50  0001 C CNN
F 3 "" H 3600 2375 50  0001 C CNN
	1    3600 2375
	0    -1   -1   0   
$EndComp
Connection ~ 3600 2575
Wire Wire Line
	3600 2575 5350 2575
$Comp
L pspice:DIODE D?
U 1 1 5BE415F9
P 3925 2475
F 0 "D?" V 3971 2347 50  0000 R CNN
F 1 "DIODE" V 3880 2347 50  0000 R CNN
F 2 "" H 3925 2475 50  0001 C CNN
F 3 "" H 3925 2475 50  0001 C CNN
	1    3925 2475
	0    -1   -1   0   
$EndComp
Connection ~ 3925 2675
Wire Wire Line
	3925 2675 5375 2675
$Comp
L pspice:DIODE D?
U 1 1 5BE41635
P 4300 2575
F 0 "D?" V 4346 2447 50  0000 R CNN
F 1 "DIODE" V 4255 2447 50  0000 R CNN
F 2 "" H 4300 2575 50  0001 C CNN
F 3 "" H 4300 2575 50  0001 C CNN
	1    4300 2575
	0    -1   -1   0   
$EndComp
$Comp
L pspice:DIODE D?
U 1 1 5BE4166D
P 4775 2675
F 0 "D?" V 4821 2547 50  0000 R CNN
F 1 "DIODE" V 4730 2547 50  0000 R CNN
F 2 "" H 4775 2675 50  0001 C CNN
F 3 "" H 4775 2675 50  0001 C CNN
	1    4775 2675
	0    -1   -1   0   
$EndComp
Connection ~ 4775 2875
Wire Wire Line
	4775 2875 5375 2875
$Comp
L pspice:DIODE D?
U 1 1 5BE416AD
P 3600 2775
F 0 "D?" V 3646 2647 50  0000 R CNN
F 1 "DIODE" V 3555 2647 50  0000 R CNN
F 2 "" H 3600 2775 50  0001 C CNN
F 3 "" H 3600 2775 50  0001 C CNN
	1    3600 2775
	0    -1   -1   0   
$EndComp
$Comp
L pspice:DIODE D?
U 1 1 5BE41711
P 3925 2875
F 0 "D?" V 3971 2747 50  0000 R CNN
F 1 "DIODE" V 3880 2747 50  0000 R CNN
F 2 "" H 3925 2875 50  0001 C CNN
F 3 "" H 3925 2875 50  0001 C CNN
	1    3925 2875
	0    -1   -1   0   
$EndComp
Connection ~ 4300 2775
Wire Wire Line
	4300 2775 5375 2775
$Comp
L pspice:DIODE D?
U 1 1 5BE417E1
P 4300 2975
F 0 "D?" V 4346 2847 50  0000 R CNN
F 1 "DIODE" V 4255 2847 50  0000 R CNN
F 2 "" H 4300 2975 50  0001 C CNN
F 3 "" H 4300 2975 50  0001 C CNN
	1    4300 2975
	0    -1   -1   0   
$EndComp
$Comp
L pspice:DIODE D?
U 1 1 5BE4181D
P 4775 3075
F 0 "D?" V 4821 2947 50  0000 R CNN
F 1 "DIODE" V 4730 2947 50  0000 R CNN
F 2 "" H 4775 3075 50  0001 C CNN
F 3 "" H 4775 3075 50  0001 C CNN
	1    4775 3075
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3575 2175 3600 2175
Connection ~ 3600 2175
Wire Wire Line
	3925 2275 3925 2175
Wire Wire Line
	3600 2175 3925 2175
Connection ~ 3925 2175
Wire Wire Line
	3925 2175 4300 2175
Wire Wire Line
	4300 2375 4300 2175
Connection ~ 4300 2175
Wire Wire Line
	4300 2175 4775 2175
Wire Wire Line
	4775 2475 4775 2175
Connection ~ 4775 2175
Wire Wire Line
	4775 2175 5150 2175
$Comp
L power:GND #PWR?
U 1 1 5BE42866
P 4775 3275
F 0 "#PWR?" H 4775 3025 50  0001 C CNN
F 1 "GND" H 4780 3102 50  0000 C CNN
F 2 "" H 4775 3275 50  0001 C CNN
F 3 "" H 4775 3275 50  0001 C CNN
	1    4775 3275
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BE4288A
P 4300 3175
F 0 "#PWR?" H 4300 2925 50  0001 C CNN
F 1 "GND" H 4305 3002 50  0000 C CNN
F 2 "" H 4300 3175 50  0001 C CNN
F 3 "" H 4300 3175 50  0001 C CNN
	1    4300 3175
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BE428A7
P 3925 3075
F 0 "#PWR?" H 3925 2825 50  0001 C CNN
F 1 "GND" H 3930 2902 50  0000 C CNN
F 2 "" H 3925 3075 50  0001 C CNN
F 3 "" H 3925 3075 50  0001 C CNN
	1    3925 3075
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BE428C4
P 3600 2975
F 0 "#PWR?" H 3600 2725 50  0001 C CNN
F 1 "GND" H 3605 2802 50  0000 C CNN
F 2 "" H 3600 2975 50  0001 C CNN
F 3 "" H 3600 2975 50  0001 C CNN
	1    3600 2975
	1    0    0    -1  
$EndComp
$EndSCHEMATC
