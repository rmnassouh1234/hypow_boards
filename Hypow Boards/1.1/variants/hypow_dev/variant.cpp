/*
  Hypow Dev Board Variant
*/
/*
 * +------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * + Pin number |  PIN   | Label/Name      | Peripheral in use / Comments
 * +------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Analog     |        |                 |
 * +------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 0          |  PA05  | PIN_ADC_VBUS    | ADC/AIN[5]
 * +------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Digital    |        |                 |
 * +------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 1          |  PA22  | PIN_FUSB_INT    | EIC/EXTINT[6] / Input
 * | 2          |  PB10  | PIN_EN_VBUS     | DOUT		   / Output
 * | 3          |  PA23  | PIN_LED1        | DOUT		   / Output
 * | 4          |  PA27  | PIN_LED2        | DOUT		   / Output
 * | 5          |  PA28  | PIN_LED3        | DOUT		   / Output
 * +------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | EDBG/UART  |        |                 |
 * +------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 6          |  PB22  | PIN_SERIAL_TX   | SERCOM5/PAD[2]
 * | 7          |  PB23  | PIN_SERIAL_RX   | SERCOM5/PAD[3]
 * +------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Wire       |        |                 |
 * +------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 8          |  PA08  | SDA             | SERCOM0/PAD[0]
 * | 9          |  PA09  | SCL             | SERCOM0/PAD[1]
 * +------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | USB        |        |                 |
 * +------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 10         |  PA18  | USB_HOST_ENABLE | PIO_COM / Not Used (No host mode required)
 * | 11         |  PA24  | USB_NEGATIVE    | USB/DM
 * | 12         |  PA25  | USB_POSITIVE    | USB/DP
 * +------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | SWCLK/SWDIO|        |                 |
 * +------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 13         |  PA30  | SWCLK           | SWCLK
 * | 14         |  PA31  | SWDIO           | SWDIO
 * +------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | Crystal    |        |                 |
 * +------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            |  PA00  | XIN32           | EIC/EXTINT[0] SERCOM1/PAD[0] TCC2/WO[0]
 * |            |  PA01  | XOUT32          | EIC/EXTINT[1] SERCOM1/PAD[1] TCC2/WO[1]
 * +------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */


#include "variant.h"

/*
 * Pins descriptions
 */
const PinDescription g_APinDescription[]=
{
  // 0 - Analog pin
  // ----------------------
  { PORTA,  5, PIO_ANALOG, 0, ADC_Channel5, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 }, // ADC / AIN[5] / VBUS

  // 1..5 - Digital pins
  // ----------------------
  { PORTA, 22, PIO_EXTINT, (PIN_ATTR_DIGITAL|PIN_ATTR_EXTINT), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 }, // D0 / EXTINT[6] / FUSB INT
  { PORTB, 10, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // D1 / DOUT / EN_VBUS
  { PORTA, 23, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // D2 / DOUT / LED 1
  { PORTA, 27, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // D3 / DOUT / LED 2
  { PORTA, 28, PIO_OUTPUT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // D4 / DOUT / LED 3
  
  // 6..7 - EDBG/UART
  // ----------------------
  { PORTB, 22, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // TX: SERCOM5/PAD[2]
  { PORTB, 23, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // RX: SERCOM5/PAD[3]
  
  // 8..9 I2C pins (SDA/SCL)
  // ----------------------
  { PORTA,  9, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9 },    // SCL: SERCOM0/PAD[1]
  { PORTA,  8, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NMI },  // SDA: SERCOM0/PAD[0]

  // 10..12 - USB
  // --------------------
  { PORTA, 18, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB Host enable
  { PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DM
  { PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DP

  // ----------------------
  // 13..14 - SWCLK, SWDIO
  { PORTA, 30, PIO_PWM, PIN_ATTR_DIGITAL|PIO_SERCOM, No_ADC_Channel, NOT_ON_PWM, TCC1_CH0, EXTERNAL_INT_10 }, // SWCLK
  { PORTA, 31, PIO_PWM, PIN_ATTR_DIGITAL|PIO_SERCOM, No_ADC_Channel, NOT_ON_PWM, TCC1_CH1, EXTERNAL_INT_11 }, // SWDIO
} ;

extern "C" {
    unsigned int PINCOUNT_fn() {
        return (sizeof(g_APinDescription) / sizeof(g_APinDescription[0]));
    }
}

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5 } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;

Uart Serial( &sercom5, PIN_SERIAL_RX, PIN_SERIAL_TX, PAD_SERIAL_RX, PAD_SERIAL_TX ) ;

void SERCOM5_Handler()
{
  Serial.IrqHandler();
}

