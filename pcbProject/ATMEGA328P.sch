EESchema Schematic File Version 4
LIBS:Arduino_Uno_R3_From_Scratch-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 9 11
Title "Arduino UNO R3 Clone"
Date "8 oct 2015"
Rev "0"
Comp "Rheingold Heavy"
Comment1 "Based on the Arduino UNO R3 From arduino.cc"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	6675 4425 6675 4075
Wire Wire Line
	6675 3775 6675 3425
Text HLabel 3450 2750 0    40   Input ~ 0
AREF
$Comp
L power:GND #PWR040
U 1 1 55E8AA8C
P 3125 3700
F 0 "#PWR040" H 3125 3700 30  0001 C CNN
F 1 "GND" H 3125 3630 30  0001 C CNN
F 2 "~" H 3125 3700 60  0000 C CNN
F 3 "~" H 3125 3700 60  0000 C CNN
F 4 "ANY" H 3125 3700 60  0001 C CNN "Source"
F 5 "N" H 3125 3700 60  0001 C CNN "Critical"
F 6 "~" H 3125 3700 60  0001 C CNN "Notes"
	1    3125 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3525 3425 3525 3675
Text HLabel 5775 4150 2    40   Input ~ 0
ARD_AN5/SCL
Text HLabel 5775 4050 2    40   Input ~ 0
ARD_AN4/SDA
Text HLabel 5775 3950 2    40   Input ~ 0
ARD_AN3
Text HLabel 5775 3850 2    40   Input ~ 0
ARD_AN2
Text HLabel 5775 3750 2    40   Input ~ 0
ARD_AN1
Text HLabel 5775 3650 2    40   Input ~ 0
ARD_AN0
Text HLabel 5775 5150 2    40   Input ~ 0
ARD_DIG7
Text HLabel 5775 5050 2    40   Input ~ 0
ARD_DIG6
Text HLabel 5775 4950 2    40   Input ~ 0
ARD_DIG5
Text HLabel 5775 4850 2    40   Input ~ 0
ARD_DIG4
Text HLabel 5775 4750 2    40   Input ~ 0
ARD_DIG3
Text HLabel 5775 4650 2    40   Input ~ 0
ARD_DIG2
Text HLabel 5775 4550 2    40   Input ~ 0
ARD_DIG1
Text HLabel 5775 4450 2    40   Input ~ 0
ARD_DIG0
Text HLabel 5875 2750 2    40   Input ~ 0
ARD_DIG8
Text HLabel 5875 2850 2    40   Input ~ 0
ARD_DIG9
Text HLabel 5875 2950 2    40   Input ~ 0
ARD_DIG10/SPI_SS
Text HLabel 7150 2625 2    40   Input ~ 0
ARD_DIG11/SPI_MOSI
Text HLabel 7150 2875 2    40   Input ~ 0
ARD_DIG12/SPI_MISO
Text HLabel 7150 3300 2    40   Input ~ 0
ARD_DIG13/SPI_SCK
Text HLabel 9600 3975 2    40   Input ~ 0
328P_RESET
$Comp
L Arduino_Uno_R3_From_Scratch-rescue:CONN_02X03 ICSP2
U 1 1 55E8CAAE
P 9375 3050
F 0 "ICSP2" H 9375 3300 50  0000 C CNN
F 1 "M20-9980346" H 9375 2850 40  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x03_P2.54mm_Vertical" H 18550 650 60  0000 C CNN
F 3 "http://cdn.harwin.com/pdfs/M20-998.pdf" H 9375 3050 60  0001 C CNN
F 4 "6 CONTACT(S), MALE, STRAIGHT TWO PART BOARD CONNECTOR" H 9375 3050 60  0001 C CNN "Characteristics"
F 5 "ATMEGA328P ICSP Header" H 9375 3050 60  0001 C CNN "Description"
F 6 "Harwin" H 9375 3050 60  0001 C CNN "MFN"
F 7 "M20-9980346" H 9375 3050 60  0001 C CNN "MFP"
F 8 "PTH" H 9375 3050 60  0001 C CNN "Package ID"
F 9 "ANY" H 9375 3050 60  0001 C CNN "Source"
F 10 "N" H 9375 3050 60  0001 C CNN "Critical"
F 11 "328P_Sub" H 9375 3050 60  0001 C CNN "Subsystem"
F 12 "~" H 9375 3050 60  0001 C CNN "Notes"
	1    9375 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	10475 3550 10475 3700
