/*
 * Copyright (C) 2013-2016, Shenzhen Huiding Technology Co., Ltd.
 * All Rights Reserved.
 */
#ifndef __GF_SPI_REE_H
#define __GF_SPI_REE_H

#include <linux/types.h>

/**********************feature defination**********************/
#define HIGH_SPEED 6
#define LOW_SPEED  1

/**********************function defination**********************/
extern void gf_spi_setup_conf_ree(u32 speed, enum spi_transfer_mode mode);
extern int gf_spi_read_bytes_ree(u16 addr, u32 data_len, u8 *rx_buf);
extern int gf_spi_write_bytes_ree(u16 addr, u32 data_len, u8 *tx_buf);
extern int gf_spi_read_byte_ree(u16 addr, u8 *value);
extern int gf_spi_write_byte_ree(u16 addr, u8 value);

#endif	/* __GF_SPI_REE_H */
