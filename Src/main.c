#include "stm32f4xx.h"   // CMSIS header
#include <stdint.h>

volatile uint32_t count = 0;

void delay(volatile uint32_t time) {
    while (time--);  // Đơn giản, không chính xác, đủ để quan sát LED
}

int main(void) {
    // 1. Bật clock cho Port D
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    // 2. Cấu hình chân PD15 làm output
    GPIOD->MODER &= ~(0x3 << (15 * 2));      // Clear 2 bit MODER15
    GPIOD->MODER |=  (0x1 << (15 * 2));      // Set 01: output

    GPIOD->OTYPER &= ~(1 << 15);             // Push-pull
    GPIOD->OSPEEDR |= (0x3 << (15 * 2));     // High speed
    GPIOD->PUPDR &= ~(0x3 << (15 * 2));      // No pull-up, pull-down

    while (1) {
        GPIOD->ODR ^= (1 << 15);             // Toggle PD15 (LED)
        count++;                             // Tăng biến đếm

        delay(1000000);                      // Độ trễ đơn giản để nhìn LED nhấp nháy
    }
}
