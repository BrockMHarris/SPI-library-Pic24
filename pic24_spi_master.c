/*
 * File:   spi.c
 * Author: Brock Harris
 *
 * Created on July 21, 2018, 5:40 PM
 */

#include <stdint.h>
#include "pic24_spi.h"
#include "pic24_spi_master.h"


void spi_begin(void){
    SPI1STAT = (SPI_ENABLE | SPI_IDLE_CON);
    SPI1CON1 = (MASTER_ENABLE_ON | SPI_MODE16_ON);
}

void spi_end(void){
    SPI1CON1 = MASTER_ENABLE_ON;
}

void spi_beginTransaction(SPISettings mySettings){
    setDataMode(mySettings.mode);
    //setBitOrder(mySettings.Order);
}

void spi_endTransaction(void){
    
}

void setBitOrder(bitOrder order){
    
}

void spi_setClockDivider(void){
    
}

void setDataMode(dataMode mode){
    switch(mode){
        case SPI_MODE0:
            SPI1CON1 |= SPI_CKE_ON;
            SPI1CON1 |= CLK_POL_ACTIVE_LOW;
            break;
        case SPI_MODE1:
            SPI1CON1 |= SPI_CKE_OFF;
            SPI1CON1 |= CLK_POL_ACTIVE_LOW;
            break;
        case SPI_MODE2:
            SPI1CON1 |= SPI_CKE_ON;
            SPI1CON1 |= CLK_POL_ACTIVE_HIGH;
            break;
        case SPI_MODE3:
            SPI1CON1 |= SPI_CKE_OFF;
            SPI1CON1 |= CLK_POL_ACTIVE_HIGH;
            break;
    }
}

uint16_t spi_transfer(uint16_t val16){
    return ioMasterSPI1(uint16_t val16);
}

void spi_usingInterrupt(void){
    
}
