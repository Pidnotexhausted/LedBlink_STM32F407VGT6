# Programming Register Level for STM32F407VGT6

This project configured system clock and GPIO using register level.
4 leds will toggle in order.

CLOCK:

- Using HSE 8MHz.
- Config PLL to get expected system clock is 64MHz.

GPIO:

- Using GPIOD of STM32F4-Dics board (Led on board).
- Config GPIOD12->15: output, push-pull, no pull-up and no pull-down, low speed.
