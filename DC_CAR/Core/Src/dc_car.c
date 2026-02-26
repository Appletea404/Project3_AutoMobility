#include "dc_car.h"

extern volatile uint8_t rxData[10];


// 전진: 양쪽 모터를 정방향으로 회전
void GO_UP()
{
    HAL_GPIO_WritePin(DC_PORT_IN1, DC_PIN_IN1, GPIO_PIN_SET);   // IN1 (PC9)
    HAL_GPIO_WritePin(DC_PORT_IN2, DC_PIN_IN2, GPIO_PIN_RESET); // IN2 (PB8)
    HAL_GPIO_WritePin(DC_PORT_IN3, DC_PIN_IN3, GPIO_PIN_SET);   // IN3 (PC8)
    HAL_GPIO_WritePin(DC_PORT_IN4, DC_PIN_IN4, GPIO_PIN_RESET); // IN4 (PC6)
}

// 후진: 양쪽 모터를 역방향으로 회전
void GO_DOWN()
{
    HAL_GPIO_WritePin(DC_PORT_IN1, DC_PIN_IN1, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(DC_PORT_IN2, DC_PIN_IN2, GPIO_PIN_SET);
    HAL_GPIO_WritePin(DC_PORT_IN3, DC_PIN_IN3, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(DC_PORT_IN4, DC_PIN_IN4, GPIO_PIN_SET);
}

// 좌회전: 한쪽은 전진, 한쪽은 후진하여 제자리 회전
void GO_LEFT()
{
    HAL_GPIO_WritePin(DC_PORT_IN1, DC_PIN_IN1, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(DC_PORT_IN2, DC_PIN_IN2, GPIO_PIN_SET);
    HAL_GPIO_WritePin(DC_PORT_IN3, DC_PIN_IN3, GPIO_PIN_SET);
    HAL_GPIO_WritePin(DC_PORT_IN4, DC_PIN_IN4, GPIO_PIN_RESET);
}

// 우회전: 한쪽은 후진, 한쪽은 전진하여 제자리 회전
void GO_RIGHT()
{
    HAL_GPIO_WritePin(DC_PORT_IN1, DC_PIN_IN1, GPIO_PIN_SET);
    HAL_GPIO_WritePin(DC_PORT_IN2, DC_PIN_IN2, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(DC_PORT_IN3, DC_PIN_IN3, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(DC_PORT_IN4, DC_PIN_IN4, GPIO_PIN_SET);
}

// 정지: 모든 출력을 Low로 만들어 모터 멈춤
void GO_STOP()
{
    HAL_GPIO_WritePin(DC_PORT_IN1, DC_PIN_IN1, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(DC_PORT_IN2, DC_PIN_IN2, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(DC_PORT_IN3, DC_PIN_IN3, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(DC_PORT_IN4, DC_PIN_IN4, GPIO_PIN_RESET);
}


// 블루투스로 받은 문자에 따라 모터 제어
void DC_CONTROL(uint8_t cmd)
{
    if      (cmd == 'F')     // 전진
    {
    	GO_UP();
    	cmd = 0;
    }
    if      (cmd == 'B')     // 전진
        {
        	GO_DOWN();
        	cmd = 0;
        }
    if      (cmd == 'L')     // 전진
        {
        	GO_LEFT();
        	cmd = 0;
        }
    if      (cmd == 'R')     // 전진
        {
        	GO_RIGHT();
        	cmd = 0;
        }
    if      (cmd == 'S')     // 전진
        {
        	GO_STOP();
        	cmd = 0;
        }



}

// 초기 테스트용 함수
void DC_RUN()
{
    GO_UP();
}
