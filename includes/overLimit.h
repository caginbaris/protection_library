
#ifndef __overLimit_h
#define __overLimit_h

#include <stdint.h>

typedef struct overLimit_inputParameters {

	float level;
	float delay;
	float dropout_ratio;
	float dropout_time;

}overLimit_inputParameters;

typedef struct overLimit_outputParameters {

	uint32_t trip_counter;
	uint32_t dropout_counter;

	uint8_t initial_pick_up:1;
	uint8_t pick_up:1;
	uint8_t trip:1;
	uint8_t trip_latch:5;
	

}overLimit_outputParameters;

void overLimit(float rms,overLimit_inputParameters overLimit_in, overLimit_outputParameters *overLimit_out,uint8_t reset, uint8_t enable);


#endif


