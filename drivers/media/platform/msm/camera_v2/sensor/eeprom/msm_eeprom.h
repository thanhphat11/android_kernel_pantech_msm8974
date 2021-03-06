/* Copyright (c) 2011-2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#ifndef MSM_EEPROM_H
#define MSM_EEPROM_H

#include <linux/i2c.h>
#include <linux/gpio.h>
#include <mach/camera2.h>
#include <media/v4l2-subdev.h>
#include <media/msmb_camera.h>
#include "msm_camera_i2c.h"
#include "msm_camera_spi.h"
#include "msm_camera_io_util.h"
#include "msm_camera_dt_util.h"

struct msm_eeprom_ctrl_t;

#define DEFINE_MSM_MUTEX(mutexname) \
	static struct mutex mutexname = __MUTEX_INITIALIZER(mutexname)

#ifdef CONFIG_PANTECH_CAMERA
#define CONFIG_PANTECH_CAMERA_READ_EEPROM 
#define CONFIG_PANTECH_CAMERA_EEPROM_CHECKSUM
#define CCI_READ_MAX 12

#if defined(CONFIG_PANTECH_CAMERA_IMX135)
#ifdef CONFIG_PANTECH_CAMERA_READ_EEPROM
#define EEPROM_READ_BLOCK 256
#endif
#ifdef CONFIG_PANTECH_CAMERA_EEPROM_CHECKSUM
#define EEPROM_READ_CHECKSUM_BYTE 2
#define EEPROM_AWB_CHECKSUM_ADDR 0x06F8
#define EEPROM_LSC_CHECKSUM_ADDR 0x06FA
#define EEPROM_AF_CHECKSUM_ADDR 0x0700
#endif
#elif defined(CONFIG_PANTECH_CAMERA_IMX214)
#ifdef CONFIG_PANTECH_CAMERA_READ_EEPROM
 #define EEPROM_READ_BLOCK 64
#endif
#ifdef CONFIG_PANTECH_CAMERA_EEPROM_CHECKSUM
#define EEPROM_READ_CHECKSUM_BYTE 4
#define EEPROM_AWB_CHECKSUM_ADDR 0x7944
#define EEPROM_LSC_CHECKSUM_ADDR 0x7946
#define EEPROM_AF_CHECKSUM_ADDR 0x794C
#define EEPROM_AWB_BLOCK_SIZE 6
#endif
#endif
#endif

struct msm_eeprom_ctrl_t {
	struct platform_device *pdev;
	struct mutex *eeprom_mutex;

	struct v4l2_subdev sdev;
	struct v4l2_subdev_ops *eeprom_v4l2_subdev_ops;
	enum msm_camera_device_type_t eeprom_device_type;
	struct msm_sd_subdev msm_sd;
	enum cci_i2c_master_t cci_master;

	struct msm_camera_i2c_client i2c_client;
	uint32_t num_bytes;
	uint8_t *memory_data;
	uint8_t is_supported;
	struct msm_eeprom_board_info *eboard_info;
	uint32_t subdev_id;
#ifdef CONFIG_PANTECH_CAMERA_READ_EEPROM
	uint32_t set_block_bytes;
	bool is_increase_slave_address;
#endif 
};

#endif
