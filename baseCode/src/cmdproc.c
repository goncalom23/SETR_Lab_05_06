/* ***************************************************** */
/* SETR 22/23, Paulo Pedreiras                           */
/* Base code for Unit Testing                            */
/*    Simple example of command processor                */
/*    Note that there are several simplifications        */
/*    E.g. Kp, Ti and Td usually are not integer values  */
/*    Code can (and should) be improved. E.g. error      */ 
/*        codes are "magic numbers" in the middle of the */
/*        code instead of being (defined) text literals  */
/* ***************************************************** */

#include <stdio.h>

#include "cmdproc.h"

/* PID parameters */
/* Note that in a real application these vars would be extern */
char Kp, Ti, Td;

/* Process variables */ 
/* Note that in a real application these vars would be extern */
int setpoint, output, error; 

/* Internal variables */
static char cmdString[MAX_CMDSTRING_SIZE];
static unsigned char cmdStringLen = 0; 

/* ************************************************************ */
/* Processes the the chars received so far looking for commands */
/* Returns:                                                     */
/*  	 0: if a valid command was found and executed           */ /* funcitonou tudo bem */
/* 	-1: if empty string found            						*/ /* não tem nenhum caracter na string */
/* 	-2: if there is no valid command found                      */ /* não tem nenhum comando associado */
/* 	-3: if a CS error is detected (command not executed)        */ /* erro de sintax */
/* 	-4: if string format is wrong 								*/	/* não ter inicializador ou terminador*/
/*	-5: incomplete command found                             	*/  /* TIPO orkgpodsfg 12 e nao ter o 3*/
/* ************************************************************ */
int cmdProcessor(void)
{
	int i;
	int j;
	int flag_SOF_SYM = 0;
	int flag_EOF_SYM = 0;
	
	/* Detect empty cmd string */
	if(cmdStringLen == 0)
	{
		resetCmdString();
		return EMPTY_STRING; 
	}
	
	/* Find index of SOF */
	for(i=0; i < cmdStringLen; i++) 
	{
		if(cmdString[i] == SOF_SYM) 
		{
 			flag_SOF_SYM = 1;
			break;
		}
	}

	/* Find index of EOF_SYM */
	for(j=0; j < cmdStringLen; j++) 
	{
		if(cmdString[j] == EOF_SYM) 
		{
			 flag_EOF_SYM = 1;
			break;
		}
	}
	
	if( (flag_SOF_SYM == 0) || (flag_EOF_SYM == 0))
	{
		resetCmdString();
		return WRONG_COMMAND_FORMAT;
	}

	/* If a SOF was found look for commands */
	if(i < cmdStringLen) 									/* means there is something writen */
	{
		if(cmdString[i+1] == 'P') /* P command detected */
		{ 
			if( (cmdString[i+2] == EOF_SYM) || (cmdString[i+3] == EOF_SYM) || (cmdString[i+4] == EOF_SYM) )
			{
			resetCmdString();
			return INCOMPLETE_COMMAND;
			}


			if( ( cmdString[i+2] < '1' || cmdString[i+2] > '9') || ( cmdString[i+3] < '1' || cmdString[i+3] > '9') || ( cmdString[i+4] < '1' || cmdString[i+4] > '9'))
			{

			resetCmdString();	
			return CS_ERROR_DETECTED;
			}

			if(cmdString[i+5] != EOF_SYM)
			{
			return WRONG_COMMAND_FORMAT;
			}

			Kp = cmdString[i+2];
			Ti = cmdString[i+3];
			Td = cmdString[i+4];

			resetCmdString();
			return EXIT_SUCESSFUL;
		}
		
		else if(cmdString[i+1] == 'S') /* S command detected */
		{ 
			if(cmdString[i+2] != EOF_SYM)
			{
				return WRONG_COMMAND_FORMAT;
			}

			printf("Setpoint = %d, Output = %d, Error = %d \n", setpoint, output, error);
			resetCmdString();
			return EXIT_SUCESSFUL;
		}			
	}

	resetCmdString();
	return NO_VALID_COMMAND_FOUND;
}

/* ******************************** */
/* Adds a char to the cmd string 	*/
/* Returns: 				        */
/*  	 0: if success 		        */
/* 		-6: if cmd string full 	    */
/* ******************************** */
int newCmdChar(unsigned char newChar)
{
	if(newChar > 127)
	{
		return CS_ERROR_DETECTED;
	}


	/* If cmd string not full add char to it */
	if (cmdStringLen < MAX_CMDSTRING_SIZE) 
	{
		cmdString[cmdStringLen] = newChar;
		cmdStringLen +=1;
		return EXIT_SUCESSFUL;		
	}
	
	/* If cmd string full return error */
	return FULL_STRING;
}

/* ************************** */
/* Resets the commanbd string */  
/* ************************** */
int resetCmdString(void)
{
	cmdStringLen = 0;		
	return EXIT_SUCESSFUL;
}