EESchema Schematic File Version 4
LIBS:sensormodule-cache
EELAYER 26 0
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
L power:GND #PWR01
U 1 1 5C6D36FF
P 3775 2425
F 0 "#PWR01" H 3775 2175 50  0001 C CNN
F 1 "GND" H 3780 2252 50  0000 C CNN
F 2 "" H 3775 2425 50  0001 C CNN
F 3 "" H 3775 2425 50  0001 C CNN
	1    3775 2425
	1    0    0    -1  
$EndComp
Connection ~ 3775 2425
$Comp
L power:+5V #PWR02
U 1 1 5C6D569A
P 3650 1275
F 0 "#PWR02" H 3650 1125 50  0001 C CNN
F 1 "+5V" H 3665 1448 50  0000 C CNN
F 2 "" H 3650 1275 50  0001 C CNN
F 3 "" H 3650 1275 50  0001 C CNN
	1    3650 1275
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5C6D660D
P 5550 1975
F 0 "C1" H 5665 2021 50  0000 L CNN
F 1 "10n" H 5665 1930 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 5588 1825 50  0001 C CNN
F 3 "~" H 5550 1975 50  0001 C CNN
	1    5550 1975
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 1525 5950 1525
Wire Wire Line
	5950 1525 5950 1850
Wire Wire Line
	5550 2425 5950 2425
Wire Wire Line
	5950 2425 5950 2150
$Comp
L Device:CP1 C2
U 1 1 5C6D73B7
P 5950 2000
F 0 "C2" H 6065 2046 50  0000 L CNN
F 1 "1u" H 6065 1955 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-6032-15_Kemet-U" H 5950 2000 50  0001 C CNN
F 3 "~" H 5950 2000 50  0001 C CNN
	1    5950 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2475 2425 2475 2125
Connection ~ 5550 2425
Wire Wire Line
	5550 2125 5550 2425
$Comp
L Connector:Screw_Terminal_01x05 J1
U 1 1 5C770605
P 2025 1925
F 0 "J1" H 1945 1500 50  0000 C CNN
F 1 "Screw_Terminal_01x05" H 1945 1591 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 2025 1925 50  0001 C CNN
F 3 "~" H 2025 1925 50  0001 C CNN
	1    2025 1925
	-1   0    0    1   
$EndComp
Wire Wire Line
	2475 2125 2225 2125
Wire Wire Line
	2225 2025 2575 2025
Wire Wire Line
	2225 1925 2500 1925
Wire Wire Line
	2475 1725 2225 1725
$Comp
L TCRT5000:TCRT5000 U1
U 1 1 5C97A40E
P 3075 1950
F 0 "U1" H 3075 2315 50  0000 C CNN
F 1 "TCRT5000" H 3075 2224 50  0000 C CNN
F 2 "TCRT5000:OPTO_TCRT5000" H 3075 1950 50  0001 L BNN
F 3 "PCB Mount Vishay" H 3075 1950 50  0001 L BNN
F 4 "TCRT5000" H 3075 1950 50  0001 L BNN "Field4"
F 5 "Vishay" H 3075 1950 50  0001 L BNN "Field5"
F 6 "950 nm 60 mA Through Hole Reflective Optical Sensor with Transistor Output" H 3075 1950 50  0001 L BNN "Field6"
F 7 "Unavailable" H 3075 1950 50  0001 L BNN "Field7"
F 8 "None" H 3075 1950 50  0001 L BNN "Field8"
	1    3075 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3775 2425 4250 2425
$Comp
L TCRT5000:TCRT5000 U2
U 1 1 5C97A5C7
P 3950 1950
F 0 "U2" H 3950 2315 50  0000 C CNN
F 1 "TCRT5000" H 3950 2224 50  0000 C CNN
F 2 "TCRT5000:OPTO_TCRT5000" H 3950 1950 50  0001 L BNN
F 3 "PCB Mount Vishay" H 3950 1950 50  0001 L BNN
F 4 "TCRT5000" H 3950 1950 50  0001 L BNN "Field4"
F 5 "Vishay" H 3950 1950 50  0001 L BNN "Field5"
F 6 "950 nm 60 mA Through Hole Reflective Optical Sensor with Transistor Output" H 3950 1950 50  0001 L BNN "Field6"
F 7 "Unavailable" H 3950 1950 50  0001 L BNN "Field7"
F 8 "None" H 3950 1950 50  0001 L BNN "Field8"
	1    3950 1950
	1    0    0    -1  
$EndComp
$Comp
L TCRT5000:TCRT5000 U3
U 1 1 5C97A607
P 4875 1950
F 0 "U3" H 4875 2315 50  0000 C CNN
F 1 "TCRT5000" H 4875 2224 50  0000 C CNN
F 2 "TCRT5000:OPTO_TCRT5000" H 4875 1950 50  0001 L BNN
F 3 "PCB Mount Vishay" H 4875 1950 50  0001 L BNN
F 4 "TCRT5000" H 4875 1950 50  0001 L BNN "Field4"
F 5 "Vishay" H 4875 1950 50  0001 L BNN "Field5"
F 6 "950 nm 60 mA Through Hole Reflective Optical Sensor with Transistor Output" H 4875 1950 50  0001 L BNN "Field6"
F 7 "Unavailable" H 4875 1950 50  0001 L BNN "Field7"
F 8 "None" H 4875 1950 50  0001 L BNN "Field8"
	1    4875 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4575 2050 4575 2425
