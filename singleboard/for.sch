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
LIBS:stm32
LIBS:ftdi
LIBS:switches
LIBS:adafruit2
LIBS:switch
LIBS:for-cache
EELAYER 25 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 1
Title "Fiber-Optic Respirometer Interface"
Date "2017-01-30"
Rev "5"
Comp "Optical Lab of Physic Engineering ITS"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L STM32F103VETx U2
U 1 1 5885EE71
P 8800 5550
F 0 "U2" H 6100 8375 50  0000 L BNN
F 1 "STM32F103VETx" H 11500 8375 50  0000 R BNN
F 2 "Housings_QFP:LQFP-100_14x14mm_Pitch0.5mm" H 11500 8325 50  0001 R TNN
F 3 "" H 8800 5550 50  0000 C CNN
	1    8800 5550
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR01
U 1 1 5885F1B7
P 9100 2550
F 0 "#PWR01" H 9100 2400 50  0001 C CNN
F 1 "VDD" H 9100 2700 50  0000 C CNN
F 2 "" H 9100 2550 50  0000 C CNN
F 3 "" H 9100 2550 50  0000 C CNN
	1    9100 2550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5885F2D1
P 9100 8450
F 0 "#PWR02" H 9100 8200 50  0001 C CNN
F 1 "GND" H 9100 8300 50  0000 C CNN
F 2 "" H 9100 8450 50  0000 C CNN
F 3 "" H 9100 8450 50  0000 C CNN
	1    9100 8450
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X16 P-LCD1
U 1 1 5885F43A
P 13400 3450
F 0 "P-LCD1" H 13400 4300 50  0000 C CNN
F 1 "CONN_02X16" V 13400 3450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x16" H 13400 2350 50  0001 C CNN
F 3 "" H 13400 2350 50  0000 C CNN
	1    13400 3450
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 5885F6D4
P 13850 2600
F 0 "#PWR03" H 13850 2350 50  0001 C CNN
F 1 "GND" H 13850 2450 50  0000 C CNN
F 2 "" H 13850 2600 50  0000 C CNN
F 3 "" H 13850 2600 50  0000 C CNN
	1    13850 2600
	-1   0    0    1   
$EndComp
Text Label 12950 2700 0    60   ~ 0
LCD_RST
Text Label 13850 2800 0    60   ~ 0
LCD_D15
Text Label 12950 2800 0    60   ~ 0
LCD_D14
Text Label 13850 2900 0    60   ~ 0
LCD_D13
Text Label 12950 2900 0    60   ~ 0
LCD_D12
Text Label 13850 3000 0    60   ~ 0
LCD_D11
Text Label 12950 3000 0    60   ~ 0
LCD_D10
Text Label 13850 3100 0    60   ~ 0
LCD_D9
Text Label 12950 3100 0    60   ~ 0
LCD_D8
Text Label 13850 3200 0    60   ~ 0
LCD_D7
Text Label 12950 3200 0    60   ~ 0
LCD_D6
Text Label 13850 3300 0    60   ~ 0
LCD_D5
Text Label 12950 3300 0    60   ~ 0
LCD_D4
Text Label 13850 3400 0    60   ~ 0
LCD_D3
Text Label 12950 3400 0    60   ~ 0
LCD_D2
Text Label 13850 3500 0    60   ~ 0
LCD_D1
Text Label 12950 3500 0    60   ~ 0
LCD_D0
Text Label 13850 3600 0    60   ~ 0
LCD_RD
Text Label 12950 3600 0    60   ~ 0
LCD_WR
Text Label 13850 3700 0    60   ~ 0
LCD_RS
Text Label 12950 3700 0    60   ~ 0
LCD_CS
Text Label 13850 3800 0    60   ~ 0
TIN_TCK
Text Label 13850 3900 0    60   ~ 0
TIN_MOSI
Text Label 13850 4000 0    60   ~ 0
TIN_INT
Text Label 12950 3800 0    60   ~ 0
TIN_CS
Text Label 12950 3900 0    60   ~ 0
TIN_MISO
Text Label 12950 4000 0    60   ~ 0
LCD_BL
$Comp
L VCC #PWR04
U 1 1 58860A4F
P 14300 4050
F 0 "#PWR04" H 14300 3900 50  0001 C CNN
F 1 "VCC" H 14300 4200 50  0000 C CNN
F 2 "" H 14300 4050 50  0000 C CNN
F 3 "" H 14300 4050 50  0000 C CNN
	1    14300 4050
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR05
U 1 1 58860A67
P 14450 4050
F 0 "#PWR05" H 14450 3900 50  0001 C CNN
F 1 "VDD" H 14450 4200 50  0000 C CNN
F 2 "" H 14450 4050 50  0000 C CNN
F 3 "" H 14450 4050 50  0000 C CNN
	1    14450 4050
	1    0    0    -1  
$EndComp
Text Label 12950 4100 0    60   ~ 0
PC2
$Comp
L GND #PWR06
U 1 1 58860BC5
P 12950 4200
F 0 "#PWR06" H 12950 3950 50  0001 C CNN
F 1 "GND" H 12950 4050 50  0000 C CNN
F 2 "" H 12950 4200 50  0000 C CNN
F 3 "" H 12950 4200 50  0000 C CNN
	1    12950 4200
	1    0    0    -1  
