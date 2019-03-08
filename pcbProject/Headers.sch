EESchema Schematic File Version 4
LIBS:Arduino_Uno_R3_From_Scratch-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 11
Title "Arduino UNO R3 Clone"
Date "8 oct 2015"
Rev "0"
Comp "Rheingold Heavy"
Comment1 "Based on the Arduino UNO R3 From arduino.cc"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Arduino_Uno_R3_From_Scratch:5V_LDO #PWR035
U 1 1 55E95D7A
P 5625 1875
F 0 "#PWR035" H 5625 1965 20  0001 C CNN
F 1 "5V_LDO" H 5625 1995 30  0000 C CNN
F 2 "~" H 5625 1875 60  0000 C CNN
F 3 "~" H 5625 1875 60  0000 C CNN
	1    5625 1875
	1    0    0    -1  
$EndComp
$Comp
L Arduino_Uno_R3_From_Scratch:3V3_LDO #PWR036
U 1 1 55E95D89
P 5400 1875
F 0 "#PWR036" H 5400 1835 30  0001 C CNN
F 1 "3V3_LDO" H 5400 1995 30  0000 C CNN
F 2 "~" H 5400 1875 60  0000 C CNN
F 3 "~" H 5400 1875 60  0000 C CNN
	1    5400 1875
	1    0    0    -1  
$EndComp
Text HLabel 5925 2225 0    40   Input ~ 0
328P_RESET
Text HLabel 4800 3475 0    40   Input ~ 0
ARD_AN3
Text HLabel 4800 3575 0    40   Input ~ 0
ARD_AN2
Text HLabel 4800 3675 0    40   Input ~ 0
ARD_AN1
Text HLabel 4800 3775 0    40   Input ~ 0
ARD_AN0
Text HLabel 4750 5575 0    40   Input ~ 0
ARD_DIG7
Text HLabel 4750 5475 0    40   Input ~ 0
ARD_DIG4
Text HLabel 4750 5375 0    40   Input ~ 0
ARD_DIG2
Text HLabel 4750 5275 0    40   Input ~ 0
ARD_DIG1
Text HLabel 4750 5175 0    40   Input ~ 0
ARD_DIG0
Text HLabel 4825 3375 0    40   Input ~ 0
ARD_AN4/SDA
Text HLabel 4825 3275 0    40   Input ~ 0
ARD_AN5/SCL
Text HLabel 4750 5675 0    40   Input ~ 0
ARD_DIG8
Text HLabel 4750 4800 0    40   Input ~ 0
ARD_DIG10/SPI_SS
Text HLabel 4750 4700 0    40   Input ~ 0
ARD_DIG11/SPI_MOSI
Text HLabel 4750 4600 0    40   Input ~ 0
ARD_DIG12/SPI_MISO
Text HLabel 4750 4500 0    40   Input ~ 0
ARD_DIG13/SPI_SCK
Text HLabel 4750 4300 0    40   Input ~ 0
AREF
$Comp
L Arduino_Uno_R3_From_Scratch-rescue:CONN_01X06 P1
U 1 1 5C574D09
P 6250 2475
F 0 "P1" H 6400 2350 60  0000 L CNN
F 1 "Power Header" H 6400 2475 60  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 6250 2475 60  0000 C CNN
F 3 "http://sullinscorp.com/catalogs/101_PAGE114-115_.100_FEMALE_HDR.pdf" H 6250 2475 60  0001 C CNN
F 4 "Connector Header 6 Position 0.100\" (2.54mm) Gold Surface Mount" H 6250 2475 60  0001 C CNN "Characteristics"
F 5 "Shield Header 6POS - ANLG" H 6250 2475 60  0001 C CNN "Description"
F 6 "Sullins Connector" H 6250 2475 60  0001 C CNN "MFN"
F 7 "NPPC061KFXC-RC" H 6250 2475 60  0001 C CNN "MFP"
F 8 "SMD" H 6250 2475 60  0001 C CNN "Package ID"
F 9 "ANY" H 6250 2475 60  0001 C CNN "Source"
F 10 "N" H 6250 2475 60  0001 C CNN "Critical"
F 11 "Shield_Headers" H 6250 2475 60  0001 C CNN "Subsystem"
F 12 "~" H 6250 2475 60  0001 C CNN "Notes"
	1    6250 2475
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR038
U 1 1 55E9684A
P 5925 2850
F 0 "#PWR038" H 5925 2850 30  0001 C CNN
F 1 "GND" H 5925 2780 30  0001 C CNN
F 2 "~" H 5925 2850 60  0000 C CNN
F 3 "~" H 5925 2850 60  0000 C CNN
F 4 "ANY" H 5925 2850 60  0001 C CNN "Source"
F 5 "N" H 5925 2850 60  0001 C CNN "Critical"
F 6 "~" H 5925 2850 60  0001 C CNN "Notes"
	1    5925 2850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5C579B64
