#include <xparameters.h>

#define PROCESSOR_CLOCK_FREQUENCY XPAR_CPU_CORE_CLOCK_FREQ_HZ // Set the frequency of the processor clock in Hz here!

// This header must be included for microblaze projects
#include <xtmrctr_l.h>


// Function prototypes
void millisleep(unsigned int microseconds);

// These two function prototypes must be included for microblaze projects
void usleep(unsigned int useconds);
void sleep(unsigned int seconds);

