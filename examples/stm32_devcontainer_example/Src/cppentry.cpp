void cppMain();

#include "FreeRTOS.h"
#include "cmsis_os.h"
#include "main.h"

extern "C" {
void cppEntry() { cppMain(); }
}

class LedBlinker {
public:
  LedBlinker() { HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, (GPIO_PinState)1); }
  ~LedBlinker() { HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, (GPIO_PinState)0); }
};

class Delayer {
private:
  LedBlinker *ledblinker;

public:
  Delayer() {
    ledblinker = new LedBlinker;
    osDelay(100);
  }
  ~Delayer() {
    delete ledblinker;
    osDelay(100);
  }
};

void cppMain() {
  for (;;) {
    {
      Delayer delayer;
    }
  }
}