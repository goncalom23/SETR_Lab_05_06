#ifndef __CMD_PROC_H_
#define __CMD_PROC_H_

/* Some defines */
/* Other defines should be return codes of the functions */
/* E.g. #define CMD_EMPTY_STRING -1                      */
#define MAX_CMDSTRING_SIZE 10 /* Maximum size of the command string */ 
#define SOF_SYM '#'	          /* Start of Frame Symbol */
#define EOF_SYM '!'           /* End of Frame Symbol */
#define Exit_Successful 0
#define EMPTY_STRING -1
#define invalid_command_found -2
#define CS_error_detected -3
#define wrong_string_format  -4
#define INCOMPLETE_COMMAND -5
#define FULL_STRING -6


/* Function prototypes */
int cmdProcessor(void);
int newCmdChar(unsigned char newChar);
void resetCmdString(void);

#endif