Wire Wire Line
	9925 3150 9925 3300
Wire Wire Line
	9625 3150 9925 3150
Wire Wire Line
	8775 3150 9125 3150
Wire Wire Line
	8775 3050 9125 3050
Wire Wire Line
	8775 2950 9125 2950
Text GLabel 7125 3150 2    40   Input ~ 0
328P_ICSP_SCK
Text GLabel 7125 3000 2    40   Input ~ 0
328P_ICSP_MISO
Text GLabel 7125 2750 2    40   Input ~ 0
328P_ICSP_MOSI
Wire Wire Line
	7125 3150 7025 3150
Wire Wire Line
	7025 3150 7025 3250
Wire Wire Line
	7125 2750 7025 2750
Text GLabel 8775 3050 0    40   Input ~ 0
328P_ICSP_SCK
Text GLabel 8775 2950 0    40   Input ~ 0
328P_ICSP_MISO
Text GLabel 9875 2950 2    40   Input ~ 0
328P_ICSP_MOSI
$Comp
L Arduino_Uno_R3_From_Scratch:RESET_SWITCH SW1
U 1 1 55E8D514
P 8975 4175
F 0 "SW1" V 8825 4475 60  0000 C CNN
F 1 "RESET_SWITCH" V 9125 4725 60  0000 C CNN
F 2 "eigenfootprint:SW_SPST_PTS645_aangepast" H 8975 4175 60  0001 C CNN
F 3 "http://industrial.panasonic.com/www-data/pdf/ATK0000/ATK0000CE28.pdf" H 8975 4175 60  0001 C CNN
F 4 "SWITCH TACTILE SPST-NO 0.02A 15V" H 8975 4175 60  0001 C CNN "Characteristics"
F 5 "Reset Pushbutton" H 8975 4175 60  0001 C CNN "Description"
F 6 "Panasonic" H 8975 4175 60  0001 C CNN "MFN"
F 7 "EVQ-Q2U02W" H 8975 4175 60  0001 C CNN "MFP"
F 8 "SMD" H 8975 4175 60  0001 C CNN "Package ID"
F 9 "ANY" H 8975 4175 60  0001 C CNN "Source"
F 10 "N" H 8975 4175 60  0001 C CNN "Critical"
F 11 "328P_Sub" H 8975 4175 60  0001 C CNN "Subsystem"
F 12 "Prefer below 3mm in accuator height off PCB" H 8975 4175 60  0001 C CNN "Notes"
	1    8975 4175
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8975 3700 8975 3850
Connection ~ 8975 3700
Wire Wire Line
	8975 4475 8975 4625
Connection ~ 8975 3850
Connection ~ 8975 4475
Wire Wire Line
	8775 3150 8775 3700
$Comp
L Arduino_Uno_R3_From_Scratch:5V_LDO #PWR041
U 1 1 55E95BB4
P 10475 2850
F 0 "#PWR041" H 10475 2940 20  0001 C CNN
F 1 "5V_LDO" H 10475 2970 30  0000 C CNN
F 2 "~" H 10475 2850 60  0000 C CNN
F 3 "~" H 10475 2850 60  0000 C CNN
	1    10475 2850
	1    0    0    -1  