Connection ~ 4575 2425
Wire Wire Line
	4575 2425 5175 2425
Wire Wire Line
	5175 2050 5175 2425
Connection ~ 5175 2425
Wire Wire Line
	5175 2425 5550 2425
Wire Wire Line
	4250 2050 4250 2425
Connection ~ 4250 2425
Wire Wire Line
	4250 2425 4575 2425
Wire Wire Line
	3650 2050 3650 2425
Connection ~ 3650 2425
Wire Wire Line
	3650 2425 3775 2425
Wire Wire Line
	3375 2050 3375 2425
Connection ~ 3375 2425
Wire Wire Line
	3375 2425 3650 2425
Wire Wire Line
	2775 2050 2775 2425
Wire Wire Line
	2475 2425 2775 2425
Connection ~ 2775 2425
Wire Wire Line
	2775 2425 3375 2425
$Comp
L Device:R R5
U 1 1 5C97C7B4
P 4575 1700
F 0 "R5" H 4645 1746 50  0000 L CNN
F 1 "100" H 4645 1655 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 4505 1700 50  0001 C CNN
F 3 "~" H 4575 1700 50  0001 C CNN
	1    4575 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5C97C8AF
P 3650 1700
F 0 "R3" H 3720 1746 50  0000 L CNN
F 1 "100" H 3720 1655 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 3580 1700 50  0001 C CNN
F 3 "~" H 3650 1700 50  0001 C CNN
	1    3650 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5C97C90B
P 2775 1700
F 0 "R1" H 2845 1746 50  0000 L CNN
F 1 "100" H 2845 1655 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 2705 1700 50  0001 C CNN
F 3 "~" H 2775 1700 50  0001 C CNN
	1    2775 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4575 1275 4575 1550
Wire Wire Line
	3650 1550 3650 1275
Connection ~ 3650 1275
Wire Wire Line
	2475 1275 2775 1275
Wire Wire Line
	2475 1275 2475 1725
Connection ~ 2775 1275
Wire Wire Line
	5550 1275 5550 1525
Connection ~ 4575 1275
Connection ~ 5550 1525
Wire Wire Line
	5550 1525 5550 1825
$Comp
L Device:R R4
U 1 1 5C97E0CA
P 4250 1425
F 0 "R4" H 4320 1471 50  0000 L CNN
F 1 "4700" H 4320 1380 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 4180 1425 50  0001 C CNN
F 3 "~" H 4250 1425 50  0001 C CNN
	1    4250 1425
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5C97E10E
P 5175 1425
F 0 "R6" H 5245 1471 50  0000 L CNN
F 1 "4700" H 5245 1380 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 5105 1425 50  0001 C CNN
F 3 "~" H 5175 1425 50  0001 C CNN
	1    5175 1425
	1    0    0    -1  
$EndComp
Wire Wire Line
	2575 1475 2575 2025
Wire Wire Line
	2775 1275 2775 1550
Wire Wire Line
	2775 1275 3375 1275
$Comp
L Device:R R2
U 1 1 5C97E072
P 3375 1425
F 0 "R2" H 3445 1471 50  0000 L CNN
F 1 "4700" H 3445 1380 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 3305 1425 50  0001 C CNN
F 3 "~" H 3375 1425 50  0001 C CNN
	1    3375 1425
	1    0    0    -1  
$EndComp
Connection ~ 3375 1275
Wire Wire Line
	3375 1275 3650 1275
Wire Wire Line
	3650 1275 4250 1275
Wire Wire Line
	4575 1275 5175 1275
Connection ~ 5175 1275
Wire Wire Line
	5175 1275 5550 1275
Connection ~ 4250 1275
Wire Wire Line
	4250 1275 4575 1275
Wire Wire Line
	4250 1575 4250 1650
Wire Wire Line
	3375 1575 3375 1600
Wire Wire Line
	2575 1475 3250 1475
Wire Wire Line
	3250 1475 3250 1600
Wire Wire Line
	3250 1600 3375 1600
Connection ~ 3375 1600
Wire Wire Line
	3375 1600 3375 1850
Wire Wire Line
	4250 1650 2500 1650
Wire Wire Line
	2500 1650 2500 1925
Connection ~ 4250 1650
Wire Wire Line
	4250 1650 4250 1850
Wire Wire Line
	2225 1825 5175 1825
Wire Wire Line
	5175 1575 5175 1825
Connection ~ 5175 1825
Wire Wire Line
	5175 1825 5175 1850
$EndSCHEMATC
