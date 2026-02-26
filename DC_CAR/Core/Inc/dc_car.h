

#include "stm32f4xx_hal.h"


#ifndef INC_DC_CAR_H_
#define INC_DC_CAR_H_

#define DC_PORT_IN1 GPIOC
#define DC_PIN_IN1 GPIO_PIN_9

#define DC_PORT_IN2 GPIOB
#define DC_PIN_IN2 GPIO_PIN_8

#define DC_PORT_IN3 GPIOC
#define DC_PIN_IN3 GPIO_PIN_8

#define DC_PORT_IN4 GPIOC
#define DC_PIN_IN4 GPIO_PIN_6



void GO_UP();
void GO_DOWN();
void GO_LEFT();
void GO_RIGHT();
void GO_STOP();



void DC_CONTROL(uint8_t cmd);

#endif /* INC_DC_CAR_H_ */