$EndComp
$Comp
L Arduino_Uno_R3_From_Scratch:5V_LDO #PWR042
U 1 1 55E95BC3
P 4050 2300
F 0 "#PWR042" H 4050 2390 20  0001 C CNN
F 1 "5V_LDO" H 4075 2450 30  0000 C CNN
F 2 "~" H 4050 2300 60  0000 C CNN
F 3 "~" H 4050 2300 60  0000 C CNN
	1    4050 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7025 4425 6675 4425
Wire Wire Line
	7025 3425 6675 3425
Text Notes 7025 1050 0    40   ~ 0
Atmel Appnote: AVR042 - AVR Hardware Design Considerations\nhttp://www.atmel.com/Images/Atmel-2521-AVR-Hardware-Design-Considerations_ApplicationNote_AVR042.pdf\n\nRefer to this for PCB layout information
$Comp
L Device:C C14
U 1 1 56159BB8
P 3525 3275
F 0 "C14" H 3575 3375 40  0000 L CNN
F 1 "0.1 uF" H 3575 3175 40  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 4525 -225 30  0000 C CNN
F 3 "http://images.ihscontent.net/vipimages/VipMasterIC/IC/KEME/KEMES10043/KEMES10043-1.pdf" H 3525 3275 60  0001 C CNN
F 4 "CAPACITOR, CERAMIC, MULTILAYER, 100 V, X7R, 0.1 uF, SURFACE MOUNT, 0805, CHIP, ROHS COMPLIANT" H 3525 3275 60  0001 C CNN "Characteristics"
F 5 "ATMEGA328P AREF Bypass Cap" H 3525 3275 60  0001 C CNN "Description"
F 6 "Kemet" H 3525 3275 60  0001 C CNN "MFN"
F 7 "C0805C104K1RACAUTO" H 3525 3275 60  0001 C CNN "MFP"
F 8 "SMD_0805" H 3525 3275 60  0001 C CNN "Package ID"
F 9 "ANY" H 3525 3275 60  0001 C CNN "Source"
F 10 "N" H 3525 3275 60  0001 C CNN "Critical"
F 11 "328P_Sub" H 3525 3275 60  0001 C CNN "Subsystem"
F 12 "~" H 3525 3275 60  0001 C CNN "Notes"
	1    3525 3275
	1    0    0    -1  
$EndComp
$Comp
L Device:C C15
U 1 1 56159BD3
P 3125 3275
F 0 "C15" H 3175 3375 40  0000 L CNN
F 1 "0.1 uF" H 3175 3175 40  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 5025 -425 30  0000 C CNN
F 3 "http://images.ihscontent.net/vipimages/VipMasterIC/IC/KEME/KEMES10043/KEMES10043-1.pdf" H 3125 3275 60  0001 C CNN
F 4 "CAPACITOR, CERAMIC, MULTILAYER, 100 V, X7R, 0.1 uF, SURFACE MOUNT, 0805, CHIP, ROHS COMPLIANT" H 3125 3275 60  0001 C CNN "Characteristics"
F 5 "ATMEGA328P VCC and AVCC Bypass Cap" H 3125 3275 60  0001 C CNN "Description"
F 6 "Kemet" H 3125 3275 60  0001 C CNN "MFN"
F 7 "C0805C104K1RACAUTO" H 3125 3275 60  0001 C CNN "MFP"
F 8 "SMD_0805" H 3125 3275 60  0001 C CNN "Package ID"
F 9 "ANY" H 3125 3275 60  0001 C CNN "Source"
F 10 "N" H 3125 3275 60  0001 C CNN "Critical"
F 11 "328P_Sub" H 3125 3275 60  0001 C CNN "Subsystem"
F 12 "~" H 3125 3275 60  0001 C CNN "Notes"
	1    3125 3275
	1    0    0    -1  
