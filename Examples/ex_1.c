#include "tmc2209_driver.h"
#include "main.h"

struct tmc_header tmc_1;

struct tmc_gpio tmc_en_1;
struct tmc_gpio tmc_dir_1;
struct tmc_gpio tmc_ms1_1;
struct tmc_gpio tmc_ms2_1;

struct tmc_step step_1;
TIM_OC_InitTypeDef step_config_1;

struct tmc_uart uart_1;

extern TIM_HandleTypeDef htim2;
extern UART_HandleTypeDef huart1;

void tmc_example(){
  tmc_en_1.port = TMC1_EN_GPIO_Port;
  tmc_en_1.pin = TMC1_EN_Pin;

  tmc_dir_1.port = TMC1_DIR_GPIO_Port;
  tmc_dir_1.pin = TMC1_DIR_Pin;

  tmc_ms1_1.port = TMC_MS1_GPIO_Port;
  tmc_ms1_1.pin = TMC_MS1_Pin;

  tmc_ms2_1.port = TMC_MS2_GPIO_Port;
  tmc_ms2_1.pin = TMC_MS2_Pin;

  step_1.tim = &htim2;
  step_1.pwm_config = &step_config_1;
  step_1.channel = TIM_CHANNEL_1;

  uart_1.uart = &huart1;


  tmc_1.tmc_en = &tmc_en_1;
  tmc_1.tmc_dir = &tmc_dir_1;
  tmc_1.tmc_ms1 = &tmc_ms1_1;
  tmc_1.tmc_ms2 = &tmc_ms2_1;
  tmc_1.step = &step_1;
  tmc_1.uart = &uart_1;

  tmc_gpio_write(tmc_1.tmc_en, 1);
  tmc_gpio_write(tmc_1.tmc_dir, 1);
  tmc_gpio_write(tmc_1.tmc_ms1, 1);
  tmc_gpio_write(tmc_1.tmc_ms2, 1);

  tmc_step_setting(tmc_1.step, 100, 5);
  tmc_step_start(tmc_1.step);

  while(1);
}