$EndComp
Text Label 5600 4850 0    60   ~ 0
LCD_RST
Text Label 5600 7450 0    60   ~ 0
LCD_D15
Text Label 5600 7350 0    60   ~ 0
LCD_D14
Text Label 5600 7250 0    60   ~ 0
LCD_D13
Text Label 5650 6250 0    60   ~ 0
LCD_D12
Text Label 5650 6150 0    60   ~ 0
LCD_D11
Text Label 5650 6050 0    60   ~ 0
LCD_D10
Text Label 5650 5950 0    60   ~ 0
LCD_D9
Text Label 5650 5850 0    60   ~ 0
LCD_D8
Text Label 5650 5750 0    60   ~ 0
LCD_D7
Text Label 5650 5650 0    60   ~ 0
LCD_D6
Text Label 5650 5550 0    60   ~ 0
LCD_D5
Text Label 5650 5450 0    60   ~ 0
LCD_D4
Text Label 5600 6550 0    60   ~ 0
LCD_D3
Text Label 5600 6450 0    60   ~ 0
LCD_D2
Text Label 5600 7950 0    60   ~ 0
LCD_D1
Text Label 5600 7850 0    60   ~ 0
LCD_D0
Text Label 5600 6950 0    60   ~ 0
LCD_WR
Text Label 5600 6850 0    60   ~ 0
LCD_RD
Text Label 5600 7550 0    60   ~ 0
LCD_RS
Text Label 5600 7150 0    60   ~ 0
LCD_CS
Text Label 11950 3550 0    60   ~ 0
TIN_TCK
Text Label 11950 3650 0    60   ~ 0
TIN_MISO
Text Label 11950 3750 0    60   ~ 0
TIN_MOSI
Text Label 11950 5350 0    60   ~ 0
TIN_INT
Text Label 11950 5450 0    60   ~ 0
TIN_CS
Text Label 5600 7750 0    60   ~ 0
LCD_BL
Text Label 11950 6650 0    60   ~ 0
PC2
$Comp
L GND #PWR07
U 1 1 5889799A
P 12350 4950
F 0 "#PWR07" H 12350 4700 50  0001 C CNN
F 1 "GND" H 12350 4800 50  0000 C CNN
F 2 "" H 12350 4950 50  0000 C CNN
F 3 "" H 12350 4950 50  0000 C CNN
	1    12350 4950
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 P-BOOT1
U 1 1 58897B4A
P 5150 3250
F 0 "P-BOOT1" H 5150 3450 50  0000 C CNN
F 1 "CONN_01X03" V 5250 3250 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 5150 3250 50  0001 C CNN
F 3 "" H 5150 3250 50  0000 C CNN
	1    5150 3250
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR08
U 1 1 58897BCB
P 5450 3350
F 0 "#PWR08" H 5450 3100 50  0001 C CNN
F 1 "GND" H 5450 3200 50  0000 C CNN
F 2 "" H 5450 3350 50  0000 C CNN
F 3 "" H 5450 3350 50  0000 C CNN
	1    5450 3350
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR09
U 1 1 58897BE8
P 5450 3150
F 0 "#PWR09" H 5450 3000 50  0001 C CNN
F 1 "VDD" H 5450 3300 50  0000 C CNN
F 2 "" H 5450 3150 50  0000 C CNN
F 3 "" H 5450 3150 50  0000 C CNN
	1    5450 3150
	1    0    0    -1  
$EndComp
$Comp
L FT232RL U1
U 1 1 58897E85
P 2700 3850
F 0 "U1" H 2050 4750 50  0000 L CNN
F 1 "FT232RL" H 3100 4750 50  0000 L CNN
F 2 "Housings_SSOP:TSSOP-28_4.4x9.7mm_Pitch0.65mm" H 2700 3850 50  0001 C CNN
F 3 "" H 2700 3850 50  0000 C CNN
	1    2700 3850
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR010
U 1 1 588EB1ED
P 2800 2750
F 0 "#PWR010" H 2800 2600 50  0001 C CNN
F 1 "VCC" H 2800 2900 50  0000 C CNN
F 2 "" H 2800 2750 50  0000 C CNN
F 3 "" H 2800 2750 50  0000 C CNN
	1    2800 2750
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR011
U 1 1 588EB73E
P 2600 2750
F 0 "#PWR011" H 2600 2600 50  0001 C CNN
F 1 "VDD" H 2600 2900 50  0000 C CNN
F 2 "" H 2600 2750 50  0000 C CNN
F 3 "" H 2600 2750 50  0000 C CNN
	1    2600 2750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 588EBD91
P 2500 4900
F 0 "#PWR012" H 2500 4650 50  0001 C CNN
F 1 "GND" H 2500 4750 50  0000 C CNN
F 2 "" H 2500 4900 50  0000 C CNN
F 3 "" H 2500 4900 50  0000 C CNN
	1    2500 4900
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR013
U 1 1 588EC186
P 1450 3350
F 0 "#PWR013" H 1450 3200 50  0001 C CNN
F 1 "VCC" H 1450 3500 50  0000 C CNN
F 2 "" H 1450 3350 50  0000 C CNN
F 3 "" H 1450 3350 50  0000 C CNN
	1    1450 3350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 588EC317
P 1350 3850
F 0 "#PWR014" H 1350 3600 50  0001 C CNN
F 1 "GND" H 1350 3700 50  0000 C CNN
F 2 "" H 1350 3850 50  0000 C CNN
F 3 "" H 1350 3850 50  0000 C CNN
	1    1350 3850
	1    0    0    -1  
$EndComp
Text Label 3700 3150 0    60   ~ 0
TX
Text Label 3700 3250 0    60   ~ 0
RX
Text Label 11950 3950 0    60   ~ 0
RX
Text Label 11950 4050 0    60   ~ 0
TX
$Comp
L GND #PWR015
U 1 1 588EE00B
P 4100 2850
F 0 "#PWR015" H 4100 2600 50  0001 C CNN
F 1 "GND" H 4100 2700 50  0000 C CNN
F 2 "" H 4100 2850 50  0000 C CNN
F 3 "" H 4100 2850 50  0000 C CNN
	1    4100 2850
	1    0    0    -1  