$EndComp
$Comp
L Device:R R16
U 1 1 56159EEE
P 10475 3400
F 0 "R16" V 10555 3400 40  0000 C CNN
F 1 "10K" V 10482 3401 40  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 2675 3825 30  0000 C CNN
F 3 "http://images.ihscontent.net/vipimages/VipMasterIC/IC/VISH/VISHS75859/VISHS75859-1.pdf" H 10475 3400 30  0001 C CNN
F 4 "RESISTOR, METAL GLAZE/THICK FILM, 0.125W, 5%, 200ppm, 10000ohm, SURFACE MOUNT, 0805" H 10475 3400 60  0001 C CNN "Characteristics"
F 5 "ATMEGA328P 10K ICSP Pull Up" H 10475 3400 60  0001 C CNN "Description"
F 6 "Vishay" H 10475 3400 60  0001 C CNN "MFN"
F 7 "CRCW080510K0JNEA" H 10475 3400 60  0001 C CNN "MFP"
F 8 "SMD_0805" H 10475 3400 60  0001 C CNN "Package ID"
F 9 "ANY" H 10475 3400 60  0001 C CNN "Source"
F 10 "N" H 10475 3400 60  0001 C CNN "Critical"
F 11 "328P_Sub" H 10475 3400 60  0001 C CNN "Subsystem"
F 12 "~" H 10475 3400 60  0001 C CNN "Notes"
	1    10475 3400
	-1   0    0    1   
$EndComp
$Comp
L Device:R R17
U 1 1 5615BCD3
P 6675 3925
F 0 "R17" H 6750 3875 40  0000 L CNN
F 1 "1M" V 6675 3925 40  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 1925 5075 30  0000 C CNN
F 3 "http://www.vishay.com/docs/20035/dcrcwe3.pdf" H 6675 3925 30  0001 C CNN
F 4 "RES SMD 1M OHM 1% 1/8W 0805" H 6675 3925 60  0001 C CNN "Characteristics"
F 5 "ATMEGA328P Xtal 1M Feedback Resistor" H 6675 3925 60  0001 C CNN "Description"
F 6 "Vishay" H 6675 3925 60  0001 C CNN "MFN"
F 7 "CRCW08051M00FKEA" H 6675 3925 60  0001 C CNN "MFP"
F 8 "SMD_0805" H 6675 3925 60  0001 C CNN "Package ID"
F 9 "ANY" H 6675 3925 60  0001 C CNN "Source"
F 10 "N" H 6675 3925 60  0001 C CNN "Critical"
F 11 "328P_Sub" H 6675 3925 60  0001 C CNN "Subsystem"
F 12 "~" H 6675 3925 60  0001 C CNN "Notes"
	1    6675 3925
	-1   0    0    1   
$EndComp
Wire Wire Line
	9075 3850 9075 3975
Wire Wire Line
	8875 3850 8975 3850
Wire Wire Line
	8875 3975 8875 3850
Wire Wire Line
	9075 4475 9075 4375
Wire Wire Line
	8875 4475 8975 4475
Wire Wire Line
	8875 4475 8875 4375
$Comp
L power:GND #PWR043
U 1 1 562077A6
P 3525 3675
F 0 "#PWR043" H 3525 3675 30  0001 C CNN
F 1 "GND" H 3525 3605 30  0001 C CNN
F 2 "~" H 3525 3675 60  0000 C CNN
F 3 "~" H 3525 3675 60  0000 C CNN
F 4 "ANY" H 3525 3675 60  0001 C CNN "Source"
F 5 "N" H 3525 3675 60  0001 C CNN "Critical"
F 6 "~" H 3525 3675 60  0001 C CNN "Notes"
	1    3525 3675
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR045
U 1 1 562079B8
P 8975 4625
F 0 "#PWR045" H 8975 4625 30  0001 C CNN
F 1 "GND" H 8975 4555 30  0001 C CNN
F 2 "~" H 8975 4625 60  0000 C CNN
F 3 "~" H 8975 4625 60  0000 C CNN
F 4 "ANY" H 8975 4625 60  0001 C CNN "Source"
F 5 "N" H 8975 4625 60  0001 C CNN "Critical"
F 6 "~" H 8975 4625 60  0001 C CNN "Notes"
	1    8975 4625
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR047
U 1 1 56208C49
P 9925 3300
F 0 "#PWR047" H 9925 3300 30  0001 C CNN
F 1 "GND" H 9925 3230 30  0001 C CNN
F 2 "~" H 9925 3300 60  0000 C CNN
F 3 "~" H 9925 3300 60  0000 C CNN
F 4 "ANY" H 9925 3300 60  0001 C CNN "Source"
F 5 "N" H 9925 3300 60  0001 C CNN "Critical"
F 6 "~" H 9925 3300 60  0001 C CNN "Notes"
	1    9925 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8775 3700 8975 3700
