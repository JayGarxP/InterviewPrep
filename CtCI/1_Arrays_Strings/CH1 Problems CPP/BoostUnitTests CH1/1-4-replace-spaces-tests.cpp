#include <boost/test/unit_test.hpp>

// project being tested
#include "../CH1 Problems CPP/pch.h"
#include "../CH1 Problems CPP/1-4-replace-spaces.cpp"

#include <string>
#include <stdlib.h>     // for _countof
#include <stdio.h>      // for printf
#include <errno.h>      // for return values

/* Chapter 1 Arrays and Strings problem 1-4
*  Write a method to replace all spaces in a string with '%20'
*  assume string has space at end to hold additional chars
*  you are given the "True Length" of the string
*  Please use character array to do this "in place"
*/
BOOST_AUTO_TEST_CASE(test_1_4_space_replace)
{
	string input = "Mr John Smith    ";
	string output = "Mr%20John%20Smith";

	char buffer[80];
	// wow...
	rsize_t restrictedSize = sizeof(char) * 80;
	// copy input string into char buffer
	//strcpy(buffer, input.c_str()); // bad security... even for this...
	strcpy_s(buffer, restrictedSize, "Mr John Smith    ");
	// mangle string in place with URL friendly %20
	spaceReplaceInPlace(buffer, 80, 11);

	BOOST_TEST(buffer == output);

	//BOOST_TEST(spaceReplaceFreeStyle(input) == output);
	
}