$EndComp
$Comp
L R R-RST1
U 1 1 588EE19F
P 5200 2750
F 0 "R-RST1" V 5280 2750 50  0000 C CNN
F 1 "4k7" V 5200 2750 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5130 2750 50  0001 C CNN
F 3 "" H 5200 2750 50  0000 C CNN
	1    5200 2750
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 588EE190
P 4800 3950
F 0 "Y1" H 4800 4100 50  0000 C CNN
F 1 "8MHz" H 4800 3800 50  0000 C CNN
F 2 "Crystals:HC-49V" H 4800 3950 50  0001 C CNN
F 3 "" H 4800 3950 50  0000 C CNN
	1    4800 3950
	0    1    1    0   
$EndComp
$Comp
L R R-CLK1
U 1 1 588EE2D3
P 5100 3950
F 0 "R-CLK1" V 5180 3950 50  0000 C CNN
F 1 "1K" V 5100 3950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5030 3950 50  0001 C CNN
F 3 "" H 5100 3950 50  0000 C CNN
	1    5100 3950
	1    0    0    -1  
$EndComp
$Comp
L C C-CLK1
U 1 1 588EE61A
P 4450 3800
F 0 "C-CLK1" H 4475 3900 50  0000 L CNN
F 1 "22pF" H 4475 3700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4488 3650 50  0001 C CNN
F 3 "" H 4450 3800 50  0000 C CNN
	1    4450 3800
	0    1    1    0   
$EndComp
$Comp
L C C-CLK2
U 1 1 588EE680
P 4450 4100
F 0 "C-CLK2" H 4475 4200 50  0000 L CNN
F 1 "22pF" H 4475 4000 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4488 3950 50  0001 C CNN
F 3 "" H 4450 4100 50  0000 C CNN
	1    4450 4100
	0    1    1    0   
$EndComp
$Comp
L GND #PWR016
U 1 1 588EEA6B
P 4100 3900
F 0 "#PWR016" H 4100 3650 50  0001 C CNN
F 1 "GND" H 4100 3750 50  0000 C CNN
F 2 "" H 4100 3900 50  0000 C CNN
F 3 "" H 4100 3900 50  0000 C CNN
	1    4100 3900
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y2
U 1 1 588EF499
P 12300 7900
F 0 "Y2" H 12300 8050 50  0000 C CNN
F 1 "32.768kHz" H 12300 7750 50  0000 C CNN
F 2 "Crystals:Crystal_Round_Horizontal_3mm" H 12300 7900 50  0001 C CNN
F 3 "" H 12300 7900 50  0000 C CNN
	1    12300 7900
	0    -1   1    0   
$EndComp
$Comp
L C C-CLK3
U 1 1 588EF4A9
P 12650 7750
F 0 "C-CLK3" H 12675 7850 50  0000 L CNN
F 1 "22pF" H 12675 7650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 12688 7600 50  0001 C CNN
F 3 "" H 12650 7750 50  0000 C CNN
	1    12650 7750
	0    -1   1    0   
$EndComp
$Comp
L C C-CLK4
U 1 1 588EF4AF
P 12650 8050
F 0 "C-CLK4" H 12675 8150 50  0000 L CNN
F 1 "22pF" H 12675 7950 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 12688 7900 50  0001 C CNN
F 3 "" H 12650 8050 50  0000 C CNN
	1    12650 8050
	0    -1   1    0   
$EndComp
$Comp
L GND #PWR017
U 1 1 588EF4B7
P 13000 7850
F 0 "#PWR017" H 13000 7600 50  0001 C CNN
F 1 "GND" H 13000 7700 50  0000 C CNN
F 2 "" H 13000 7850 50  0000 C CNN
F 3 "" H 13000 7850 50  0000 C CNN
	1    13000 7850
	-1   0    0    -1  
$EndComp
$Comp
L MC33063/MC34063D_SO08 U3
U 1 1 588F1B22
P 2600 6150
F 0 "U3" H 2600 6150 60  0001 C CNN
F 1 "MC33063/MC34063D_SO08" H 2600 6150 60  0001 C CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 2600 6150 60  0001 C CNN
F 3 "" H 2600 6150 60  0001 C CNN
	1    2600 6150
	1    0    0    -1  
$EndComp
$Comp
L L L-PWR1
U 1 1 588F25E6
P 2550 5400
F 0 "L-PWR1" V 2500 5400 50  0000 C CNN
F 1 "100uH" V 2625 5400 50  0000 C CNN
F 2 "Inductors:SELF-WE-PD-XXL" H 2550 5400 50  0001 C CNN
F 3 "" H 2550 5400 50  0000 C CNN
	1    2550 5400
	0    1    1    0   
$EndComp
$Comp
L R R-PWR1
U 1 1 588F2A0D
P 3150 5600
F 0 "R-PWR1" V 3230 5600 50  0000 C CNN
F 1 "180" V 3150 5600 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3080 5600 50  0001 C CNN
F 3 "" H 3150 5600 50  0000 C CNN
	1    3150 5600
	1    0    0    -1  
$EndComp
$Comp
L D_Schottky D-PWR1
U 1 1 588F40BB
P 1750 5400
F 0 "D-PWR1" H 1750 5500 50  0000 C CNN
F 1 "D_Schottky" H 1750 5300 50  0000 C CNN
F 2 "Diodes_SMD:SMB_Standard" H 1750 5400 50  0001 C CNN
F 3 "" H 1750 5400 50  0000 C CNN
	1    1750 5400
	1    0    0    -1  
