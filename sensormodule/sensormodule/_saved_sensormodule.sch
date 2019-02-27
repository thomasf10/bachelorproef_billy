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
Wire Wire Line
	3775 2200 3775 2425
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
Wire Wire Line
	3175 2200 3175 2425
Wire Wire Line
	3175 2425 3775 2425
Connection ~ 3775 2425
Wire Wire Line
	3950 2200 3950 2425
Wire Wire Line
	3950 2425 3775 2425
Wire Wire Line
	4550 2200 4550 2425
Connection ~ 3950 2425
Wire Wire Line
	4700 2200 4700 2425
Wire Wire Line
	3950 2425 4550 2425
Connection ~ 4550 2425
Wire Wire Line
	5300 2200 5300 2425
Wire Wire Line
	4550 2425 4700 2425
Connection ~ 4700 2425
Wire Wire Line
	4700 2425 5300 2425
$Comp
L Device:R R2
U 1 1 5C6D394E
P 3775 1675
F 0 "R2" H 3845 1721 50  0000 L CNN
F 1 "47k" H 3575 1700 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3705 1675 50  0001 C CNN
F 3 "~" H 3775 1675 50  0001 C CNN
	1    3775 1675
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5C6D39B0
P 4550 1675
F 0 "R4" H 4620 1721 50  0000 L CNN
F 1 "47k" H 4325 1700 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4480 1675 50  0001 C CNN
F 3 "~" H 4550 1675 50  0001 C CNN
	1    4550 1675
	1    0    0    -1  
$EndComp
Wire Wire Line
	3775 2000 3775 1925
$Comp
L Device:R R1
U 1 1 5C6D3C59
P 3175 1675
F 0 "R1" H 3245 1721 50  0000 L CNN
F 1 "220" H 3245 1630 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3105 1675 50  0001 C CNN
F 3 "~" H 3175 1675 50  0001 C CNN
	1    3175 1675
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5C6D3C99
P 3950 1675
F 0 "R3" H 4020 1721 50  0000 L CNN
F 1 "220" H 4020 1630 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3880 1675 50  0001 C CNN
F 3 "~" H 3950 1675 50  0001 C CNN
	1    3950 1675
	1    0    0    -1  
$EndComp
Wire Wire Line
	3175 1825 3175 2000
Wire Wire Line
	3950 1825 3950 2000
Wire Wire Line
	4550 1825 4550 1875
$Comp
L Device:R R5
U 1 1 5C6D4060
P 4700 1675
F 0 "R5" H 4770 1721 50  0000 L CNN
F 1 "220" H 4770 1630 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4630 1675 50  0001 C CNN
F 3 "~" H 4700 1675 50  0001 C CNN
	1    4700 1675
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5C6D4094
P 5300 1675
F 0 "R6" H 5370 1721 50  0000 L CNN
F 1 "47k" H 5100 1725 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5230 1675 50  0001 C CNN
F 3 "~" H 5300 1675 50  0001 C CNN
	1    5300 1675
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 2000 4700 1825
Wire Wire Line
	3175 1525 3775 1525
Connection ~ 3775 1525
Wire Wire Line
	3775 1525 3950 1525
Connection ~ 3950 1525
Wire Wire Line
	3950 1525 4375 1525
Connection ~ 4550 1525
Wire Wire Line
	4550 1525 4700 1525
Connection ~ 4700 1525
Wire Wire Line
	4375 1525 4375 1400
Connection ~ 4375 1525
Wire Wire Line
	4375 1525 4550 1525
$Comp
L power:+5V #PWR02
U 1 1 5C6D569A
P 4375 1400
F 0 "#PWR02" H 4375 1250 50  0001 C CNN
F 1 "+5V" H 4390 1573 50  0000 C CNN
F 2 "" H 4375 1400 50  0001 C CNN
F 3 "" H 4375 1400 50  0001 C CNN
	1    4375 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 1525 5550 1825
$Comp
L Device:C C1
U 1 1 5C6D660D
P 5550 1975
F 0 "C1" H 5665 2021 50  0000 L CNN
F 1 "10n" H 5665 1930 50  0000 L CNN
F 2 "" H 5588 1825 50  0001 C CNN
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
F 2 "" H 5950 2000 50  0001 C CNN
F 3 "~" H 5950 2000 50  0001 C CNN
	1    5950 2000
	1    0    0    -1  
$EndComp
Connection ~ 3775 1925
Wire Wire Line
	3775 1925 3775 1825
Connection ~ 4550 1875
Wire Wire Line
	4550 1875 4550 2000
Wire Wire Line
	4700 1525 5300 1525
Wire Wire Line
	5300 1825 5300 1850
Connection ~ 5300 1850
Wire Wire Line
	5300 1850 5300 2000
Wire Wire Line
	2475 1850 2475 1825
Wire Wire Line
	2475 1850 5300 1850
Wire Wire Line
	2500 1875 2500 1925
Wire Wire Line
	2500 1875 4550 1875
Wire Wire Line
	2575 1925 2575 2025
Wire Wire Line
	2575 1925 3775 1925
Wire Wire Line
	4375 1400 2475 1400
Connection ~ 4375 1400
Wire Wire Line
	3175 2425 2475 2425
Wire Wire Line
	2475 2425 2475 2125
Connection ~ 3175 2425
$Comp
L Sensor_Proximity:QRE1113 U1
U 1 1 5C766DAC
P 3475 2100
F 0 "U1" H 3475 2417 50  0000 C CNN
F 1 "QRE1113" H 3475 2326 50  0000 C CNN
F 2 "OptoDevice:OnSemi_CASE100CY" H 3475 1900 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/QRE1113-D.PDF" H 3475 2200 50  0001 C CNN
	1    3475 2100
	1    0    0    -1  
$EndComp
$Comp
L Sensor_Proximity:QRE1113 U2
U 1 1 5C7671CA
P 4250 2100
F 0 "U2" H 4250 2417 50  0000 C CNN
F 1 "QRE1113" H 4250 2326 50  0000 C CNN
F 2 "OptoDevice:OnSemi_CASE100CY" H 4250 1900 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/QRE1113-D.PDF" H 4250 2200 50  0001 C CNN
	1    4250 2100
	1    0    0    -1  
$EndComp
$Comp
L Sensor_Proximity:QRE1113 U3
U 1 1 5C76720A
P 5000 2100
F 0 "U3" H 5000 2417 50  0000 C CNN
F 1 "QRE1113" H 5000 2326 50  0000 C CNN
F 2 "OptoDevice:OnSemi_CASE100CY" H 5000 1900 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/QRE1113-D.PDF" H 5000 2200 50  0001 C CNN
	1    5000 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 1525 5550 1525
Connection ~ 5300 1525
Connection ~ 5550 1525
Wire Wire Line
	5300 2425 5550 2425
Connection ~ 5300 2425
Connection ~ 5550 2425
Wire Wire Line
	5550 2125 5550 2425
$Comp
L Connector:Screw_Terminal_01x05 J?
U 1 1 5C770605
P 2025 1925
F 0 "J?" H 1945 1500 50  0000 C CNN
F 1 "Screw_Terminal_01x05" H 1945 1591 50  0000 C CNN
F 2 "" H 2025 1925 50  0001 C CNN
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
	2475 1825 2225 1825
Wire Wire Line
	2475 1725 2225 1725
Wire Wire Line
	2475 1400 2475 1725
$EndSCHEMATC
