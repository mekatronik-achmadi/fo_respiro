/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    fo_mmc.h
 * @brief   MMC-SPI FAT-FS header.
 *
 * @addtogroup Storage
 * @{
 */

#ifndef FO_MMC_H
#define FO_MMC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "ff.h"

#define MMC_SPI_OK      0
#define MMC_SPI_FAIL    1
#define MMC_SPI_ERROR   2

/**
 * @brief File buffer maximal size
 * @details More than 256 cause all system freeze
 */
#define STR_BUFF_SIZE 128

/**
 * @brief Define whether scan directory recursively or files only
 * @details Highly recommended to disable it as still buggy
 */
#define USE_SCAN_DIR FALSE

/**
 * @brief rename to match name f_write()
 */
#define f_readline   f_gets

/**
 * @brief Check MMC readyness
 */
void fo_mmc_initCheck(void);

/**
 * @brief Initialize MMC-SPI peripherals
 */
void fo_mmc_Init(void);

#endif // FO_MMC_H
/** @} */