$EndComp
$Comp
L CP CP-PWR1
U 1 1 588F4C50
P 1600 5600
F 0 "CP-PWR1" H 1625 5700 50  0000 L CNN
F 1 "100uF" H 1625 5500 50  0000 L CNN
F 2 "Capacitors_SMD:c_elec_4x5.3" H 1638 5450 50  0001 C CNN
F 3 "" H 1600 5600 50  0000 C CNN
	1    1600 5600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR018
U 1 1 588F5065
P 1600 5800
F 0 "#PWR018" H 1600 5550 50  0001 C CNN
F 1 "GND" H 1600 5650 50  0000 C CNN
F 2 "" H 1600 5800 50  0000 C CNN
F 3 "" H 1600 5800 50  0000 C CNN
	1    1600 5800
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR019
U 1 1 588F51F6
P 1250 5400
F 0 "#PWR019" H 1250 5250 50  0001 C CNN
F 1 "VCC" H 1250 5550 50  0000 C CNN
F 2 "" H 1250 5400 50  0000 C CNN
F 3 "" H 1250 5400 50  0000 C CNN
	1    1250 5400
	1    0    0    -1  
$EndComp
$Comp
L C C-PWR1
U 1 1 588F567A
P 1700 6400
F 0 "C-PWR1" H 1725 6500 50  0000 L CNN
F 1 "1nF" H 1725 6300 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1738 6250 50  0001 C CNN
F 3 "" H 1700 6400 50  0000 C CNN
	1    1700 6400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR020
U 1 1 588F58FB
P 1700 6650
F 0 "#PWR020" H 1700 6400 50  0001 C CNN
F 1 "GND" H 1700 6500 50  0000 C CNN
F 2 "" H 1700 6650 50  0000 C CNN
F 3 "" H 1700 6650 50  0000 C CNN
	1    1700 6650
	1    0    0    -1  
$EndComp
$Comp
L R R-PWR2
U 1 1 588F6584
P 3400 6750
F 0 "R-PWR2" V 3480 6750 50  0000 C CNN
F 1 "12K" V 3400 6750 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3330 6750 50  0001 C CNN
F 3 "" H 3400 6750 50  0000 C CNN
	1    3400 6750
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR021
U 1 1 588F662A
P 3400 6500
F 0 "#PWR021" H 3400 6350 50  0001 C CNN
F 1 "VCC" H 3400 6650 50  0000 C CNN
F 2 "" H 3400 6500 50  0000 C CNN
F 3 "" H 3400 6500 50  0000 C CNN
	1    3400 6500
	1    0    0    -1  
$EndComp
$Comp
L R R-PWR3
U 1 1 588F6892
P 3400 7150
F 0 "R-PWR3" V 3480 7150 50  0000 C CNN
F 1 "3K9" V 3400 7150 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3330 7150 50  0001 C CNN
F 3 "" H 3400 7150 50  0000 C CNN
	1    3400 7150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR022
U 1 1 588F6DB3
P 3400 7400
F 0 "#PWR022" H 3400 7150 50  0001 C CNN
F 1 "GND" H 3400 7250 50  0000 C CNN
F 2 "" H 3400 7400 50  0000 C CNN
F 3 "" H 3400 7400 50  0000 C CNN
	1    3400 7400
	1    0    0    -1  
$EndComp
$Comp
L CP CP-PWR2
U 1 1 588F7D64
P 3750 6400
F 0 "CP-PWR2" H 3775 6500 50  0000 L CNN
F 1 "10uF" H 3775 6300 50  0000 L CNN
F 2 "Capacitors_SMD:c_elec_4x5.3" H 3788 6250 50  0001 C CNN
F 3 "" H 3750 6400 50  0000 C CNN
	1    3750 6400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR023
U 1 1 588F8CC1
P 3750 6650
F 0 "#PWR023" H 3750 6400 50  0001 C CNN
F 1 "GND" H 3750 6500 50  0000 C CNN
F 2 "" H 3750 6650 50  0000 C CNN
F 3 "" H 3750 6650 50  0000 C CNN
	1    3750 6650
	1    0    0    -1  
$EndComp
$Comp
L R R-PWR4
U 1 1 588F9164
P 3700 6050
F 0 "R-PWR4" V 3780 6050 50  0000 C CNN
F 1 "180" V 3700 6050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3630 6050 50  0001 C CNN
F 3 "" H 3700 6050 50  0000 C CNN
	1    3700 6050
	0    1    1    0   
$EndComp
$Comp
L CONN_01X02 BATT-IN1
U 1 1 588FA1C0
P 4650 6300
F 0 "BATT-IN1" H 4650 6450 50  0000 C CNN
F 1 "CONN_01X02" V 4750 6300 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 4650 6300 50  0001 C CNN
F 3 "" H 4650 6300 50  0000 C CNN
	1    4650 6300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR024
U 1 1 588FA652
P 4450 6500
F 0 "#PWR024" H 4450 6250 50  0001 C CNN
F 1 "GND" H 4450 6350 50  0000 C CNN
F 2 "" H 4450 6500 50  0000 C CNN
F 3 "" H 4450 6500 50  0000 C CNN
	1    4450 6500
	1    0    0    -1  
$EndComp
$Comp
L R R-LED1
U 1 1 588FE29A
P 4050 6500
F 0 "R-LED1" V 4130 6500 50  0000 C CNN
F 1 "330" V 4050 6500 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3980 6500 50  0001 C CNN
F 3 "" H 4050 6500 50  0000 C CNN
	1    4050 6500
	1    0    0    -1  
