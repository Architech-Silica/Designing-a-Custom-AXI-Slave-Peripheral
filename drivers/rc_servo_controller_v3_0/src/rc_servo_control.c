#include "rc_servo_control.h"
#include "xparameters.h"
#include "xil_io.h"


void rc_servo_set_servo_position(int baseaddr, int servo_number, int position)
{
	servo_number--;
	if (servo_number >=0)
		rc_servo_set_servo_register(baseaddr, 128 + (servo_number*4), position);
}

int rc_servo_get_servo_position(int baseaddr, int servo_number)
{
	int temp = 0;

	servo_number--;
	if (servo_number >=0)
		temp = rc_servo_get_servo_register(baseaddr, 128 + (servo_number*4));
	return (temp);
}

void rc_servo_enable_manual_mode(int baseaddr, int servo_number)
{
	int mask;
	int temp;

	temp = 1;
	mask = 1;
	while (temp < servo_number)
	{
		mask *= 2;
		temp++;
	}
	servo_number--;

	if (servo_number >=0)
	{
		temp = rc_servo_get_servo_register(baseaddr, 0);
		temp = temp | mask;
		rc_servo_set_servo_register(baseaddr, 0, temp);
	}
}

void rc_servo_disable_manual_mode(int baseaddr, int servo_number)
{
	int mask;
	int temp;

	temp = 1;
	mask = 1;
	while (temp < servo_number)
	{
		mask *= 2;
		temp++;
	}
	mask = ~mask;
	servo_number--;

	if (servo_number >=0)
	{
		temp = rc_servo_get_servo_register(baseaddr, 0);
		temp = temp & mask;
		rc_servo_set_servo_register(baseaddr, 0, temp);
	}
}


void rc_servo_set_servo_register(int baseaddr, int offset, int value)
{
	Xil_Out32(baseaddr + offset, value);
}

int rc_servo_get_servo_register(int baseaddr, int offset)
{
	int temp = 0;
	temp = Xil_In32(baseaddr + offset);
	return (temp);
}

void rc_servo_assert_manual_output(int baseaddr, int servo_number)
{
	int mask;
	int temp;

	temp = 1;
	mask = 1;
	while (temp < servo_number)
	{
		mask *= 2;
		temp++;
	}
	servo_number--;

	if (servo_number >=0)
	{
		temp = rc_servo_get_servo_register(baseaddr, 4);
		temp = temp | mask;
		rc_servo_set_servo_register(baseaddr, 4, temp);
	}
}

void rc_servo_deassert_manual_output(int baseaddr, int servo_number)
{
	int mask;
	int temp;

	temp = 1;
	mask = 1;
	while (temp < servo_number)
	{
		mask *= 2;
		temp++;
	}
	mask = ~mask;
	servo_number--;

	if (servo_number >=0)
	{
		temp = rc_servo_get_servo_register(baseaddr, 4);
		temp = temp & mask;
		rc_servo_set_servo_register(baseaddr, 4, temp);
	}
}

void rc_servo_set_low_endstop(int baseaddr, int servo_number, int value)
{
	servo_number--;
	if (servo_number >=0)
		rc_servo_set_servo_register(baseaddr, 256 + (servo_number*4), value);
}

void rc_servo_set_high_endstop(int baseaddr, int servo_number, int value)
{
	servo_number--;
	if (servo_number >=0)
		rc_servo_set_servo_register(baseaddr, 384 + (servo_number*4), value);
}

int rc_servo_get_low_endstop(int baseaddr, int servo_number)
{
	int temp = 0;

	servo_number--;
	if (servo_number >=0)
		temp = rc_servo_get_servo_register(baseaddr, 256 + (servo_number*4));
	return (temp);
}

int rc_servo_get_high_endstop(int baseaddr, int servo_number)
{
	int temp = 0;

	servo_number--;
	if (servo_number >=0)
		temp = rc_servo_get_servo_register(baseaddr, 384 + (servo_number*4));
	return (temp);
}

