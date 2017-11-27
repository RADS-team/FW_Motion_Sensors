/*
 * ________________________________________________________________________________________________________
 * Copyright (c) 2015-2015 RADS Inc. All rights reserved.
 *
 * This software, related documentation and any modifications thereto (collectively “Software”) is subject
 * to RADS and its licensors' intellectual property rights under FRANCE. and international copyright
 * and other intellectual property rights laws.
 *
 * RADS and its licensors retain all intellectual property and proprietary rights in and to the Software
 * and any use, reproduction, disclosure or distribution of the Software without an express license agreement
 * from RADS is strictly prohibited.
 *
 * EXCEPT AS OTHERWISE PROVIDED IN A LICENSE AGREEMENT BETWEEN THE PARTIES, THE SOFTWARE IS
 * PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * EXCEPT AS OTHERWISE PROVIDED IN A LICENSE AGREEMENT BETWEEN THE PARTIES, IN NO EVENT SHALL
 * INVENSENSE BE LIABLE FOR ANY DIRECT, SPECIAL, INDIRECT, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, OR ANY
 * DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THE SOFTWARE.
 * ________________________________________________________________________________________________________
 */

#include "HostSerifImpl.h" //in Invn example named idd_io_hal.h

// board drivers
#include "nrf_drv_spi.h"
#include "nrf_delay.h"

#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define READ_BIT_MASK 0x80

/* TODO    Implement Non blocking mode for SPI */

static const nrf_drv_spi_t m_spi_master_0 = NRF_DRV_SPI_INSTANCE(0);

/* Host Serif object definition for SPI ***************************************/

static int idd_io_hal_init_spi(void)
{     
    nrf_drv_spi_config_t config = NRF_DRV_SPI_DEFAULT_CONFIG;
    config.sck_pin   = SPI0_CONFIG_SCK_PIN;
    config.miso_pin  = SPI0_CONFIG_MISO_PIN;
    config.mosi_pin  = SPI0_CONFIG_MOSI_PIN;
    config.ss_pin    = SPI0_CONFIG_SS_PIN;
    config.frequency = NRF_DRV_SPI_FREQ_1M;
    config.mode      = NRF_DRV_SPI_MODE_0;
    config.bit_order = NRF_DRV_SPI_BIT_ORDER_MSB_FIRST;
    ;
    return (nrf_drv_spi_init(&m_spi_master_0, &config, NULL,NULL) == NRF_SUCCESS ? 0:-1);
}

static int idd_io_hal_read_reg_spi(uint8_t reg, uint8_t * rbuffer, uint32_t rlen)
{
        uint8_t buf [rlen+1];
        reg = READ_BIT_MASK | reg;
        int error = NRF_SUCCESS;
        error = nrf_drv_spi_transfer(&m_spi_master_0,&reg,1,buf, rlen+1);
        for (int i = 1; i< rlen+1;i++)
          rbuffer[i-1] = buf[i];
         return (error  == NRF_SUCCESS ? 0:-1); 
}

static int idd_io_hal_write_reg_spi(uint8_t reg, const uint8_t * wbuffer, uint32_t wlen)
{
        uint8_t write[wlen+1];
        write [0] = reg;
        for (int i = 1; i<(wlen+1); i++)
          write [i]=wbuffer[i-1];
	return (nrf_drv_spi_transfer (&m_spi_master_0, write,wlen+1, NULL, 0)== NRF_SUCCESS ? 0:-1);
}

static const inv_host_serif_t serif_instance_spi = {
	idd_io_hal_init_spi,
	0,
	idd_io_hal_read_reg_spi,
	idd_io_hal_write_reg_spi,
	0,
	1024*32, /* max transaction size */
	1024*32, /* max transaction size */
	INV_HOST_SERIF_TYPE_SPI,
};

const inv_host_serif_t * idd_io_hal_get_serif_instance_spi(void)
{
	return &serif_instance_spi;
}

static int idd_io_hal_uinit_spi(void) //Implementation of SPI close
{
        nrf_drv_spi_uninit(&m_spi_master_0);
        return 0;
}