$EndComp
$Comp
L LED LED-PWR1
U 1 1 588FE754
P 4050 6850
F 0 "LED-PWR1" H 4050 6950 50  0000 C CNN
F 1 "LED" H 4050 6750 50  0000 C CNN
F 2 "LEDs:LED_0805" H 4050 6850 50  0001 C CNN
F 3 "" H 4050 6850 50  0000 C CNN
	1    4050 6850
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR025
U 1 1 588FEBF2
P 4050 7100
F 0 "#PWR025" H 4050 6850 50  0001 C CNN
F 1 "GND" H 4050 6950 50  0000 C CNN
F 2 "" H 4050 7100 50  0000 C CNN
F 3 "" H 4050 7100 50  0000 C CNN
	1    4050 7100
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR026
U 1 1 588F619C
P 1700 7700
F 0 "#PWR026" H 1700 7550 50  0001 C CNN
F 1 "VDD" H 1700 7850 50  0000 C CNN
F 2 "" H 1700 7700 50  0000 C CNN
F 3 "" H 1700 7700 50  0000 C CNN
	1    1700 7700
	1    0    0    -1  
$EndComp
$Comp
L D D-LASER1
U 1 1 588F6220
P 2300 7700
F 0 "D-LASER1" H 2300 7800 50  0000 C CNN
F 1 "D" H 2300 7600 50  0000 C CNN
F 2 "Diodes_SMD:SMB_Standard" H 2300 7700 50  0001 C CNN
F 3 "" H 2300 7700 50  0000 C CNN
	1    2300 7700
	-1   0    0    1   
$EndComp
$Comp
L D D-LASER2
U 1 1 588F629A
P 2300 7950
F 0 "D-LASER2" H 2300 8050 50  0000 C CNN
F 1 "D" H 2300 7850 50  0000 C CNN
F 2 "Diodes_SMD:MELF_Handsoldering" H 2300 7950 50  0001 C CNN
F 3 "" H 2300 7950 50  0000 C CNN
	1    2300 7950
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X02 P-LASER1
U 1 1 588F73EE
P 2800 7750
F 0 "P-LASER1" H 2800 7900 50  0000 C CNN
F 1 "CONN_01X02" V 2900 7750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 2800 7750 50  0001 C CNN
F 3 "" H 2800 7750 50  0000 C CNN
	1    2800 7750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR027
U 1 1 588F750A
P 2600 7900
F 0 "#PWR027" H 2600 7650 50  0001 C CNN
F 1 "GND" H 2600 7750 50  0000 C CNN
F 2 "" H 2600 7900 50  0000 C CNN
F 3 "" H 2600 7900 50  0000 C CNN
	1    2600 7900
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW-PWR1
U 1 1 588F9D3E
P 4200 5750
F 0 "SW-PWR1" H 4250 5850 50  0000 L CNN
F 1 "SW_Push" H 4200 5690 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 4200 5950 50  0001 C CNN
F 3 "" H 4200 5950 50  0000 C CNN
	1    4200 5750
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW-LASER1
U 1 1 588FAB67
P 1950 7400
F 0 "SW-LASER1" H 2000 7500 50  0000 L CNN
F 1 "SW_Push" H 1950 7340 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 1950 7600 50  0001 C CNN
F 3 "" H 1950 7600 50  0000 C CNN
	1    1950 7400
	1    0    0    -1  
$EndComp
$Comp
L AD620 U4
U 1 1 588FF3B3
P 14450 5400
F 0 "U4" H 14650 5550 50  0000 L CNN
F 1 "AD620" H 14650 5250 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 14450 5400 50  0001 C CNN
F 3 "" H 14450 5400 50  0000 C CNN
	1    14450 5400
	1    0    0    -1  
$EndComp
$Comp
L POT_TRIM RV-PHLASER1
U 1 1 588FF9E0
P 14450 5950
F 0 "RV-PHLASER1" V 14275 5950 50  0000 C CNN
F 1 "100K" V 14350 5950 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Trimmer-EVM3E" H 14450 5950 50  0001 C CNN
F 3 "" H 14450 5950 50  0000 C CNN
	1    14450 5950
	1    0    0    -1  
$EndComp
$Comp
L POT_TRIM RV-PHLASER2
U 1 1 5890043D
P 14700 4800
F 0 "RV-PHLASER2" V 14525 4800 50  0000 C CNN
F 1 "100K" V 14600 4800 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Trimmer-EVM3E" H 14700 4800 50  0001 C CNN
F 3 "" H 14700 4800 50  0000 C CNN
	1    14700 4800
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR028
U 1 1 589008A5
P 14700 5000
F 0 "#PWR028" H 14700 4750 50  0001 C CNN
F 1 "GND" H 14700 4850 50  0000 C CNN
F 2 "" H 14700 5000 50  0000 C CNN
F 3 "" H 14700 5000 50  0000 C CNN
	1    14700 5000
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR029
U 1 1 58900D19
P 14700 4600
F 0 "#PWR029" H 14700 4450 50  0001 C CNN
F 1 "VCC" H 14700 4750 50  0000 C CNN
F 2 "" H 14700 4600 50  0000 C CNN
F 3 "" H 14700 4600 50  0000 C CNN
	1    14700 4600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR030
U 1 1 58901DF7
P 14350 5850
F 0 "#PWR030" H 14350 5600 50  0001 C CNN
F 1 "GND" H 14350 5700 50  0000 C CNN
F 2 "" H 14350 5850 50  0000 C CNN
F 3 "" H 14350 5850 50  0000 C CNN
	1    14350 5850
	1    0    0    -1  
$EndComp
$Comp
L C C-PHLASER1
U 1 1 589038C0
P 14950 4800
F 0 "C-PHLASER1" H 14975 4900 50  0000 L CNN
F 1 "0.1uF" H 14975 4700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 14988 4650 50  0001 C CNN
F 3 "" H 14950 4800 50  0000 C CNN
	1    14950 4800
	1    0    0    -1  
