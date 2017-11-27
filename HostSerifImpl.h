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

#ifndef _HOSTSERIFIMPL_H_
#define _HOSTSERIFIMPL_H_
#include "stdint.h"

#include "Invn/Devices/HostSerif.h"

#ifdef __cplusplus
extern "C" {
#endif


/** @brief Return handle to Serif for SPI
 */
const inv_host_serif_t * idd_io_hal_get_serif_instance_spi(void);

#ifdef __cplusplus
}
#endif

#endif /* _HOSTSERIFIMPL_H_*/