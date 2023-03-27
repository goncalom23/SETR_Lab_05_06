#include <unity.h>
#include "cmdproc.h"

void setUp(void)								/* introduce necessary calculations */ 
{
	return;
}
void tearDown(void)
{
	return;
}


void test_cmdProcessor_EXIT_SUCESSFUL(void)
{
	resetCmdString();
    newCmdChar('#');
    newCmdChar('P');
    newCmdChar('1');
    newCmdChar('2');
    newCmdChar('3');
	newCmdChar('!');
	TEST_ASSERT_EQUAL_INT(EXIT_SUCESSFUL, cmdProcessor());	
}

void test_newCmdChar_EXIT_SUCESSFUL(void)
{
	resetCmdString();
	TEST_ASSERT_EQUAL_INT(EXIT_SUCESSFUL, newCmdChar('3'));	

}

void test_resetCmdString_EXIT_SUCESSFUL(void)
{
	TEST_ASSERT_EQUAL_INT(EXIT_SUCESSFUL, resetCmdString());	
}



void test_cmdProcessor_EMPTY_STRING(void)
{
	resetCmdString();
	TEST_ASSERT_EQUAL_INT(EMPTY_STRING, cmdProcessor());	
}

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
}


void test_cmdProcessor_CS_ERROR_DETECTED(void)
{
    resetCmdString();
    newCmdChar('#');
	newCmdChar('P');
	newCmdChar('1');
	newCmdChar('2');	
	newCmdChar('W');
    newCmdChar('!');	
	TEST_ASSERT_EQUAL_INT(CS_ERROR_DETECTED, cmdProcessor());

	resetCmdString();
    newCmdChar('#');
	newCmdChar('P');
	newCmdChar('1');
	newCmdChar('R');	
	newCmdChar('3');
    newCmdChar('!');	
	TEST_ASSERT_EQUAL_INT(CS_ERROR_DETECTED, cmdProcessor());

}

void test_newCmdChar_CS_ERROR_DETECTED(void)
{
	TEST_ASSERT_EQUAL_INT(CS_ERROR_DETECTED, newCmdChar((unsigned char)('P'+'1'+'2'+'3')));
}


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

	resetCmdString();
	newCmdChar('#');
	newCmdChar('P');
	newCmdChar('1');
	newCmdChar('2');
	newCmdChar('3');
	newCmdChar('4');	
	newCmdChar('!');
	TEST_ASSERT_EQUAL_INT(WRONG_COMMAND_FORMAT, cmdProcessor());

	resetCmdString();
	newCmdChar('#');
	newCmdChar('S');
	newCmdChar('1');
	newCmdChar('!');
	TEST_ASSERT_EQUAL_INT(WRONG_COMMAND_FORMAT, cmdProcessor());
	
}

void test_cmdProcessor_INCOMPLETE_COMMAND(void)
{
	resetCmdString();
	newCmdChar('#');
	newCmdChar('P');
	newCmdChar('1');
	newCmdChar('!');
	TEST_ASSERT_EQUAL_INT(INCOMPLETE_COMMAND, cmdProcessor());
}

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

int main(void)
{
	UNITY_BEGIN();
	

	RUN_TEST(test_cmdProcessor_EXIT_SUCESSFUL);
	RUN_TEST(test_newCmdChar_EXIT_SUCESSFUL);
	RUN_TEST(test_resetCmdString_EXIT_SUCESSFUL);


	RUN_TEST(test_cmdProcessor_EMPTY_STRING);	
	RUN_TEST(test_cmdProcessor_NO_VALID_COMMAND_FOUND);
	RUN_TEST(test_cmdProcessor_CS_ERROR_DETECTED);	
	RUN_TEST(test_newCmdChar_CS_ERROR_DETECTED);
	RUN_TEST(test_cmdProcessor_WRONG_COMMAND_FORMAT);
	RUN_TEST(test_cmdProcessor_INCOMPLETE_COMMAND);
	RUN_TEST(test_newCmdChar_FULL_STRING);

	return UNITY_END();
}