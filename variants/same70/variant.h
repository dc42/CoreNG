/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_SAME70_H
#define _VARIANT_SAME70_H

#ifndef __SAME70Q21__
#error Wrong variant.h file included!
#endif

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		12000000

/** Master clock frequency */
#define VARIANT_MCK			150000000

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "Core.h"

#ifdef __cplusplus
#include "UARTClass.h"
#include "USARTClass.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

/**
 * Libc porting layers
 */
#if defined (__GNUC__) /* GCC CS3 */
# include <syscalls.h> /** RedHat Newlib minimal stub */
#endif

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

#define PORTA_PIN(n)	(n)
#define PORTB_PIN(n)	(32+n)
#define PORTC_PIN(n)	(64+n)
#define PORTD_PIN(n)	(96+n)
#define PORTE_PIN(n)	(128+n)

/*
 * SPI Interfaces
 */

// The following are correct for the XPLD, not for Duet 3
#define SPI_INTERFACE_ID	ID_SPI
#define APIN_SPI_MOSI		(117u)
#define APIN_SPI_MISO		(116u)
#define APIN_SPI_SCK		(118u)
#define APIN_SPI_SS0		(34u)

/*
 * UART/USART Interfaces
 */

// SerialUSB
#ifdef DUET3
# define USB_VBUS_PIN		(PORTC_PIN(21))		// this is for Duet 3, not present on the XPLD
#endif

// Serial
static const uint8_t APINS_UART0 = 139;
static const uint8_t APIN_UART0_RXD = 9;
static const uint8_t APIN_UART0_TXD = 10;
// Serial1
static const uint8_t APINS_UART1 = 140;
static const uint8_t APIN_UART1_RXD = 5;
static const uint8_t APIN_UART1_TXD = 6;

// HSMCI
static const uint8_t APIN_HSMCI_CLOCK = 134;
static const uint8_t APIN_HSMCI_DATA = 135;

// PHY
static const uint8_t APIN_GMAC_PHY_INTERRUPT = 136;
static const uint8_t APIN_GMAC_PHY_RESET = 137;
static const uint8_t APINS_GMAC_PHY = 138;

static const uint32_t MaxPinNumber = 133;						// last GPIO pin (PE05)

static const uint32_t PwmFastClock = 25000 * 255;				// fast PWM clock for Intel spec PWM fans that need 25kHz PWM
static const uint32_t PwmSlowClock = (25000 * 255) / 256;		// slow PWM clock to allow us to get slow speeds

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

extern UARTClass Serial;
extern UARTClass Serial1;

extern void ConfigurePin(const PinDescription& pinDesc);

#endif

#endif /* _VARIANT_SAME70_H */
