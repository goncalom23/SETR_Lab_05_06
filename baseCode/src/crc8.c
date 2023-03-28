 /**
 * \file:   crc8.c
 * \author: Gonçalo Martins <goncalom23@ua.pt> and Filipe Silva <filipe.msilva@ua.pt>
 *
 * \date March 20, 2023, 09:47 AM
 * \brief CRC - Cyclic Redundancy Check with 8 bits
 * 
 */

#include "crc8.h"

/** \brief
 *  Calculates the crc with 8bits (unsigned char size)
 *  \param[in] data buffer with the message to calculate the CRC
 *  \param[in] length length of the message
 *	\return                        
 *	crc: generated crc value                                                      	 
 */ 
unsigned char crc8(unsigned char *data, int length) 
{
    unsigned char crc = 0;  /* Initial CRC value */ 
    int i, j;
    for (i = 0; i < length; i++) {
        crc ^= data[i];  /* XOR the next byte into the CRC*/
        for (j = 0; j < 8; j++) {
            if (crc & 0x80) {
                crc = (crc << 1) ^ POLYNOMIAL;  /* If the top bit is 1, shift and XOR the polynomial*/
            } else {
                crc <<= 1;  /* If the top bit is 0, just shift*/
            }
        }
    }

    return crc;
}