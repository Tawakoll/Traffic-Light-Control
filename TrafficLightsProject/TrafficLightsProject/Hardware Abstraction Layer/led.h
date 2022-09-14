/*
 * led.h
 *
 * Created: 12/09/2022 04:17:42 PM
 *  Author: main user
 */ 


#ifndef LED_H_
#define LED_H_

/*includes of other header files needed*/

#include "../gpio_driver/gpio.h"

/********************    functions prototypes    *************************/

void LED_init(uint8_t ledPort, uint8_t ledPin);
void LED_on(uint8_t ledPort, uint8_t ledPin);
void LED_off(uint8_t ledPort, uint8_t ledPin);
void LED_blink(uint8_t ledPort, uint8_t ledPin,uint32_t blinkTime);

#endif /* LED_H_ */