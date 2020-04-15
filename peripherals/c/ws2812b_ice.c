#include "ws2812b.h"

void ws2812b_rotate( WS2812B_t *base, uint8_t num_leds) {
	
	WS2812B_t temp = base[num_leds-1];
	int i;
	for(i=num_leds-2; i>=0; i--) {
		base[i] = base[i+1];
	}
	base[0] = temp;
}

void ws2812b_pulse(WS2812B_t *base, uint8_t num_leds) {
	
	static int direction = 1; // 1: incrementing; 0: decrementing
	int i;
	uint8_t red;
	for(i=0; i<num_leds; i++) {
		red = base[i].red;
		if(red == 0xFF) {
			direction = 0;
		} else if(red == 0x00) {
			direction = 1;
		} else if(direction) {
			red++;
		} else {
			red --;
		}
		base[i].red = red;
	}
		
}