$EndComp
$Comp
L POT_TRIM RV-PHLASER3
U 1 1 58905DF4
P 14150 6300
F 0 "RV-PHLASER3" V 13975 6300 50  0000 C CNN
F 1 "100K" V 14050 6300 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Trimmer-EVM3E" H 14150 6300 50  0001 C CNN
F 3 "" H 14150 6300 50  0000 C CNN
	1    14150 6300
	0    -1   -1   0   
$EndComp
$Comp
L C C-PHLASER2
U 1 1 58906D16
P 14150 6550
F 0 "C-PHLASER2" H 14175 6650 50  0000 L CNN
F 1 "0.1uF" H 14175 6450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 14188 6400 50  0001 C CNN
F 3 "" H 14150 6550 50  0000 C CNN
	1    14150 6550
	0    1    1    0   
$EndComp
$Comp
L CONN_01X03 P-SENSOR1
U 1 1 58908216
P 12800 5400
F 0 "P-SENSOR1" H 12800 5600 50  0000 C CNN
F 1 "CONN_01X03" V 12900 5400 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 12800 5400 50  0001 C CNN
F 3 "" H 12800 5400 50  0000 C CNN
	1    12800 5400
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR031
U 1 1 5890853E
P 13000 5600
F 0 "#PWR031" H 13000 5350 50  0001 C CNN
F 1 "GND" H 13000 5450 50  0000 C CNN
F 2 "" H 13000 5600 50  0000 C CNN
F 3 "" H 13000 5600 50  0000 C CNN
	1    13000 5600
	1    0    0    -1  
$EndComp
$Comp
L R R-PHLASER1
U 1 1 5890AFA0
P 13450 5300
F 0 "R-PHLASER1" V 13530 5300 50  0000 C CNN
F 1 "100K" V 13450 5300 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 13380 5300 50  0001 C CNN
F 3 "" H 13450 5300 50  0000 C CNN
	1    13450 5300
	0    1    1    0   
$EndComp
$Comp
L R R-PHLASER2
U 1 1 5890B041
P 13450 5500
F 0 "R-PHLASER2" V 13530 5500 50  0000 C CNN
F 1 "100K" V 13450 5500 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 13380 5500 50  0001 C CNN
F 3 "" H 13450 5500 50  0000 C CNN
	1    13450 5500
	0    1    1    0   
$EndComp
$Comp
L GND #PWR032
U 1 1 5890BF11
P 14000 4800
F 0 "#PWR032" H 14000 4550 50  0001 C CNN
F 1 "GND" H 14000 4650 50  0000 C CNN
F 2 "" H 14000 4800 50  0000 C CNN
F 3 "" H 14000 4800 50  0000 C CNN
	1    14000 4800
	1    0    0    -1  
$EndComp
$Comp
L R R-PHLASER3
U 1 1 5890C4E7
P 13750 4950
F 0 "R-PHLASER3" V 13830 4950 50  0000 C CNN
F 1 "100K" V 13750 4950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 13680 4950 50  0001 C CNN
F 3 "" H 13750 4950 50  0000 C CNN
	1    13750 4950
	-1   0    0    1   
$EndComp
Text Label 15150 5400 0    60   ~ 0
ADC_SENSOR
Text Label 11950 3050 0    60   ~ 0
ADC_SENSOR
$Comp
L CONN_01X02 P-PWR1
U 1 1 5891A8BA
P 1450 5200
F 0 "P-PWR1" H 1450 5350 50  0000 C CNN
F 1 "CONN_01X02" V 1550 5200 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 1450 5200 50  0001 C CNN
F 3 "" H 1450 5200 50  0000 C CNN
	1    1450 5200
	0    -1   -1   0   
$EndComp
$Comp
L SKHMP*E010_SKHMPXE010 U5
U 1 1 5891EE27
P 4450 2850
F 0 "U5" H 4450 2850 0   0001 C CNN
F 1 "SKHMP*E010_SKHMPXE010" H 4450 2850 0   0001 C CNN
F 2 "switch:SKHMPXE010" H 4450 2850 60  0001 C CNN
F 3 "" H 4450 2850 60  0001 C CNN
	1    4450 2850
	1    0    0    -1  
$EndComp
$Comp
L USB_OTG P2
U 1 1 58920D53
P 5150 6300
F 0 "P2" H 5475 6175 50  0000 C CNN
F 1 "USB_OTG" H 5150 6500 50  0000 C CNN
F 2 "Connect:USB_Mini-B" V 5100 6200 50  0001 C CNN
F 3 "" V 5100 6200 50  0000 C CNN
	1    5150 6300
	0    1    1    0   
$EndComp
Wire Wire Line
	8300 2550 9100 2550
Connection ~ 9000 2550
Connection ~ 8900 2550
Connection ~ 8800 2550
Connection ~ 8700 2550
Connection ~ 8600 2550
Wire Wire Line
	8500 8450 9100 8450
Connection ~ 8600 8450
Connection ~ 8700 8450
Connection ~ 8800 8450
Connection ~ 8900 8450
Connection ~ 9000 8450
Wire Wire Line
	13650 2700 13850 2700
Wire Wire Line
	13850 2700 13850 2600
Wire Wire Line
	13150 2700 12950 2700
Wire Wire Line
	13650 2800 13850 2800
Wire Wire Line
	13150 2800 12950 2800
Wire Wire Line
	13650 2900 13850 2900
Wire Wire Line
	13150 2900 12950 2900
Wire Wire Line
	13650 3000 13850 3000
Wire Wire Line
	13150 3000 12950 3000
Wire Wire Line
	13650 3100 13850 3100
Wire Wire Line
	13150 3100 12950 3100
Wire Wire Line
	13650 3200 13850 3200
Wire Wire Line
	13150 3200 12950 3200
Wire Wire Line
	13650 3300 13850 3300
Wire Wire Line
	13150 3300 12950 3300
Wire Wire Line
	13650 3400 13850 3400
