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
LIBS:sensorlaser-cache
EELAYER 25 0
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
L CONN_01X04 J-SENMOUNT1
U 1 1 59DD6908
P 4600 2550
F 0 "J-SENMOUNT1" H 4600 2800 50  0000 C CNN
F 1 "CONN_01X04" V 4700 2550 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x04_Pitch2.54mm" H 4600 2550 50  0001 C CNN
F 3 "" H 4600 2550 50  0001 C CNN
	1    4600 2550
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X02 J-SENMOUNT2
U 1 1 59DD69FB
P 5600 2500
F 0 "J-SENMOUNT2" H 5600 2650 50  0000 C CNN
F 1 "CONN_01X02" V 5700 2500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 5600 2500 50  0001 C CNN
F 3 "" H 5600 2500 50  0001 C CNN
	1    5600 2500
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X02 J-SENMOUNT3
U 1 1 59DD6A3A
P 5600 2900
F 0 "J-SENMOUNT3" H 5600 3050 50  0000 C CNN
F 1 "CONN_01X02" V 5700 2900 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 5600 2900 50  0001 C CNN
F 3 "" H 5600 2900 50  0001 C CNN
	1    5600 2900
	-1   0    0    1   
$EndComp
Wire Wire Line
	4800 2400 4950 2400
Wire Wire Line
	4800 2500 4950 2500
Wire Wire Line
	4800 2600 4950 2600
Wire Wire Line
	4800 2700 4950 2700
Text Label 4950 2400 0    60   ~ 0
VSEN+
Text Label 4950 2500 0    60   ~ 0
IN-
Text Label 4950 2600 0    60   ~ 0
IN+
Text Label 4950 2700 0    60   ~ 0
VSEN-
Wire Wire Line
	5800 2450 5950 2450
Wire Wire Line
	5800 2550 5950 2550
Text Label 5950 2450 0    60   ~ 0
VSEN+
Text Label 5950 2550 0    60   ~ 0
VSEN-
Wire Wire Line
	5800 2850 5950 2850
Wire Wire Line
	5800 2950 5950 2950
Text Label 5950 2850 0    60   ~ 0
IN+
Text Label 5950 2950 0    60   ~ 0
IN-
$EndSCHEMATC
