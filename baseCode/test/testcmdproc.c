 /**
 * \file:   testcmdproc.c
 * \author: Gonçalo Martins <goncalom23@ua.pt> and Filipe Silva <filipe.msilva@ua.pt>
 *
 * \date March 20, 2023, 09:47 AM
 * \brief Testing module using Unity for cmdproc 
 * 
 */

#include <unity.h>
#include "cmdproc.h"
#include "crc8.h"

/*! Unity Function called at the beggining */
void setUp(void)											
{
	return;
}

/*! Unity Function called at the end 	  */
void tearDown(void)											
{
	return;
}

/*! Function using Unity used to test if the cmdProcessor returns EXIT_SUCESSFUL
*	when suposed to
*/
void test_cmdProcessor_EXIT_SUCESSFUL(void)
{
	resetCmdString();
    newCmdChar('#');
    newCmdChar('P');
    newCmdChar('1');
    newCmdChar('2');
    newCmdChar('3');
	unsigned char buffer1[] = {'P','1','2','3'};
    unsigned char crc1 = crc8(buffer1, 4);
	newCmdChar(crc1);
	newCmdChar('!');
	TEST_ASSERT_EQUAL_INT(EXIT_SUCESSFUL, cmdProcessor());	

	resetCmdString();
	newCmdChar('1');
	newCmdChar('1');
    newCmdChar('#');
    newCmdChar('P');
    newCmdChar('1');
    newCmdChar('2');
    newCmdChar('3');
	unsigned char buffer2[] = {'P','1','2','3'};
    unsigned char crc2 = crc8(buffer2, 4);
	newCmdChar(crc2);
	newCmdChar('!');
	TEST_ASSERT_EQUAL_INT(EXIT_SUCESSFUL, cmdProcessor());
}

/*! Function using Unity used to test if the newCmdChar returns EXIT_SUCESSFUL
*	when suposed to
*/
void test_newCmdChar_EXIT_SUCESSFUL(void)
{
	resetCmdString();
	TEST_ASSERT_EQUAL_INT(EXIT_SUCESSFUL, newCmdChar('3'));	

}

/*! Function using Unity used to test if the resetCmdString returns EXIT_SUCESSFUL
*	when suposed to
*/
void test_resetCmdString_EXIT_SUCESSFUL(void)
{
	TEST_ASSERT_EQUAL_INT(EXIT_SUCESSFUL, resetCmdString());	
}

/*! Function using Unity used to test if the cmdProcessor returns EMPTY_STRING
*	when suposed to
*/
void test_cmdProcessor_EMPTY_STRING(void)
{
	resetCmdString();
	TEST_ASSERT_EQUAL_INT(EMPTY_STRING, cmdProcessor());	
}

/*! Function using Unity used to test if the cmdProcessor returns NO_VALID_COMMAND_FOUND
*	when suposed to
*/
void test_cmdProcessor_NO_VALID_COMMAND_FOUND(void)
{
	resetCmdString();
    newCmdChar('#');
    newCmdChar('T');
    newCmdChar('1');
    newCmdChar('2');
    newCmdChar('3');
	newCmdChar('!');	
	TEST_ASSERT_EQUAL_INT(NO_VALID_COMMAND_FOUND, cmdProcessor());

	resetCmdString();
    newCmdChar('#');
	newCmdChar('1');
	newCmdChar('1');
    newCmdChar('P');
    newCmdChar('1');
    newCmdChar('2');
    newCmdChar('3');
	newCmdChar('!');
	TEST_ASSERT_EQUAL_INT(NO_VALID_COMMAND_FOUND, cmdProcessor());
}

/* Function using Unity used to test if the cmdProcessor returns CS_ERROR_DETECTED
*	when suposed to
void test_cmdProcessor_CS_ERROR_DETECTED(void)
{
	resetCmdString();
    newCmdChar('#');
    newCmdChar('P');
    newCmdChar('1');
    newCmdChar('2');
    newCmdChar('3');
	newCmdChar((unsigned char)('1'+'2'+'3'));
	newCmdChar('!');
	TEST_ASSERT_EQUAL_INT(CS_ERROR_DETECTED, cmdProcessor());

	resetCmdString();
    newCmdChar('#');
    newCmdChar('S');
    newCmdChar('1');
	newCmdChar('!');
	TEST_ASSERT_EQUAL_INT(CS_ERROR_DETECTED, cmdProcessor());
}*/

