/*
 * U-boot - main board file
 *
 * Copyright (c) 2005-2008 Analog Devices Inc.
 *
 * Licensed under the GPL-2 or later.
 */

#include <common.h>
#include <config.h>
#include <command.h>
#include <net.h>
#include <netdev.h>
#include <asm/blackfin.h>
#include <asm/io.h>

DECLARE_GLOBAL_DATA_PTR;

int checkboard(void)
{
	printf("Board: Bluetechnix TCM-BF537 board\n");
	printf("       Support: http://www.bluetechnix.at/\n");
	return 0;
}

phys_size_t initdram(int board_type)
{
	gd->bd->bi_memstart = CFG_SDRAM_BASE;
	gd->bd->bi_memsize = CFG_MAX_RAM_SIZE;
	return CFG_MAX_RAM_SIZE;
}

#if defined(CONFIG_BFIN_MAC)
void board_get_enetaddr(unsigned char *mac_addr)
{
	/* make something up */
	const char s[] = __DATE__;
	size_t i;
	u32 cycles;
	for (i = 0; i < 6; ++i) {
	      asm("%0 = CYCLES;":"=r"(cycles));
		mac_addr[i] = cycles ^ s[i];
	}
	mac_addr[0] = (mac_addr[0] | 0x02) & ~0x01;	/* make it local unicast */
	return 0;
}

int board_eth_init(bd_t *bis)
{
	return bfin_EMAC_initialize(bis);
}
#endif
