
#ifndef __automata_h
#define __automata_h

#include <stdint.h>

uint8_t on_delay(uint8_t input, uint8_t mem, uint32_t qual_sample, uint32_t *count);
uint8_t off_delay(uint8_t input, uint8_t mem, uint32_t qual_sample, uint32_t *count);
uint8_t on_off_delay(uint8_t input, uint8_t mem, uint32_t qual_sample, uint32_t *count);

void f_limiter(float* parameter,float downLimit,float upLimit);


//macros

#define ON_DELAY(input,out,qual,count) 			out=on_delay(input,out,qual,&count)
#define OFF_DELAY(input,out,qual,count) 		out=off_delay(input,out,qual,&count)
#define ON_OFF_DELAY(input,out,qual,count) 	out=on_off_delay(input,out,qual,&count)

#define f_LIMITER(x,down,up)								f_limiter(&x,down,up)

#endif

