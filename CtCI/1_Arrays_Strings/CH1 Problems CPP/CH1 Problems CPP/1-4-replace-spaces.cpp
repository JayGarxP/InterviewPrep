#include "pch.h"
#include "1-4-replace-spaces.hpp"

// Implementation true to CtCI book
void spaceReplaceInPlace(char * buff, int buffSize, int cCount)
{
	// whiteboard code; did not compile had to debug it; I had off by ones and logical errors
	//		need to seperate indexes for each buffer; can't just use one.

	// save copy of input buffer string
	// traverse input string;
	// when encouncer ' ' overwrite with '%20' instead; resume writing from previous index
	// each valid character processed decrement cCount AKA "True Length" of string

	string input = buff; // doesn't really count as in place anymore...
	int charstoApprove = cCount;

	int i = 0;
	int j = 0;
	while (charstoApprove > 0)
	{
		if (input[i] == ' ')
		{
			buff[j] = '%';
			buff[++j] = '2';
			buff[++j] = '0';
		}
		else 
		{
			// character is fine where it is
			charstoApprove--;
			buff[j] = input[i];
		}

		i++;
		j++;
	}
}