Wire Wire Line
	13150 3400 12950 3400
Wire Wire Line
	13650 3500 13850 3500
Wire Wire Line
	13150 3500 12950 3500
Wire Wire Line
	13650 3600 13850 3600
Wire Wire Line
	13150 3600 12950 3600
Wire Wire Line
	13650 3700 13850 3700
Wire Wire Line
	13150 3700 12950 3700
Wire Wire Line
	13650 3800 13850 3800
Wire Wire Line
	13650 3900 13850 3900
Wire Wire Line
	13650 4000 13850 4000
Wire Wire Line
	13150 3800 12950 3800
Wire Wire Line
	13150 3900 12950 3900
Wire Wire Line
	13150 4000 12950 4000
Wire Wire Line
	13650 4200 14450 4200
Wire Wire Line
	14450 4200 14450 4050
Wire Wire Line
	13650 4100 14300 4100
Wire Wire Line
	14300 4100 14300 4050
Wire Wire Line
	13150 4100 12950 4100
Wire Wire Line
	13150 4200 12950 4200
Wire Wire Line
	5900 4850 5600 4850
Wire Wire Line
	5900 7450 5600 7450
Wire Wire Line
	5900 7350 5600 7350
Wire Wire Line
	5600 7250 5900 7250
Wire Wire Line
	5900 6250 5650 6250
Wire Wire Line
	5900 6150 5650 6150
Wire Wire Line
	5900 6050 5650 6050
Wire Wire Line
	5900 5950 5650 5950
Wire Wire Line
	5900 5850 5650 5850
Wire Wire Line
	5900 5750 5650 5750
Wire Wire Line
	5900 5650 5650 5650
Wire Wire Line
	5900 5550 5650 5550
Wire Wire Line
	5900 5450 5650 5450
Wire Wire Line
	5900 6550 5600 6550
Wire Wire Line
	5900 6450 5600 6450
Wire Wire Line
	5900 7950 5600 7950
Wire Wire Line
	5900 7850 5600 7850
Wire Wire Line
	5900 6950 5600 6950
Wire Wire Line
	5900 6850 5600 6850
Wire Wire Line
	5900 7550 5600 7550
Wire Wire Line
	5900 7150 5600 7150
Wire Wire Line
	11700 3550 11950 3550
Wire Wire Line
	11700 3650 11950 3650
Wire Wire Line
	11700 3750 11950 3750
Wire Wire Line
	11700 5350 11950 5350
Wire Wire Line
	11700 5450 11950 5450
Wire Wire Line
	5900 7750 5600 7750
Wire Wire Line
	11700 6650 11950 6650
Wire Wire Line
	11700 4950 12350 4950
Wire Wire Line
	5350 3250 5900 3250
Wire Wire Line
	5350 3150 5450 3150
Wire Wire Line
	5350 3350 5450 3350
Wire Wire Line
	1900 3150 1900 2850
Wire Wire Line
	1900 2850 2600 2850
Wire Wire Line
	2600 2850 2600 2750
Wire Wire Line
	1900 4850 2900 4850
Connection ~ 2800 4850
Connection ~ 2700 4850
Wire Wire Line
	2500 4900 2500 4850
Wire Wire Line
	1200 3450 1650 3450
Wire Wire Line
	1650 3450 1650 3550
Wire Wire Line
	1650 3550 1900 3550
Wire Wire Line
	1200 3550 1550 3550
Wire Wire Line
	1550 3550 1550 3500
Wire Wire Line
	1550 3500 1700 3500
Wire Wire Line
	1700 3500 1700 3450
Wire Wire Line
	1700 3450 1900 3450
Wire Wire Line
	3500 3150 3700 3150
Wire Wire Line
	3500 3250 3700 3250
Wire Wire Line
	11700 3950 11950 3950
Wire Wire Line
	11700 4050 11950 4050
Wire Wire Line
	1900 4550 1900 4850
Connection ~ 2500 4850
Wire Wire Line
	4750 2950 5700 2950
Wire Wire Line
	5700 2950 5700 3050
Wire Wire Line
	5700 3050 5900 3050
Wire Wire Line
	5200 2900 5200 2950
Connection ~ 5200 2950
Wire Wire Line
	5200 2600 8300 2600
Wire Wire Line
	8300 2600 8300 2550
Connection ~ 8500 2550
Wire Wire Line
	5900 3850 5550 3850
Wire Wire Line
	5550 3850 5550 3800
Wire Wire Line
	5550 3800 4600 3800
Wire Wire Line
	5900 3950 5550 3950
Wire Wire Line
	5550 3950 5550 4100
Wire Wire Line
	5550 4100 4600 4100
Connection ~ 5100 3800
Connection ~ 5100 4100
Connection ~ 4800 3800
Connection ~ 4800 4100
Wire Wire Line
	4300 3800 4300 4100
Wire Wire Line
	4100 3900 4300 3900
Connection ~ 4300 3900
Wire Wire Line
	11950 7750 12500 7750
Wire Wire Line
	11950 8050 12500 8050
Connection ~ 12300 7750
Connection ~ 12300 8050
Wire Wire Line
	12800 7750 12800 8050
Wire Wire Line
	13000 7850 12800 7850
Connection ~ 12800 7850
Wire Wire Line
	11700 7850 11950 7850
Wire Wire Line
	11950 7850 11950 7750
Wire Wire Line
	11700 7950 11950 7950
Wire Wire Line
	11950 7950 11950 8050
Wire Wire Line
	2800 2750 2800 2850
Wire Wire Line
	2700 5400 3400 5400
Wire Wire Line
	3150 5400 3150 5450
Wire Wire Line
	1900 5400 2400 5400
Wire Wire Line
	2000 5400 2000 5850
