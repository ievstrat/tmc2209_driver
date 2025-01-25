#include "tmc_platform.h"

void tmc_gpio_write(struct tmc_gpio* gpio, int state){
    HAL_GPIO_WritePin(gpio->port, gpio->pin, state);
}

void tmc_step_setting(struct tmc_step* step, uint16_t steps, uint32_t speed_steps){
  uint16_t period;
  uint16_t pulse;
  uint16_t prescaler;

  step->steps = steps;

  if(speed_steps > 100){
    period = TIM_FREQUENCY/1000000;
  }
  else{
    period = TIM_FREQUENCY/1000;
  }
  __HAL_TIM_SET_AUTORELOAD(step->tim, period);

  step->pwm_config->OCMode = TIM_OCMODE_PWM1;
  step->pwm_config->Pulse = period / 2;
  step->pwm_config->OCPolarity = TIM_OCPOLARITY_HIGH;
  step->pwm_config->OCFastMode = TIM_OCFAST_DISABLE;

  HAL_TIM_PWM_ConfigChannel(step->tim, step->pwm_config, step->channel);

  prescaler = TIM_FREQUENCY / (speed_steps * period);
  __HAL_TIM_SET_PRESCALER(step->tim, prescaler);
}

void tmc_step_start(struct tmc_step* step){
  HAL_TIM_Base_Start_IT(step->tim);
  HAL_TIM_PWM_Start(step->tim, step->channel);
}

void tmc_step_stop(struct tmc_step* step){
  HAL_TIM_Base_Stop_IT(step->tim);
  HAL_TIM_PWM_Stop(step->tim, step->channel);
}

void tmc_step_count(struct tmc_step* step){
  if(step->steps == 0){
    tmc_step_stop(step);
  }
  else{
    step->steps --;
  }
}