EESchema Schematic File Version 4
LIBS:Arduino_Uno_R3_From_Scratch-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 11
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
L Arduino_Uno_R3_From_Scratch-rescue:LP2985LV U3
U 1 1 55D1286F
P 7000 4500
F 0 "U3" H 7200 4050 60  0000 C CNN
F 1 "LP2985-33DBVR" H 7000 4950 60  0000 C CNN
F 2 "~" H 7000 4500 60  0000 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lp2985-33.pdf" H 7000 4500 60  0001 C CNN
F 4 "3.3V FIXED POSITIVE LDO REGULATOR, 0.575V DROPOUT" H 7000 4500 60  0001 C CNN "Characteristics"
F 5 "3V3 Fixed LDO Regulator" H 7000 4500 60  0001 C CNN "Description"
F 6 "Texas Instruments" H 7000 4500 60  0001 C CNN "MFN"
F 7 "LP2985-33DBVR" H 7000 4500 60  0001 C CNN "MFP"
F 8 "SOT-23 5" H 7000 4500 60  0001 C CNN "Package ID"
F 9 "ANY" H 7000 4500 60  0001 C CNN "Source"
F 10 "N" H 7000 4500 60  0001 C CNN "Critical"
F 11 "Voltage_Mgmt" H 7000 4500 60  0001 C CNN "Subsystem"
F 12 "~" H 7000 4500 60  0001 C CNN "Notes"
	1    7000 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 4200 5900 4400
Wire Wire Line
	5900 4400 6200 4400
Connection ~ 5900 4200
Wire Wire Line
	7000 5200 7000 5325
NoConn ~ 6200 4700
$Comp
L Device:C C6
U 1 1 55D12923
P 8000 4600
F 0 "C6" H 8000 4700 40  0000 L CNN
F 1 "2.2uF" H 8006 4515 40  0000 L CNN
F 2 "~" H 8038 4450 30  0000 C CNN
F 3 "http://product.tdk.com/en/catalog/datasheets/mlcc_commercial_general_en.pdf" H 8000 4600 60  0001 C CNN
F 4 "CAP CER 2.2UF 16V X7R 0805" H 8000 4600 60  0001 C CNN "Characteristics"
F 5 "2.2uF 3V3 LDO Output Cap" H 8000 4600 60  0001 C CNN "Description"
F 6 "TDK Corporation" H 8000 4600 60  0001 C CNN "MFN"
F 7 "C2012X7R1C225K125AB" H 8000 4600 60  0001 C CNN "MFP"
F 8 "SMD_0805" H 8000 4600 60  0001 C CNN "Package ID"
F 9 "ANY" H 8000 4600 60  0001 C CNN "Source"
F 10 "Y" H 8000 4600 60  0001 C CNN "Critical"
F 11 "Voltage_Mgmt" H 8000 4600 60  0001 C CNN "Subsystem"
F 12 "Must be between 0.001 and 1Ω ESR" H 8000 4600 60  0001 C CNN "Notes"
	1    8000 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 4200 8000 4200
Wire Wire Line
	8000 4000 8000 4200
Wire Wire Line
	8000 4750 8000 5325
Connection ~ 8000 4200
Wire Notes Line
	2650 2500 2650 2150
Wire Notes Line
	2650 2150 8000 2150
Wire Notes Line
	8000 2150 8000 2450
Wire Wire Line
	5400 3700 5400 4200
Text Notes 4450 2100 0    60   ~ 0
USBVCC / VIN Comparator
$Comp
L Arduino_Uno_R3_From_Scratch:3V3_LDO #PWR013
U 1 1 55E95795
P 8000 4000
F 0 "#PWR013" H 8000 3960 30  0001 C CNN
F 1 "3V3_LDO" H 8000 4120 30  0000 C CNN
F 2 "~" H 8000 4000 60  0000 C CNN
F 3 "~" H 8000 4000 60  0000 C CNN
	1    8000 4000
	1    0    0    -1  
$EndComp
$Comp
L Arduino_Uno_R3_From_Scratch:5V_LDO #PWR014
U 1 1 55E957AE
P 5400 3700
F 0 "#PWR014" H 5400 3790 20  0001 C CNN
F 1 "5V_LDO" H 5400 3820 30  0000 C CNN
F 2 "~" H 5400 3700 60  0000 C CNN
F 3 "~" H 5400 3700 60  0000 C CNN
	1    5400 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR019
U 1 1 561FE596
P 7000 5325
F 0 "#PWR019" H 7000 5325 30  0001 C CNN
F 1 "GND" H 7000 5255 30  0001 C CNN
F 2 "~" H 7000 5325 60  0000 C CNN
F 3 "~" H 7000 5325 60  0000 C CNN
F 4 "ANY" H 7000 5325 60  0001 C CNN "Source"
F 5 "N" H 7000 5325 60  0001 C CNN "Critical"
F 6 "~" H 7000 5325 60  0001 C CNN "Notes"
	1    7000 5325
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR020
U 1 1 561FE5BF
P 8000 5325
F 0 "#PWR020" H 8000 5325 30  0001 C CNN
F 1 "GND" H 8000 5255 30  0001 C CNN
F 2 "~" H 8000 5325 60  0000 C CNN
F 3 "~" H 8000 5325 60  0000 C CNN
F 4 "ANY" H 8000 5325 60  0001 C CNN "Source"
F 5 "N" H 8000 5325 60  0001 C CNN "Critical"
F 6 "~" H 8000 5325 60  0001 C CNN "Notes"
	1    8000 5325
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 4200 6200 4200
Wire Wire Line
	8000 4200 8000 4450
Wire Wire Line
	5400 4200 5900 4200
$EndSCHEMATC
