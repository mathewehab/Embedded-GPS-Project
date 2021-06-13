#include "define.h"
#include "tm4c123gh6pm.h"
#include <math.h>
#include "fpu.h"
#include <stdint.h>
#include "fpu.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned char Gpsdata;             // for incoming serial data
unsigned int finish =0;            // indicate end of message
unsigned int pos_cnt=0;            // position counter
unsigned int lat_cnt=0;            // latitude data counter
unsigned int log_cnt=0;            // longitude data counter
unsigned int flg    =0;            // GPS flag
unsigned int com_cnt=0;            // comma counter
char lat[20];             // latitude array
char lg[20];              // longitude array
char distance_Display[20];
char total_distance_Display[20];
unsigned int i=0;
unsigned int fg=0;
double lat_raw;
double lg_raw;
unsigned int degrees_lat;
unsigned int minutes_lat;
double seconds_lat;
unsigned int degrees_lon;
unsigned int minutes_lon;
double seconds_lon;
double Latitude;
double Longitude;
double Total_distance=0.0;
char lat_new_display[20]; // display variables for testing on serial port
char long_new_display[20];
char lat_old_display[20];
char long_old_display[20];
char lat_raw_display[20];
char long_raw_display[20];

void RGBLED_Init(void);
void delay_ms(int);
void delay_us(int);
void LED_Output(unsigned char);
void TestDistance(double);
double CalcGPSDistance(double,double,double,double);
void SevenSeg_Data(int, int);
void Startup(void);
void UART_Init(void);
char UART_Inchar(void);
void Red_blink ();
void UART0_Init(void);
void UART_outstring (char  *pt);
void UART_outchar(char data);
char UART_Inchar(void);
double ConvertDegreeAngleTodouble(double degrees, double minutes, double seconds);
