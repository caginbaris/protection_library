
#ifndef __underLimit_h
#define __underLimit_h

#include <stdint.h>

typedef struct underLimit_inputParameters {

	float level;
	float delay;
	float dropout_ratio;
	float dropout_time;
	
	uint8_t enable:1;
	uint8_t init_error:1;
	uint8_t rem:6;

}underLimit_inputParameters;

typedef struct underLimit_outputParameters {

	uint32_t trip_counter;
	uint32_t dropout_counter;

	uint8_t initial_pick_up:1;
	uint8_t pick_up:1;
	uint8_t trip:1;
	uint8_t trip_latch:1;
	uint8_t rem:4;

	

}underLimit_outputParameters;

void underLimitInitialization(underLimit_inputParameters *in,underLimit_inputParameters init);
void underLimit(float rms,underLimit_inputParameters underLimit_in, underLimit_outputParameters *underLimit_out,uint8_t inhibit,uint8_t reset);



#endif


