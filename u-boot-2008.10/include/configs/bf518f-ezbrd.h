/*
 * U-boot - Configuration file for BF518F EZBrd board
 */

#ifndef __CONFIG_BF518F_EZBRD_H__
#define __CONFIG_BF518F_EZBRD_H__

#include <asm/blackfin-config-pre.h>


/*
 * Processor Settings
 */
#define CONFIG_BFIN_CPU             bf518-0.0
#define CONFIG_BFIN_BOOT_MODE       BFIN_BOOT_PARA


/*
 * Clock Settings
 *	CCLK = (CLKIN * VCO_MULT) / CCLK_DIV
 *	SCLK = (CLKIN * VCO_MULT) / SCLK_DIV
 */
/* CONFIG_CLKIN_HZ is any value in Hz					*/
#define CONFIG_CLKIN_HZ			25000000
/* CLKIN_HALF controls the DF bit in PLL_CTL      0 = CLKIN		*/
/*                                                1 = CLKIN / 2		*/
#define CONFIG_CLKIN_HALF		0
/* PLL_BYPASS controls the BYPASS bit in PLL_CTL  0 = do not bypass	*/
/*                                                1 = bypass PLL	*/
#define CONFIG_PLL_BYPASS		0
/* VCO_MULT controls the MSEL (multiplier) bits in PLL_CTL		*/
/* Values can range from 0-63 (where 0 means 64)			*/
#define CONFIG_VCO_MULT			16
/* CCLK_DIV controls the core clock divider				*/
/* Values can be 1, 2, 4, or 8 ONLY					*/
#define CONFIG_CCLK_DIV			1
/* SCLK_DIV controls the system clock divider				*/
/* Values can range from 1-15						*/
#define CONFIG_SCLK_DIV			5


/*
 * Memory Settings
 */
/* This board has a 64meg MT48H32M16 */
#define CONFIG_MEM_ADD_WDTH	10
#define CONFIG_MEM_SIZE		64

#define CONFIG_EBIU_SDRRC_VAL	0x0096
#define CONFIG_EBIU_SDGCTL_VAL	(SCTLE | CL_3 | PASR_ALL | TRAS_6 | TRP_3 | TRCD_3 | TWR_2 | PSS)

#define CONFIG_EBIU_AMGCTL_VAL	(AMCKEN | AMBEN_ALL)
#define CONFIG_EBIU_AMBCTL0_VAL	(B1WAT_15 | B1RAT_15 | B1HT_3 | B1RDYPOL | B0WAT_15 | B0RAT_15 | B0HT_3 | B0RDYPOL)
#define CONFIG_EBIU_AMBCTL1_VAL	(B3WAT_15 | B3RAT_15 | B3HT_3 | B3RDYPOL | B2WAT_15 | B2RAT_15 | B2HT_3 | B2RDYPOL)

#define CFG_MONITOR_LEN		(384 * 1024)	/* Reserve 384 kB for monitor */
#define CFG_MALLOC_LEN		(384 * 1024)	/* Reserve 384 kB for malloc() (video/spi are big) */


/*
 * Network Settings
 */
#if !defined(__ADSPBF512__) && !defined(__ADSPBF514__)
#define ADI_CMDS_NETWORK	1
#define CONFIG_BFIN_MAC
#define CONFIG_BFIN_MAC_RMII
#define CONFIG_NETCONSOLE	1
#define CONFIG_NET_MULTI	1
#endif
#define CONFIG_HOSTNAME		bf518f-ezbrd
/* Uncomment next line to use fixed MAC address */
/* #define CONFIG_ETHADDR	02:80:ad:20:31:e8 */


/*
 * Flash Settings
 */
#if 0 /* parallel flash is busted in first spin of board */
#define CFG_FLASH_BASE		0x20000000
#define CFG_FLASH_CFI		/* The flash is CFI compatible */
#define CONFIG_FLASH_CFI_DRIVER	/* Use common CFI driver */
#define CFG_FLASH_PROTECTION
#define CFG_MAX_FLASH_BANKS	1	/* max number of memory banks */
#define CFG_MAX_FLASH_SECT	259	/* max number of sectors on one chip */
#if (CONFIG_BFIN_BOOT_MODE == BFIN_BOOT_SPI_MASTER)
#define CONFIG_ENV_IS_IN_EEPROM	1
#define CONFIG_ENV_OFFSET	0x4000
#else
#define CONFIG_ENV_IS_IN_FLASH	1
#define CONFIG_ENV_ADDR		0x20004000
#define CONFIG_ENV_OFFSET	0x4000
#endif
#define CONFIG_ENV_SECT_SIZE	0x2000	/* Total Size of Environment Sector */
#define ENV_IS_EMBEDDED_CUSTOM
#endif
#define CFG_NO_FLASH
#define CONFIG_ENV_IS_NOWHERE 1
#define CONFIG_ENV_SIZE		0x2000

/* CONFIG_SPI_BAUD controls the SPI peripheral clock divider		*/
/* Values can range from 2-65535					*/
/* SCK Frequency = SCLK / (2 * CONFIG_SPI_BAUD)				*/
#define CONFIG_SPI
#define CONFIG_SPI_BAUD			2
#define CONFIG_SPI_BAUD_INITBLOCK	4
#define CFG_I2C_FRAM


/*
 * I2C Settings
 */
#define CONFIG_BFIN_TWI_I2C	1
#define CONFIG_HARD_I2C		1
#define CFG_I2C_SPEED		50000
#define CFG_I2C_SLAVE		0


/*
 * Misc Settings
 */
#define CONFIG_RTC_BFIN
#define CONFIG_UART_CONSOLE	0


/*
 * Pull in common ADI header for remaining command/environment setup
 */
#include <configs/bfin_adi_common.h>

#include <asm/blackfin-config-post.h>

#endif
