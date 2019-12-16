// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
* Chapter 1 of Cracking the Coding Interview 5th edition by Gayle Laakmann McDowell
* Solved by JP Fallon in CPP C++
* Questions start on page 73
* use java style camelCase for naming everything just like in book, use old_dot_net style for tests
*/
#include "pch.h"
#include "1-2-reverse-c-string.h"
#include "1-4-replace-spaces.hpp"

#include <stdlib.h>     // for _countof
#include <stdio.h>      // for printf
#include <errno.h>      // for return values

int main()
{
	std::cout << "Hello World!\n";
	// full test of chapter 1: problem 2 reverse c string
	//testReverse();

	string input = "Mr John Smith    ";
	string output = "Mr%20John%20Smith";

	char buffer[80];
	// wow... must declare this before using...
	rsize_t restrictedSize = sizeof(char) * 80;
	// copy input string into char buffer
	//strcpy(buffer, input.c_str()); // bad security... even for this...
	strcpy_s(buffer, restrictedSize, "Mr John Smith    ");
	// mangle string in place with URL friendly %20
	spaceReplaceInPlace(buffer, 80, 11);

	_CrtDumpMemoryLeaks();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

