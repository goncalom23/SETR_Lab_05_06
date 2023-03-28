/**
 * \file:   crc8.h
 * \author: Gonçalo Martins <goncalom23@ua.pt> and Filipe Silva <filipe.msilva@ua.pt>
 * 
 * \date March 20, 2023, 09:47 AM
 * \brief
 * Apropriate returns defines for the crc8 and respective function prototypes
 */

#ifndef crc8_H
#define crc8_H

/* Some defines */
/* Other defines should be return codes of the functions */
/* E.g. #define CMD_EMPTY_STRING -1                      */

/* Doyxgen comments using the following inicializers, will point to the line they are at */

#define POLYNOMIAL 0x07                 /*!< CRC-8 polynomial */

unsigned char crc8(unsigned char *data, int length);
#endif