P 5625 4925
F 0 "#PWR0101" H 5625 4675 50  0001 C CNN
F 1 "GND" H 5630 4752 50  0000 C CNN
F 2 "" H 5625 4925 50  0001 C CNN
F 3 "" H 5625 4925 50  0001 C CNN
	1    5625 4925
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 4300 4750 4300
Wire Wire Line
	6050 4500 4750 4500
Wire Wire Line
	6050 4600 4750 4600
$Comp
L Arduino_Uno_R3_From_Scratch-rescue:CONN_01X08 P2
U 1 1 5C79CCDA
P 6250 3425
F 0 "P2" H 6168 2850 50  0000 C CNN
F 1 "P2 Analog Header (AD)" H 6825 3400 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 6250 3425 60  0001 C CNN
F 3 "" H 6250 3425 60  0000 C CNN
	1    6250 3425
	1    0    0    1   
$EndComp
Wire Wire Line
	4800 3775 6050 3775
Wire Wire Line
	4800 3675 6050 3675
Wire Wire Line
	4800 3575 6050 3575
Wire Wire Line
	4800 3475 6050 3475
Wire Wire Line
	4825 3375 6050 3375
Wire Wire Line
	4825 3275 6050 3275
Text HLabel 4825 3175 0    50   Input ~ 0
ARD_AN6
Text HLabel 4825 3075 0    50   Input ~ 0
ARD_AN7
Wire Wire Line
	4825 3175 6050 3175
Wire Wire Line
	4825 3075 6050 3075
Wire Wire Line
	4750 5175 6050 5175
Wire Wire Line
	4750 5275 6050 5275
Wire Wire Line
	4750 5375 6050 5375
Wire Wire Line
	4750 5475 6050 5475
Wire Wire Line
	4750 5575 6050 5575
Wire Wire Line
	4750 5675 6050 5675
Wire Wire Line
	4750 4800 6050 4800
Wire Wire Line
	4750 4700 6050 4700
Wire Wire Line
	6050 4400 5625 4400
Wire Wire Line
	5625 4400 5625 4925
$Comp
L Arduino_Uno_R3_From_Scratch-rescue:CONN_01X06 P3
U 1 1 5C9A72A7
P 6250 4550
F 0 "P3" H 6168 4075 50  0000 C CNN
F 1 "Digital Header 02 (IOH) P3" H 6168 4166 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 6250 4550 60  0001 C CNN
F 3 "" H 6250 4550 60  0000 C CNN
	1    6250 4550
	1    0    0    1   
$EndComp
$Comp
L Arduino_Uno_R3_From_Scratch-rescue:CONN_01X06 P4
U 1 1 5C9A74BA
P 6250 5425
F 0 "P4" H 6328 5466 50  0000 L CNN
F 1 "Digital Header 01 (IOL)" H 6328 5375 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 6250 5425 60  0001 C CNN
F 3 "" H 6250 5425 60  0000 C CNN
	1    6250 5425
	1    0    0    -1  
$EndComp
Wire Wire Line
	5925 2225 6050 2225
Wire Wire Line
	5925 2850 5925 2725
Wire Wire Line
	5925 2725 6050 2725
Wire Wire Line
	5925 2725 5925 2625
Wire Wire Line
	5925 2625 6050 2625
Connection ~ 5925 2725
Wire Wire Line
	6050 2525 5400 2525
Wire Wire Line
	5400 2425 6050 2425
Wire Wire Line
	5400 1875 5400 2425
Connection ~ 5400 2425
Wire Wire Line
	5400 2425 5400 2525
Wire Wire Line
	5625 1875 5625 2325
Wire Wire Line
	5625 2325 6050 2325
$EndSCHEMATC
