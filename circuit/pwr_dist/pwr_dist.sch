EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
EELAYER 25 0
EELAYER END
$Descr User 7874 5906
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
	3000 2700 3000 2800
Wire Wire Line
	3000 2800 3300 2800
Wire Wire Line
	3100 2800 3100 2700
Wire Wire Line
	3400 2100 3700 2100
$Comp
L GND #PWR01
U 1 1 5BD13542
P 3050 2850
F 0 "#PWR01" H 3050 2600 50  0001 C CNN
F 1 "GND" H 3050 2700 50  0000 C CNN
F 2 "" H 3050 2850 50  0001 C CNN
F 3 "" H 3050 2850 50  0001 C CNN
	1    3050 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 2850 3050 2800
Connection ~ 3050 2800
$Comp
L D D1
U 1 1 5BD13588
P 3850 2100
F 0 "D1" H 3850 2200 50  0000 C CNN
F 1 "D" H 3850 2000 50  0000 C CNN
F 2 "Diodes_SMD:D_SMB_Handsoldering" H 3850 2100 50  0001 C CNN
F 3 "" H 3850 2100 50  0001 C CNN
	1    3850 2100
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X02 J1
U 1 1 5BD13746
P 4550 2150
F 0 "J1" H 4550 2300 50  0000 C CNN
F 1 "CONN_01X02" V 4650 2150 50  0000 C CNN
F 2 "Connectors:AK300-2" H 4550 2150 50  0001 C CNN
F 3 "" H 4550 2150 50  0001 C CNN
	1    4550 2150
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 J2
U 1 1 5BD13769
P 4550 2500
F 0 "J2" H 4550 2650 50  0000 C CNN
F 1 "CONN_01X02" V 4650 2500 50  0000 C CNN
F 2 "Connectors:AK300-2" H 4550 2500 50  0001 C CNN
F 3 "" H 4550 2500 50  0001 C CNN
	1    4550 2500
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 J3
U 1 1 5BD13796
P 4550 2800
F 0 "J3" H 4550 2950 50  0000 C CNN
F 1 "CONN_01X02" V 4650 2800 50  0000 C CNN
F 2 "Connectors:AK300-2" H 4550 2800 50  0001 C CNN
F 3 "" H 4550 2800 50  0001 C CNN
	1    4550 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 2100 4350 2100
Wire Wire Line
	4250 2100 4250 2750
Wire Wire Line
	4250 2750 4350 2750
Wire Wire Line
	4350 2450 4250 2450
Connection ~ 4250 2450
Wire Wire Line
	4350 2200 4150 2200
Wire Wire Line
	4150 2200 4150 2850
Wire Wire Line
	3300 2850 4350 2850
Wire Wire Line
	4350 2550 4150 2550
Connection ~ 4150 2550
Connection ~ 4250 2100
Wire Wire Line
	3300 2800 3300 2850
Connection ~ 3100 2800
Connection ~ 4150 2850
$Comp
L USB_B USB1
U 1 1 5BD13E13
P 3100 2300
F 0 "USB1" H 2900 2750 50  0000 L CNN
F 1 "USB_B" H 2900 2650 50  0000 L CNN
F 2 "Connectors:USB_B" H 3250 2250 50  0001 C CNN
F 3 "" H 3250 2250 50  0001 C CNN
	1    3100 2300
	1    0    0    -1  
$EndComp
$EndSCHEMATC