Wire Wire Line
	8975 3700 9500 3700
Wire Wire Line
	8975 3850 9075 3850
Wire Wire Line
	8975 4475 9075 4475
Wire Wire Line
	4825 2350 4825 2450
Wire Wire Line
	4825 2350 4925 2350
Wire Wire Line
	4925 2350 4925 2450
$Comp
L power:GND #PWR03
U 1 1 5C83660C
P 4825 5575
F 0 "#PWR03" H 4825 5325 50  0001 C CNN
F 1 "GND" H 4830 5402 50  0000 C CNN
F 2 "" H 4825 5575 50  0001 C CNN
F 3 "" H 4825 5575 50  0001 C CNN
	1    4825 5575
	1    0    0    -1  
$EndComp
Wire Wire Line
	4825 2350 4050 2350
Connection ~ 4825 2350
Connection ~ 6675 4425
Wire Wire Line
	5425 2950 5875 2950
Wire Wire Line
	5425 2850 5875 2850
Wire Wire Line
	5425 2750 5875 2750
Wire Wire Line
	5425 4150 5775 4150
Wire Wire Line
	5425 3650 5775 3650
Wire Wire Line
	5425 3750 5775 3750
Wire Wire Line
	5425 3850 5775 3850
Wire Wire Line
	5425 3950 5775 3950
Wire Wire Line
	5425 4050 5775 4050
Wire Wire Line
	5425 4450 5775 4450
Wire Wire Line
	5425 4550 5775 4550
Wire Wire Line
	5425 4650 5775 4650
Wire Wire Line
	5425 4750 5775 4750
Wire Wire Line
	5425 4850 5775 4850
Wire Wire Line
	5425 4950 5775 4950
Wire Wire Line
	5425 5050 5775 5050
Wire Wire Line
	5425 5150 5775 5150
Wire Wire Line
	3125 3700 3125 3425
Text HLabel 4000 2950 0    40   Input ~ 0
ARD_AN6
Text HLabel 4000 3050 0    40   Input ~ 0
ARD_AN7
Wire Wire Line
	4000 2950 4225 2950
Wire Wire Line
	4000 3050 4225 3050
$Comp
L Device:Crystal Y1
U 1 1 5C9F065B
P 7025 3925
F 0 "Y1" V 6979 4056 50  0000 L CNN
F 1 "CSTCE16MOV53-R0" V 7150 4025 50  0000 L CNN
F 2 "Crystal:Crystal_SMD_HC49-SD" H 7025 3925 50  0001 C CNN
F 3 "~" H 7025 3925 50  0001 C CNN
	1    7025 3925
	0    1    1    0   
$EndComp
Wire Wire Line
	7025 4075 7025 4150
Wire Wire Line
	7025 3425 7025 3775
$Comp
L Device:C C20
U 1 1 5C89A715
P 7425 4300
F 0 "C20" H 7540 4346 50  0000 L CNN
F 1 "22p" H 7540 4255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7463 4150 50  0001 C CNN
F 3 "~" H 7425 4300 50  0001 C CNN
	1    7425 4300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C19
U 1 1 5C89A779
P 7425 3575
F 0 "C19" H 7540 3621 50  0000 L CNN
F 1 "22p" H 7540 3530 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7463 3425 50  0001 C CNN
F 3 "~" H 7425 3575 50  0001 C CNN
	1    7425 3575
	1    0    0    -1  
