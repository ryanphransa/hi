/*
   This projects depends of turning off
   watchdog verify interval
*/
#include <stdint.h>

/* Definicao dos registradores */
#define GPIO_OUT_REG    0x3FF44004 // Altera o estado dos GPIOs para 1 ou 0
#define GPIO_ENABLE_REG 0x3FF44020 // Define os GPIOs para saida
#define GPIO_IN_REG     0x3FF4403C // Le as entradas dos GPIOs
#define SENS_SAR_DAC_CTRL1_REG 0x3FF48898 // Registrador de configuracao (DAC control)
#define SENS_SAR_DAC_CTRL2_REG 0x3FF4889C // Registrador de configuracao (DAC output control)
#define RTCIO_PAD_DAC1_REG 0x3FF48484 // Registrador de configuracao

/* Definicao dos registrador de configuracao */
// SENS_SAR_DAC_CTRL1_REG:
#define SENS_SW_TONE_EN (1u << 16)
// RTCIO_PAD_DAC1_REG
#define RTCIO_PAD_PDAC1_XPD_DAC (1u << 18) /* Liga DAC1 */
#define RTCIO_PAD_PDAC1_DAC_XPD_FORCE (1u << 10) /* Forca DAC1 */

/* Frequencias */
#define NOTA_MUSICAL_R 2
#define NOTA_MUSICAL_Y 4
#define NOTA_MUSICAL_A 6
#define NOTA_MUSICAL_N 8

#define NOTA_MUSICAL_P 10
#define NOTA_MUSICAL_E 12

#define REG_READ(reg) (*(volatile uint32_t *)(reg))

int estado_interruptor = 0; /* frequency divider state (on or off) */

void definir_gpio_saida(volatile uint32_t* gpio_enable, uint32_t val) {
  *gpio_enable |= (1 << val);
}

void ligar_gpio_saida(volatile uint32_t* gpio_enable, volatile uint32_t* gpio_out) {
  *gpio_enable &= ~(1 << 25);
  *gpio_out &= ~(1 << 25);
  *gpio_out |= *gpio_enable;
}

int ler_gpio_entrada(int gpio_entrada) {
  if (gpio_entrada > 0)
    return ((REG_READ(GPIO_IN_REG)) >> gpio_entrada) & 0x01;
  else
    return 0;
}

void ligar_dac1(volatile uint32_t* dac1_config) {
  // Escrevendo no registrador:
  *dac1_config |= RTCIO_PAD_PDAC1_XPD_DAC;
  *dac1_config |= RTCIO_PAD_PDAC1_DAC_XPD_FORCE;
}

void interruptor(volatile uint32_t* dac_freq, int leitura_interruptor, int estado_interruptor, int nota_atual) {
  if (leitura_interruptor && !estado_interruptor) {
    *dac_freq = nota_atual/2  + SENS_SW_TONE_EN;
    estado_interruptor = 1;
  }
  else if (leitura_interruptor && estado_interruptor){
    estado_interruptor = 0;
  }
}

void desligar_gpio_saida(volatile uint32_t* gpio_enable, volatile uint32_t* gpio_out) {
  *gpio_out &= ~*gpio_enable;
}

void desligar_dac1(volatile uint32_t* dac1_config) {
  *dac1_config = 0;
}

void app_main(void)
{
  volatile uint32_t* gpio_out = (volatile uint32_t*)GPIO_OUT_REG;
  volatile uint32_t* gpio_enable = (volatile uint32_t*)GPIO_ENABLE_REG;
  volatile uint32_t* dac_freq = (volatile uint32_t*)SENS_SAR_DAC_CTRL1_REG;
  volatile uint32_t* dac1_config = (volatile uint32_t*)RTCIO_PAD_DAC1_REG;

  /* GPIOs que estao os botoes */
  uint32_t botao_gpio[31] = { 4, 16, 17, 5, 18, 19 };
  uint32_t interruptor_gpio[31] = { 21 };

  /* GPIOs que serao configurados como output */
  uint32_t gpio[31] = { 2 }; // LED

  definir_gpio_saida(gpio_enable, gpio[0]);

  int nota_atual = 0;
  while(1) {
    for (int i = 0; ; i++) {
      if (botao_gpio[i] > 0 && ler_gpio_entrada(botao_gpio[i]) && botao_gpio[i] != 21) {
        uint32_t gpio_entrada = botao_gpio[i];

        // Liga os GPIOs configurados no gpio_enable
        ligar_gpio_saida(gpio_enable, gpio_out);

        // Liga o DAC1 (GPIO 25), que eh a saida de som
        ligar_dac1(dac1_config);

        /* Definindo frequencia da onda a partir do botao pressionado */
        if (gpio_entrada == 4) {
          *dac_freq = NOTA_MUSICAL_R + SENS_SW_TONE_EN;
          nota_atual = NOTA_MUSICAL_R;
        }
        else if (gpio_entrada == 16) {
          *dac_freq = NOTA_MUSICAL_Y + SENS_SW_TONE_EN;
          nota_atual = NOTA_MUSICAL_Y;
        }
        else if (gpio_entrada == 17) {
          *dac_freq = NOTA_MUSICAL_A + SENS_SW_TONE_EN;
          nota_atual = NOTA_MUSICAL_A;
        }
        else if (gpio_entrada == 5) {
          *dac_freq = NOTA_MUSICAL_N + SENS_SW_TONE_EN;
          nota_atual = NOTA_MUSICAL_N;
        }
        else if (gpio_entrada == 18) {
          *dac_freq = NOTA_MUSICAL_P + SENS_SW_TONE_EN;
          nota_atual = NOTA_MUSICAL_P;
        }
        else if (gpio_entrada == 19) {
          *dac_freq = NOTA_MUSICAL_E + SENS_SW_TONE_EN;
          nota_atual = NOTA_MUSICAL_E;
        }
      }
      else if (i > 31) {
        desligar_gpio_saida(gpio_enable, gpio_out);
        desligar_dac1(dac1_config);

        break;
      }

      interruptor(dac_freq, ler_gpio_entrada(interruptor_gpio[0]), estado_interruptor, nota_atual);
    }
  }
}