/*! Function using Unity used to test if the cmdProcessor returns CRC_ERROR_DETECTED
*	when suposed to
*/
void test_cmdProcessor_CRC_ERROR_DETECTED(void)
{
	resetCmdString();
    newCmdChar('#');
    newCmdChar('P');
    newCmdChar('1');
    newCmdChar('2');
    newCmdChar('3');
	unsigned char buffer1[] = {'P','1','2','4'};
    unsigned char crc1 = crc8(buffer1, 4);
	newCmdChar(crc1);
	newCmdChar('!');
	TEST_ASSERT_EQUAL_INT(CRC_ERROR_DETECTED, cmdProcessor());	
}


/*! Function using Unity used to test if the cmdProcessor returns WRONG_COMMAND_FORMAT
*	when suposed to
*/
void test_cmdProcessor_WRONG_COMMAND_FORMAT(void)
{
	resetCmdString();
	newCmdChar('P');
    newCmdChar('!');	

	TEST_ASSERT_EQUAL_INT(WRONG_COMMAND_FORMAT, cmdProcessor());

	resetCmdString();
	newCmdChar('#');
	newCmdChar('P');
	TEST_ASSERT_EQUAL_INT(WRONG_COMMAND_FORMAT, cmdProcessor());
}

/*! Function using Unity used to test if the cmdProcessor returns INCOMPLETE_COMMAND
*	when suposed to
*/
void test_cmdProcessor_INCOMPLETE_COMMAND(void)
{
	resetCmdString();
	newCmdChar('#');
	newCmdChar('P');
	newCmdChar('1');
	newCmdChar('!');
	TEST_ASSERT_EQUAL_INT(INCOMPLETE_COMMAND, cmdProcessor());
}

/*! Function using Unity used to test if the cmdProcessor returns FULL_STRING
*	when suposed to
*/
void test_newCmdChar_FULL_STRING(void)
{
	resetCmdString();
	int i;
	newCmdChar('#');
	newCmdChar('P');
	newCmdChar('1');
	newCmdChar('2');
	newCmdChar('3');
	for(i = 0 ; i < 12 ; i++)
	{
		newCmdChar('B');
	}
	newCmdChar('!');

	TEST_ASSERT_EQUAL_INT(FULL_STRING, newCmdChar('3'));
}

/*! Function using Unity used to test if the cmdProcessor returns SYNTAX_ERROR_DETECTED
*	when suposed to
*/
void test_cmdProcessor_SYNTAX_ERROR_DETECTED(void)
{
    resetCmdString();
    newCmdChar('#');
	newCmdChar('P');
	newCmdChar('1');
	newCmdChar('2');	
	newCmdChar('W');
	unsigned char buffer1[] = {'P','1','2','4'};
    unsigned char crc1 = crc8(buffer1, 4);
	newCmdChar(crc1);
	newCmdChar('!');
	TEST_ASSERT_EQUAL_INT(SYNTAX_ERROR_DETECTED, cmdProcessor());

	resetCmdString();
    newCmdChar('#');
	newCmdChar('P');
	newCmdChar('1');
	newCmdChar('R');	
	newCmdChar('3');
	unsigned char buffer2[] = {'P','1','2','4'};
    unsigned char crc2 = crc8(buffer2, 4);
	newCmdChar(crc2);
	newCmdChar('!');
	TEST_ASSERT_EQUAL_INT(SYNTAX_ERROR_DETECTED, cmdProcessor());

}


int main(void)
{
	UNITY_BEGIN();
	

	RUN_TEST(test_cmdProcessor_EXIT_SUCESSFUL);
	RUN_TEST(test_newCmdChar_EXIT_SUCESSFUL);
	RUN_TEST(test_resetCmdString_EXIT_SUCESSFUL);
	RUN_TEST(test_cmdProcessor_EMPTY_STRING);	
	RUN_TEST(test_cmdProcessor_NO_VALID_COMMAND_FOUND);

	/*RUN_TEST(test_cmdProcessor_CS_ERROR_DETECTED);*/
	RUN_TEST(test_cmdProcessor_CRC_ERROR_DETECTED);

	RUN_TEST(test_cmdProcessor_WRONG_COMMAND_FORMAT);
	RUN_TEST(test_cmdProcessor_INCOMPLETE_COMMAND);
	RUN_TEST(test_newCmdChar_FULL_STRING);
	RUN_TEST(test_cmdProcessor_SYNTAX_ERROR_DETECTED);		

	return UNITY_END();
}