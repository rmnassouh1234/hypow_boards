# HYPOW BOARDS
Hypow custom boards for Arduino IDE

# Installation
1. Open Arduino IDE.
2. Go to *File->Preferences*
3. Copy this URL: https://raw.githubusercontent.com/rmnassouh1234/hypow_boards/main/package_hypow_index.json
4. Past in under "*Additional Boards Manager URLs:*" list
5. Close *Preferences* window
6. Go to *Tools->Board->Boards Manager...*
7. Type in the following in the search text input: "*Hypow*"
8. In search result click **Install** under the package titled **Hypow Boards**

The Hypow boards list will now be available to select from under *Tools->Board* list.

# Usage

## Hypow Dev Board

 | **Pin number**  | **PIN**   | **Label/Name**      | **Peripheral in use** / **Comments**               |
 | ----------- | ----- | --------------- | ------------------------------------------ |
 | **Analog**      |       |                 |                                            |
 | 0           | PA05  | PIN_ADC_VBUS    | ADC/AIN[5]                                 |
 | **Digital**     |       |                 |                                            |
 | 1           | PA22  | PIN_FUSB_INT    | EIC/EXTINT[6] / Input                      |
 | 2           | PB10  | PIN_EN_VBUS     | DOUT		   / Output                       |
 | 3           | PA23  | PIN_LED1        | DOUT		   / Output                       |
 | 4           | PA27  | PIN_LED2        | DOUT		   / Output                       |
 | 5           | PA28  | PIN_LED3        | DOUT		   / Output                       |
 | **EDBG/UART**   |       |                 |                                            |
 | 6           | PB22  | PIN_SERIAL_TX   | SERCOM5/PAD[2]                             |
 | 7           | PB23  | PIN_SERIAL_RX   | SERCOM5/PAD[3]                             |
 | **Wire**        |       |                 |                                            |
 | 8           | PA08  | SDA             | SERCOM0/PAD[0]                             |
 | 9           | PA09  | SCL             | SERCOM0/PAD[1]                             |
 | **USB**         |       |                 |                                            |
 | 10          | PA18  | USB_HOST_ENABLE | PIO_COM / Not Used (No host mode required) |
 | 11          | PA24  | USB_NEGATIVE    | USB/DM                                     |
 | 12          | PA25  | USB_POSITIVE    | USB/DP                                     |
 | **SWCLK/SWDIO** |       |                 |                                            |
 | 13          | PA30  | SWCLK           | SWCLK                                      |
 | 14          | PA31  | SWDIO           | SWDIO                                      |
 | **Crystal**     |       |                 |                                            |
 |             | PA00  | XIN32           | EIC/EXTINT[0] SERCOM1/PAD[0] TCC2/WO[0]    |
 |             | PA01  | XOUT32          | EIC/EXTINT[1] SERCOM1/PAD[1] TCC2/WO[1]    |


