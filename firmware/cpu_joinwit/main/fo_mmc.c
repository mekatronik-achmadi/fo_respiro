/*
              UNKNOWN PUBLIC LICENSE

 Copyright (C) 2019 Achmadi S.T. M.T.

 Currently no license applied because author liv in
 Indonesia, a country which doesn't really concern
 about digital content copyright.

 */

/**
 * @file    fo_mmc.c
 * @brief   MMC-SPI FAT-FS code.
 *
 * @addtogroup Storage
 * @{
 */

#include "fo_mmc.h"

/**
 * @brief Global MMC Driver Pointer
 */
MMCDriver MMCD1;

/**
 * @brief FatFS ready status flag
 */
static bool filesystem_ready=true;

/**
 * @brief MMC SPI Peripheral status flag
 */
static uint8_t mmc_spi_status_flag=MMC_SPI_OK;

/**
 * @brief SPI High-Clock NSS config
 */
static SPIConfig hs_spicfg = {NULL, GPIOA, 15, 0};

/**
 * @brief SPI Low-Clock NSS config
 */
static SPIConfig ls_spicfg = {NULL, GPIOA, 15, SPI_CR1_BR_2 | SPI_CR1_BR_1};

/**
 * @brief MMC config struct
 */
static MMCConfig mmccfg = {&SPID1, &ls_spicfg, &hs_spicfg};

/**
 * @brief Checking readiness FatFS
 * @details Must calling before mounting actual media MMC
 * @details Checking both Peripheral and Filesystem status
 * @param[in] uint8_t Status to change LED mode or not
 */
static FRESULT mmc_check(void){
    FATFS FatFs;
    FRESULT err;

    uint32_t clusters;
    FATFS *fsp;

    mmc_spi_status_flag=MMC_SPI_OK;
    filesystem_ready=false;
    err = FR_OK;

    if(mmcConnect(&MMCD1)){
        filesystem_ready = true;
        f_mount(&FatFs, "", 0);
    }
    else{
        err = f_mount(&FatFs, "", 0);
        if(err == FR_OK){filesystem_ready = true; }
        else{return err;}
    }

    if(!filesystem_ready){
        mmc_spi_status_flag=MMC_SPI_FAIL;
        return err;
    }

    mmc_spi_status_flag=MMC_SPI_ERROR;
    err = f_getfree("", &clusters, &fsp);
    if(err == FR_OK){ mmc_spi_status_flag=MMC_SPI_OK;}
    else{return err;}

    f_mount(0, "", 0);

    return err;
}

void fo_mmc_initCheck(void){
    FATFS FatFs;
    FRESULT err;

    uint32_t clusters;
    FATFS *fsp;

    mmc_spi_status_flag=MMC_SPI_OK;
    filesystem_ready=false;

    if(mmcConnect(&MMCD1)){
        filesystem_ready = true;
        err = f_mount(&FatFs, "", 0);
        if(err != FR_OK)return;
    }
    else{
        err = f_mount(&FatFs, "", 0);
        if(err == FR_OK){filesystem_ready = true;}
        else{return;}
    }

    if(!filesystem_ready)return;

    mmc_spi_status_flag=MMC_SPI_ERROR;
    err = f_getfree("", &clusters, &fsp);
    if(err != FR_OK)return;

    f_mount(0, "", 0);
}

void fo_mmc_Init(void){
//    palSetPadMode(GPIOC, 12, PAL_MODE_ALTERNATE(6) | PAL_STM32_OSPEED_HIGHEST); //MOSI
//    palSetPadMode(GPIOC, 11, PAL_MODE_ALTERNATE(6) | PAL_STM32_OSPEED_HIGHEST); //MISO
//    palSetPadMode(GPIOC, 10, PAL_MODE_ALTERNATE(6) | PAL_STM32_OSPEED_HIGHEST); //SCK
//    palSetPadMode(GPIOA, 15, PAL_MODE_OUTPUT_PUSHPULL | PAL_STM32_OSPEED_HIGHEST); //NSS
//    palSetPad(GPIOA, 15);

//    mmcObjectInit(&MMCD1);
//    mmcStart(&MMCD1, &mmccfg);

    chThdSleepMilliseconds(1000);
}

/** @} */
