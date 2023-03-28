/**
 * \file:   cmdproc.h
 * \author: Gonçalo Martins <goncalom23@ua.pt> and Filipe Silva <filipe.msilva@ua.pt> base on the
 * example code provided by Prof. Paulo Pedreiras
 * 
 * \date March 20, 2023, 09:47 AM
 * \brief
 * Apropriate returns defines
 * Function prototypes
 */



#ifndef __CMD_PROC_H_
#define __CMD_PROC_H_

/* Some defines */
/* Other defines should be return codes of the functions */
/* E.g. #define CMD_EMPTY_STRING -1                      */

/* Doyxgen comments using the following inicializers, will point to the line they are at */

#define MAX_CMDSTRING_SIZE 10       /*!< MAX_CMDSTRING_SIZE Maximum size of the command string */
#define SOF_SYM '#'	                /*!< Start of Frame Symbol */
#define EOF_SYM '!'                 /*!< End of Frame Symbol */

#define EXIT_SUCESSFUL 0            /*!< Function worked as suposed                                  */
#define EMPTY_STRING -1             /*!< -1: if empty string found  	                             */
#define NO_VALID_COMMAND_FOUND -2   /*!< -2: if there is no valid command found                      */
#define CS_ERROR_DETECTED -3        /*!< -3: if a CS error is detected (checksum not correct)        */
#define WRONG_COMMAND_FORMAT -4     /*!< -4: if string format is wrong (No start or end frame)		 */
#define INCOMPLETE_COMMAND -5       /*!< -5: incomplete command found                             	 */
#define FULL_STRING -6              /*!< -6: if cmd string full 	                                 */
#define SYNTAX_ERROR_DETECTED -7    /*!< -7: if is detected a error in the syntax of the command     */
#define  CRC_ERROR_DETECTED -8 		/*!< -8: if there is an error on the CRC error check    		 */

#define POLYNOMIAL 0x07  /* CRC-8 polynomial */

/* Function prototypes */

unsigned char crc8(unsigned char *data, int length);

int cmdProcessor(void);

int newCmdChar(unsigned char newChar);

int resetCmdString(void);

#endif
