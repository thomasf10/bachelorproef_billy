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
L Arduino_Uno_R3_From_Scratch:3V3_LDO #PWR036
U 1 1 55E95D89
P 5700 2825
F 0 "#PWR036" H 5700 2785 30  0001 C CNN
F 1 "3V3_LDO" H 5700 2945 30  0000 C CNN
F 2 "~" H 5700 2825 60  0000 C CNN
F 3 "~" H 5700 2825 60  0000 C CNN
	1    5700 2825
	1    0    0    -1  
$EndComp
Text HLabel 5850 3725 0    40   Input ~ 0
ARD_AN3
Text HLabel 5850 3825 0    40   Input ~ 0
ARD_AN2
Text HLabel 5850 3925 0    40   Input ~ 0
ARD_AN1
Text HLabel 5850 4025 0    40   Input ~ 0
ARD_AN0
Text HLabel 5850 5575 0    40   Input ~ 0
ARD_DIG7
Text HLabel 5850 5475 0    40   Input ~ 0
ARD_DIG4
Text HLabel 5850 5375 0    40   Input ~ 0
ARD_DIG2
Text HLabel 5850 5275 0    40   Input ~ 0
ARD_DIG1
Text HLabel 5850 5175 0    40   Input ~ 0
ARD_DIG0
Text HLabel 5875 3625 0    40   Input ~ 0
ARD_AN4/SDA
Text HLabel 5875 3525 0    40   Input ~ 0
ARD_AN5/SCL
Text HLabel 5850 5675 0    40   Input ~ 0
ARD_DIG8
Text HLabel 5850 4800 0    40   Input ~ 0
ARD_DIG10/SPI_SS
Text HLabel 5850 4700 0    40   Input ~ 0
ARD_DIG11/SPI_MOSI
Text HLabel 5850 4600 0    40   Input ~ 0
ARD_DIG12/SPI_MISO
Text HLabel 5850 4500 0    40   Input ~ 0
ARD_DIG13/SPI_SCK
Text HLabel 5850 4300 0    40   Input ~ 0
AREF
$Comp
L Arduino_Uno_R3_From_Scratch-rescue:CONN_01X08 P2
U 1 1 5C79CCDA
P 6200 3675
F 0 "P2" H 6118 3100 50  0000 C CNN
F 1 "P2 Analog Header (AD)" H 6775 3650 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 6200 3675 60  0001 C CNN
F 3 "" H 6200 3675 60  0000 C CNN
	1    6200 3675
	1    0    0    1   
$EndComp
Text HLabel 5875 3425 0    50   Input ~ 0
ARD_AN6
Text HLabel 5875 3325 0    50   Input ~ 0
ARD_AN7
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
Connection ~ 5925 2675
$Comp
L Connector:Conn_01x04_Female J3
U 1 1 5C8FAAAF
P 6200 2675
F 0 "J3" H 6228 2651 50  0000 L CNN
F 1 "3v3" H 6228 2560 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 6200 2675 50  0001 C CNN
F 3 "~" H 6200 2675 50  0001 C CNN
	1    6200 2675
	1    0    0    -1  
$EndComp
Wire Wire Line
	5925 2575 5925 2675
$Comp
L Connector:Conn_01x05_Female J4
U 1 1 5C8FCBE2
P 6250 4600
F 0 "J4" H 6278 4626 50  0000 L CNN
F 1 "Digital Header 02 (IOH)" H 6278 4535 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x05_P2.54mm_Vertical" H 6250 4600 50  0001 C CNN
F 3 "~" H 6250 4600 50  0001 C CNN
	1    6250 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 4300 6050 4400
Wire Wire Line
	5700 2825 5700 2875
Wire Wire Line
	5700 2875 5925 2875
Wire Wire Line
	5875 3325 6000 3325
Wire Wire Line
	5875 3425 6000 3425
Wire Wire Line
	5875 3525 6000 3525
Wire Wire Line
	5875 3625 6000 3625
Wire Wire Line
	5850 3725 6000 3725
Wire Wire Line
	5850 3825 6000 3825
Wire Wire Line
	5850 3925 6000 3925
Wire Wire Line
	5850 4025 6000 4025
Wire Wire Line
	5850 4300 6050 4300
Wire Wire Line
	5850 4500 6050 4500
Wire Wire Line
	5850 4600 6050 4600
Wire Wire Line
	5850 4700 6050 4700
Wire Wire Line
	5850 4800 6050 4800
Wire Wire Line
	5850 5175 6050 5175
Wire Wire Line
	5850 5275 6050 5275
Wire Wire Line
	5850 5375 6050 5375
Wire Wire Line
	5850 5475 6050 5475
Wire Wire Line
	5850 5575 6050 5575
Wire Wire Line
	5850 5675 6050 5675
Wire Wire Line
	5925 2675 5925 2775
Wire Wire Line
	5925 2575 6000 2575
Wire Wire Line
	5925 2675 6000 2675
Wire Wire Line
	5925 2775 6000 2775
Connection ~ 5925 2775
Wire Wire Line
	5925 2775 5925 2875
Wire Wire Line
	5925 2875 6000 2875
Connection ~ 5925 2875
$EndSCHEMATC