Wire Wire Line
	3150 5750 3150 5850
Wire Wire Line
	3150 5850 3100 5850
Connection ~ 2000 5400
Wire Wire Line
	2000 6250 1700 6250
Wire Wire Line
	2000 6450 1950 6450
Wire Wire Line
	1950 6450 1950 6650
Wire Wire Line
	1950 6650 1500 6650
Wire Wire Line
	1700 6650 1700 6550
Wire Wire Line
	2000 6050 1500 6050
Wire Wire Line
	1500 6050 1500 6650
Connection ~ 1700 6650
Wire Wire Line
	3400 6500 3400 6600
Wire Wire Line
	3400 7300 3400 7400
Wire Wire Line
	3400 6900 3400 7000
Wire Wire Line
	3100 6450 3200 6450
Wire Wire Line
	3200 6450 3200 6950
Wire Wire Line
	3200 6950 3400 6950
Connection ~ 3400 6950
Wire Wire Line
	3100 6250 4150 6250
Wire Wire Line
	3750 6550 3750 6650
Wire Wire Line
	3100 6050 3550 6050
Wire Wire Line
	3400 5400 3400 6050
Connection ~ 3150 5400
Connection ~ 3400 6050
Connection ~ 3750 6250
Wire Wire Line
	3850 6050 3950 6050
Wire Wire Line
	3950 6050 3950 6250
Connection ~ 3950 6250
Wire Wire Line
	4250 6250 4450 6250
Wire Wire Line
	4450 6350 4450 6500
Wire Wire Line
	4050 6350 4050 6250
Connection ~ 4050 6250
Wire Wire Line
	4050 6650 4050 6700
Wire Wire Line
	4050 7000 4050 7100
Wire Wire Line
	2150 7700 2150 7950
Wire Wire Line
	2450 7950 2450 7700
Wire Wire Line
	2000 7700 2150 7700
Wire Wire Line
	1900 7700 1700 7700
Wire Wire Line
	2450 7700 2600 7700
Wire Wire Line
	2600 7900 2600 7800
Wire Wire Line
	4250 5950 4250 6250
Wire Wire Line
	4250 5950 4400 5950
Wire Wire Line
	4400 5950 4400 5750
Wire Wire Line
	4150 6250 4150 5950
Wire Wire Line
	4150 5950 4000 5950
Wire Wire Line
	4000 5950 4000 5750
Wire Wire Line
	2000 7700 2000 7550
Wire Wire Line
	2000 7550 2150 7550
Wire Wire Line
	2150 7550 2150 7400
Wire Wire Line
	1900 7700 1900 7550
Wire Wire Line
	1900 7550 1750 7550
Wire Wire Line
	1750 7550 1750 7400
Wire Wire Line
	14450 5700 14450 5800
Wire Wire Line
	14600 5950 14600 5700
Wire Wire Line
	14600 5700 14550 5700
Wire Wire Line
	14700 5000 14700 4950
Wire Wire Line
	14700 4600 14700 4650
Wire Wire Line
	14550 4800 14450 4800
Wire Wire Line
	14450 4800 14450 5100
Wire Wire Line
	14350 5850 14350 5700
Wire Wire Line
	14350 5100 14350 4650
Wire Wire Line
	14350 4650 14950 4650
Connection ~ 14700 4650
Wire Wire Line
	14700 4950 14950 4950
Wire Wire Line
	14300 6300 14900 6300
Wire Wire Line
	14900 5400 14900 6550
Wire Wire Line
	14750 5400 15150 5400
Wire Wire Line
	14900 6550 14300 6550
Connection ~ 14900 6300
Wire Wire Line
	13850 6550 14000 6550
Wire Wire Line
	13850 5500 13850 6550
Wire Wire Line
	13600 5500 14150 5500
Wire Wire Line
	14150 5500 14150 6150
Wire Wire Line
	13000 5500 13000 5600
Connection ~ 13850 5500
Wire Wire Line
	13600 5300 14150 5300
Wire Wire Line
	14000 4800 13750 4800
Wire Wire Line
	13750 5100 13750 5300
Connection ~ 13750 5300
Wire Wire Line
	13000 5300 13300 5300
Wire Wire Line
	13000 5400 13300 5400
Wire Wire Line
	13300 5400 13300 5500
Connection ~ 14900 5400
Wire Wire Line
	11700 3050 11950 3050
Wire Wire Line
	1200 3350 1450 3350
Wire Wire Line
	1400 5400 1250 5400
Wire Wire Line
	1500 5400 1600 5400
Wire Wire Line
	1600 5400 1600 5450
Wire Wire Line
	1600 5750 1600 5800
Wire Wire Line
	4750 2850 4750 2950
Wire Wire Line
	4100 2850 4250 2850
Wire Wire Line
	4250 2850 4250 3050
Connection ~ 4250 2950
Wire Wire Line
	5250 6700 4850 6700
Wire Wire Line
	4850 6700 4850 6500
Wire Wire Line
	4850 6100 4250 6100
Connection ~ 4250 6100
$Comp
L USB_OTG P1
U 1 1 58921B9F
P 900 3550
F 0 "P1" H 1225 3425 50  0000 C CNN
F 1 "USB_OTG" H 900 3750 50  0000 C CNN
F 2 "Connect:USB_Mini-B" V 850 3450 50  0001 C CNN
F 3 "" V 850 3450 50  0000 C CNN
	1    900  3550
	0    -1   1    0   
$EndComp
Wire Wire Line
	1200 3750 1350 3750
Wire Wire Line
	1350 3750 1350 3850
Wire Wire Line
	800  3950 1200 3950
Wire Wire Line
	1200 3950 1200 3750
Wire Wire Line
	4850 6500 4450 6500
$EndSCHEMATC
