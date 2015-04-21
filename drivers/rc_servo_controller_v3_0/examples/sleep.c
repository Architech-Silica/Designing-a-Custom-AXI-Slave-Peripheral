#include "sleep.h"


void millisleep(unsigned int milliseconds)
{
	int i = 0;

	for (i=0; i<milliseconds; i++)
	{
		usleep(1000);
	}
}

// These two functions must be included for microblaze projects
// A Timer peripheral must also be added

void usleep(unsigned int useconds)
{
	unsigned int timer_count = 0;
	unsigned int wait_for_timer = 0;
	unsigned int count_value = 0;

	wait_for_timer = 1;
	count_value = useconds * (PROCESSOR_CLOCK_FREQUENCY / 1000000);
	XTmrCtr_Disable(XPAR_TMRCTR_0_BASEADDR, 0);
	XTmrCtr_SetLoadReg(XPAR_TMRCTR_0_BASEADDR, 0, 0x00);
	XTmrCtr_LoadTimerCounterReg(XPAR_TMRCTR_0_BASEADDR, 0);

	// Set the timer running
	XTmrCtr_SetControlStatusReg(XPAR_TMRCTR_0_BASEADDR, 0, XTC_CSR_ENABLE_TMR_MASK);

	while (wait_for_timer)
	{
		timer_count=XTmrCtr_GetTimerCounterReg(XPAR_TMRCTR_0_BASEADDR, 0);
		if (timer_count > count_value)
		{
			wait_for_timer = 0;
		}
	}

	XTmrCtr_SetControlStatusReg(XPAR_TMRCTR_0_BASEADDR, 0, 0x00);
}

void sleep(unsigned int seconds)
{
	int i = 0;

	for (i=0; i<seconds; i++)
	{
		millisleep(1000);
	}
}