$EndComp
Wire Wire Line
	7025 3425 7425 3425
Connection ~ 7025 3425
Wire Wire Line
	7025 4150 7425 4150
Connection ~ 7025 4150
Wire Wire Line
	7025 4150 7025 4425
$Comp
L power:GND #PWR09
U 1 1 5C89ED8F
P 7425 4500
F 0 "#PWR09" H 7425 4250 50  0001 C CNN
F 1 "GND" H 7430 4327 50  0000 C CNN
F 2 "" H 7425 4500 50  0001 C CNN
F 3 "" H 7425 4500 50  0001 C CNN
	1    7425 4500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5C89EDC5
P 7425 3775
F 0 "#PWR08" H 7425 3525 50  0001 C CNN
F 1 "GND" H 7430 3602 50  0000 C CNN
F 2 "" H 7425 3775 50  0001 C CNN
F 3 "" H 7425 3775 50  0001 C CNN
	1    7425 3775
	1    0    0    -1  
$EndComp
Wire Wire Line
	7425 3775 7425 3725
Wire Wire Line
	7425 4500 7425 4450
Wire Wire Line
	10475 2850 10475 3050
Wire Wire Line
	9875 2950 9625 2950
Wire Wire Line
	9625 3050 10475 3050
Connection ~ 10475 3050
Wire Wire Line
	10475 3050 10475 3250
Wire Wire Line
	3525 2750 3525 3125
Wire Wire Line
	3525 2750 4225 2750
Wire Wire Line
	3450 2750 3525 2750
Connection ~ 3525 2750
Wire Wire Line
	3125 2350 3125 3125
Wire Wire Line
	4050 2300 4050 2350
Connection ~ 4050 2350
Wire Wire Line
	4050 2350 3125 2350
Wire Wire Line
	6650 3050 5425 3050
Wire Wire Line
	6775 3150 5425 3150
Wire Wire Line
	5425 3250 7025 3250
Wire Wire Line
	7025 3350 7025 3425
Wire Wire Line
	6475 3450 6475 4425
Wire Wire Line
	6475 4425 6675 4425
$Comp
L MCU_Microchip_ATmega:ATmega328P-AU U2
U 1 1 5C76D532
P 4825 3950
F 0 "U2" H 4600 2450 50  0000 C CNN
F 1 "ATmega328P-AU" H 5325 2450 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 4825 3950 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 4825 3950 50  0001 C CNN
	1    4825 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7025 3350 5425 3350
Wire Wire Line
	5425 3450 6475 3450
Wire Wire Line
	7025 2750 7025 2675
Wire Wire Line
	7025 2625 7150 2625
Wire Wire Line
	6650 2675 7025 2675
Wire Wire Line
	6650 2675 6650 3050
Connection ~ 7025 2675
Wire Wire Line
	7025 2675 7025 2625
Wire Wire Line
	6775 3000 6775 3150
Wire Wire Line
	6775 3000 7025 3000
Wire Wire Line
	7150 2875 7025 2875
Wire Wire Line
	7025 2875 7025 3000
Connection ~ 7025 3000
Wire Wire Line
	7025 3000 7125 3000
Connection ~ 7025 3250
Wire Wire Line
	7025 3300 7150 3300
Wire Wire Line
	7025 3250 7025 3300
Wire Wire Line
	5425 4250 6300 4250
Wire Wire Line
	6300 4250 6300 4750
Wire Wire Line
	6300 4750 8000 4750
Wire Wire Line
	8000 4750 8000 3700
Wire Wire Line
	8775 3700 8000 3700
Connection ~ 8775 3700
Wire Wire Line
	9600 3975 9500 3975
Wire Wire Line
	9500 3975 9500 3700
Connection ~ 9500 3700
Wire Wire Line
	9500 3700 10475 3700
Wire Wire Line
	4825 5575 4825 5450
$EndSCHEMATC
