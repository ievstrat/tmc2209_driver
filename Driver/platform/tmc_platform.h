#ifndef TMC_PLATFORM_H
#define TMC_PLATFORM_H

#include "main.h"

#define TIM_FREQUENCY 64000000


struct tmc_gpio{
  GPIO_TypeDef* port;
  uint16_t pin;
};

struct tmc_uart{
  UART_HandleTypeDef* *uart;
};

struct tmc_step{
  TIM_HandleTypeDef *tim;
  TIM_OC_InitTypeDef *pwm_config;
  uint8_t channel;
  uint32_t steps;
};

void tmc_gpio_write(struct tmc_gpio* gpio, int state);

void tmc_step_setting(struct tmc_step* step, uint16_t steps, uint32_t speed_steps);

void tmc_step_start(struct tmc_step* step);

void tmc_step_stop(struct tmc_step* step);

void tmc_step_count(struct tmc_step* step);

#endif //TMC_PLATFORM_H
