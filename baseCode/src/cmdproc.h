#ifndef __CMD_PROC_H_
#define __CMD_PROC_H_

/* Some defines */
/* Other defines should be return codes of the functions */
/* E.g. #define CMD_EMPTY_STRING -1                      */
#define MAX_CMDSTRING_SIZE 10 /* Maximum size of the command string */ 
#define SOF_SYM '#'	          /* Start of Frame Symbol */
#define EOF_SYM '!'           /* End of Frame Symbol */


#define EXIT_SUCESSFUL 0    /* funcitonou tudo bem */
#define EMPTY_STRING -1         /* -1: if empty string found  	*/ /* não tem nenhum caracter na string */ 
#define NO_VALID_COMMAND_FOUND -2/* 	-2: if there is no valid command found                      */ /* não tem nenhum comando associado */
#define CS_ERROR_DETECTED -3/* 	-3: if a CS error is detected (command not executed)        */ /* erro de sintax */
#define WRONG_COMMAND_FORMAT -4/* 	-4: if string format is wrong 								*/	/* não ter inicializador ou terminador*/
#define INCOMPLETE_COMMAND -5/*	-5: incomplete command found                             	*/  /* TIPO orkgpodsfg 12 e nao ter o 3*/
#define FULL_STRING -6/* 		-6: if cmd string full 	    */


/* Function prototypes */
int cmdProcessor(void);
int newCmdChar(unsigned char newChar);
int resetCmdString(void);

#endif
