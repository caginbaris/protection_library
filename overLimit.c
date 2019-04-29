
#include "plib.h"


void overLimit(float rms,overLimit_inputParameters overLimit_in, overLimit_outputParameters *overLimit_out,uint8_t reset, uint8_t enable)
{
	
	
		if (rms > overLimit_in.level)
		{
			overLimit_out->initial_pick_up = 1;
		}
		
		if (rms < overLimit_in.level * overLimit_in.dropout_ratio)
		{
			overLimit_out->initial_pick_up = 0;
		}
		
		if (enable){
		
		overLimit_out->pick_up = off_delay(overLimit_out->initial_pick_up, overLimit_out->pick_up, overLimit_in.dropout_time * fs, &(overLimit_out->dropout_counter));

		overLimit_out->trip    = on_delay (overLimit_out->pick_up, overLimit_out->trip, overLimit_in.delay * fs, &(overLimit_out->trip_counter));

		if (overLimit_out->trip == 1)
		{
			overLimit_out->trip_latch = 1;
		}
		
		}else{
		
		overLimit_out->pick_up=0;		
		overLimit_out->trip = 0;
			
		}
		
		if(overLimit_out->initial_pick_up==0 && reset==1){
		
			overLimit_out->trip_latch=0;
		
		}
		
}


