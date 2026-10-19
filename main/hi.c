#include <stdio.h>
#include <stdint.h>

#define GPIO_OUT_REG    0x3FF44004
#define GPIO_OUT_ENABLE 0x3FF44020
#define GPIO_IN_REG     0x3FF4403C

#define REG_READ(reg) (*(volatile uint32_t *)(reg))

// #define LED_PIN 2

/*
   This projects depends of turning off
   watchdog verify interval
*/

void delay_ms(unsigned int ms)
{
  while(ms--) {
    for(int count = 0; count < 24000; count++) {
      /* Assembly code for giving a free cpu cycle
        to create a delay, nop -> NO OPERATION */
      __asm__ volatile ("nop");
    }
  }
}

size_t expoent(size_t x) {
  size_t result = 2;
  while(--x)
    result *= 2;

  return result;
}

void app_main(void)
{
  volatile uint32_t* gpio_out = (volatile uint32_t*)GPIO_OUT_REG;
  volatile uint32_t* gpio_enable = (volatile uint32_t*)GPIO_OUT_ENABLE;

  int button_gpio[31] = {0};
  button_gpio[4] = 1;
  button_gpio[16] = 1;

  int gpio[31] = {0};
  gpio[2] = 1;

  /* Enables LED pin as output */
  // *gpio_enable = (1 << LED_PIN);
  for (size_t i = 0; i <= 31; i++) {
    if (gpio[i] && !button_gpio[i]) {
      *gpio_enable += (1 << i);
    }
  }

  while(1) {
    for (size_t i = 0; ; i++) {
      if (button_gpio[i] && ((REG_READ(GPIO_IN_REG)) >> i) & 0x01) {
        printf("gpio_on\n");
        *gpio_out = *gpio_enable;
        break;
      }
      else if (i > 31) {
        printf("gpio_off\n");
        *gpio_out &= ~*gpio_enable;
        break;
      }
    }

    delay_ms(10); // timer is wrong, correct it
  }
}
