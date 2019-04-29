
#include "plib.h"


void underLimit(float rms,underLimit_inputParameters underLimit_in, underLimit_outputParameters *underLimit_out,uint8_t reset, uint8_t enable)
{
	
		if (rms < underLimit_in.level)
		{
			underLimit_out->initial_pick_up = 1;
		}
		
		if (rms > underLimit_in.level * underLimit_in.dropout_ratio)
		{
			underLimit_out->initial_pick_up = 0;
		}
		
		if (enable){
		
		underLimit_out->pick_up = off_delay(underLimit_out->initial_pick_up, underLimit_out->pick_up, underLimit_in.dropout_time * fs, &(underLimit_out->dropout_counter));

		underLimit_out->trip    = on_delay (underLimit_out->pick_up, underLimit_out->trip, underLimit_in.delay * fs, &(underLimit_out->trip_counter));

		if (underLimit_out->trip == 1)
		{
			underLimit_out->trip_latch = 1;
		}
		
		}else{
		
		underLimit_out->pick_up=0;		
		underLimit_out->trip = 0;
			
		}
		
		if(underLimit_out->initial_pick_up==0 && reset==1){
		
			underLimit_out->trip_latch=0;
		
		}
		
}
