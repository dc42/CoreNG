 /**
 * \file
 *
 * \brief EMAC (Ethernet MAC) driver for SAM.
 *
 * Copyright (c) 2011-2015 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef CONF_ETH_H_INCLUDED
#define CONF_ETH_H_INCLUDED

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond


#if defined(__SAME70Q21__) || defined(__SAME70Q20B__) || defined(__SAME70Q21B__)

# include "gmac.h"

/**
 * LWIP_NETIF_TX_SINGLE_PBUF: if this is set to 1, lwIP tries to put all data
 * to be sent into one single pbuf. This is for compatibility with DMA-enabled
 * MACs that do not support scatter-gather.
 */
#define LWIP_NETIF_TX_SINGLE_PBUF                     1

/** Number of buffer for RX */
# define GMAC_RX_BUFFERS  3

/** Number of buffer for TX */
# define GMAC_TX_BUFFERS  3

/** MAC PHY operation max retry count */
# define MAC_PHY_RETRY_MAX 1000000

/** Ethernet MII/RMII mode */
# define ETH_PHY_MODE                                  GMAC_PHY_RMII

/** GMAC HW configurations */
# define BOARD_GMAC_PHY_ADDR   0

#else

/** EMAC PHY address */
# define BOARD_EMAC_PHY_ADDR  2
/*! EMAC RMII mode */
# define BOARD_EMAC_MODE_RMII 1

/** Number of buffer for RX */
# define EMAC_RX_BUFFERS  (32)

/** Number of buffer for TX */
# define EMAC_TX_BUFFERS  (8)

/** MAC PHY operation max retry count */
# define MAC_PHY_RETRY_MAX 1000000

/** Ethernet MII/RMII mode */
# define ETH_PHY_MODE                                  BOARD_EMAC_MODE_RMII

#endif

/** MAC address definition.  The MAC address must be unique on the network. */
#define ETHERNET_CONF_ETHADDR0                        0xBE
#define ETHERNET_CONF_ETHADDR1                        0xEF
#define ETHERNET_CONF_ETHADDR2                        0xDE
#define ETHERNET_CONF_ETHADDR3                        0xAD
#define ETHERNET_CONF_ETHADDR4                        0xFE
#define ETHERNET_CONF_ETHADDR5                        0xED

#if 0		// IP address etc. are set dynamically

/** The IP address being used. */
#define ETHERNET_CONF_IPADDR0                         192
#define ETHERNET_CONF_IPADDR1                         168
#define ETHERNET_CONF_IPADDR2                         0
#define ETHERNET_CONF_IPADDR3                         2

/** The gateway address being used. */
#define ETHERNET_CONF_GATEWAY_ADDR0                   192
#define ETHERNET_CONF_GATEWAY_ADDR1                   168
#define ETHERNET_CONF_GATEWAY_ADDR2                   0
#define ETHERNET_CONF_GATEWAY_ADDR3                   1

/** The network mask being used. */
#define ETHERNET_CONF_NET_MASK0                       255
#define ETHERNET_CONF_NET_MASK1                       255
#define ETHERNET_CONF_NET_MASK2                       255
#define ETHERNET_CONF_NET_MASK3                       0

#endif

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif /* CONF_ETH_H_INCLUDED */
