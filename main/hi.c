#include <stdio.h>
#include <stdint.h>

#define GPIO_OUT_REG    0x3FF44004 /* output GPIO 0-31 value */

#define GPIO_ENABLE_REG 0x3FF44020 /* verify if a GPIO is enabled
                                    * or enable it
                                    */

#define GPIO_IN_REG     0x3FF4403C /* verify if GPIO has input
                                    * using REG_READ
                                    */
#define SENS_SAR_DAC_CTRL1_REG 0x3FF48898
#define SENS_SAR_DAC_CTRL2_REG 0x3FF4889C
/*
 * Adjust frequency of CW with SENS_SAR_SW_FSTEP [15:0]
 * freq = dig_clk_rtc_freq * SENS_SAR_SW_FSTEP / 65536
 * the frequency of dig_clk_rtc is typically 8MHz
 */
#define RTCIO_PAD_DAC1_REG 0x3FF48484
#define RTCIO_PAD_DAC2_REG 0x3FF48488

#define REG_READ(reg) (*(volatile uint32_t *)(reg))

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

void app_main(void)
{
  volatile uint32_t* gpio_out = (volatile uint32_t*)GPIO_OUT_REG;
  volatile uint32_t* gpio_enable = (volatile uint32_t*)GPIO_ENABLE_REG;
  volatile uint32_t* dac_freq = (volatile uint32_t*)SENS_SAR_DAC_CTRL1_REG;
  volatile uint32_t* dac_power_on = (volatile uint32_t*)RTCIO_PAD_DAC1_REG;
  volatile uint32_t* dac_cw = (volatile uint32_t*)SENS_SAR_DAC_CTRL2_REG;

  *dac_cw = 1 << 24;

  //*dac_power_on = (1 << 10) + (1 << 18);  // dac power on
  /* tristate now */
  *dac_power_on += 0 << 27; // RUE OFF
  *dac_power_on += 0 << 28; // RDE OFF
  *dac_power_on += 0 << 11; // FUN_IE OFF
  *dac_power_on += 0 << 12; // SLP_OE OFF
  *dac_power_on += 0 << 13; // SLP_IE OFF

  *dac_freq = (1 << 16); // SENS_SW_FSTEP Frequency step for CW generator;
                         // can be used to adjust the frequency.

  *dac_freq += (1 << 3); // define freq

  int button_gpio[31] = {0};
  button_gpio[4] = 1;
  button_gpio[16] = 1;
  button_gpio[17] = 1;
  button_gpio[5] = 1;

  int gpio[31] = {0};
  gpio[2] = 1;
  gpio[25] = 1;

  /* Enables LED pin as output */
  for (size_t i = 0; i <= 31; i++) {
    if (gpio[i] && !button_gpio[i]) {
      *gpio_enable += (1 << i);
    }
  }

  while(1) {
    for (size_t i = 0; ; i++) {
      if (button_gpio[i] && ((REG_READ(GPIO_IN_REG)) >> i) & 0x01) {
        //printf("gpio_on\n");
        *gpio_out = *gpio_enable;
        *dac_power_on = (1 << 10) + (1 << 18);  // dac power on
        if (i == 4)
          *dac_freq = (1 << 4) + (1 << 16);
        else if (i == 16)
          *dac_freq = (1 << 3) + (1 << 16);
        else if (i == 17)
          *dac_freq = (1 << 2) + (1 << 16);
        else if (i == 5)
          *dac_freq = (1 << 1) + (1 << 16);
        break;
      }
      else if (i > 31) {
        //printf("gpio_off\n");
        *gpio_out &= ~*gpio_enable;
        *dac_power_on = (0 << 10) + (0 << 18);  // dac power off
        break;
      }
    }

    delay_ms(10); // timer is wrong, correct it
  }
}
