#include "xparameters.h"
#include "xintc_l.h"
#include "xintc.h"
#include "stdio.h"
#include "xtmrctr_l.h"
#include "rc_servo_control.h"
#include "sleep.h"



#define SERVO_UPDATE_DELAY 200


// Global Variables
int servo_value;
int servo_offset;
int servo_side;
int number_of_interrupts_from_timer;


// Function Prototypes
void calculate_servo_position(void);
void adjust_servo_manually(int baseaddr, int servo_number, int position);



int main (void)
{
	int i = 0;
	xil_printf("Start of Servo Control Demo\n\r");


	// Start by adjusting the servo manually; GPIO style.
	// Just to prove that it works, this essentially bypasses the state machine in the servo controller
	xil_printf("Configuring the Servo controller in manual mode\n\r");
	rc_servo_enable_manual_mode(XPAR_AXI_RC_SERVO_CONTROLLER_0_BASEADDR, 1);


	for(i=0; i<2048; i++)
	{
		calculate_servo_position();
		adjust_servo_manually(XPAR_AXI_RC_SERVO_CONTROLLER_0_BASEADDR, 1, 0x00 + servo_value);
		millisleep(SERVO_UPDATE_DELAY);
	}

	// Now switch over to using the servo controller properly.
	// This is the way that the servo controller would normally be used
	xil_printf("Configuring the Servo controller in automatic mode\n\r");
	rc_servo_disable_manual_mode(XPAR_AXI_RC_SERVO_CONTROLLER_0_BASEADDR, 1);


	for(i=0; i<2048; i++)
	{
		calculate_servo_position();
		rc_servo_set_servo_position(XPAR_AXI_RC_SERVO_CONTROLLER_0_BASEADDR, 1, 0x00 + servo_value);
		millisleep(SERVO_UPDATE_DELAY);
	}


	xil_printf("End of Servo Control Demo\n\r");
	return (0);
}



void calculate_servo_position(void)
{
	if (servo_offset < 0x7F) servo_offset+=5; else servo_offset = 0x10;
	while (servo_offset > 0x7F) servo_offset--;

	if (servo_side == 1)
	{
		servo_side = 0;
		servo_value = 0x80 + servo_offset;
	}
	else
	{
		servo_side = 1;
		servo_value = 0x80 - servo_offset;
	}
}



void adjust_servo_manually(int baseaddr, int servo_number, int position)
{
	int high_time_us;

	high_time_us = 700 + ((2000/256) * position);

	millisleep(25);
	rc_servo_assert_manual_output(baseaddr, servo_number);
	usleep(high_time_us);
	rc_servo_deassert_manual_output(baseaddr, servo_number);
}



