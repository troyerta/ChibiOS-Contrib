/*
    ChibiOS/RT - Copyright (C) 2014 Uladzimir Pylinsky aka barthess

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "ch.h"
#include "hal.h"

#include "onewire_test.h"

/*
 * Application entry point.
 */
int main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  /*
   * Connect PB8 to TIM4 channel 2, set open drain mode
   * and enable internal pullup for slave absence detection.
   */
  palSetPadMode(GPIOB, GPIOB_PIN8,
      PAL_MODE_ALTERNATE(2) | PAL_STM32_OTYPE_OPENDRAIN | PAL_STM32_PUDR_PULLUP);

  /*
   * Executes infinite onewire test code.
   */
  onewireTest();
  return 0;
}
