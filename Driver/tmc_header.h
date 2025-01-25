#ifndef TMC_HEADER_H
#define TMC_HEADER_H

#include <stdint.h>
#include "tmc_platform.h"

struct tmc_header {
  struct tmc_gpio *tmc_en;
  struct tmc_gpio *tmc_dir;
  struct tmc_gpio *tmc_ms1;
  struct tmc_gpio *tmc_ms2;

  struct tmc_step *step;

  struct tmc_uart *uart;

  uint8_t uart_addr;
  uint32_t step_speed;
};

#endif //TMC_HEADER_H
