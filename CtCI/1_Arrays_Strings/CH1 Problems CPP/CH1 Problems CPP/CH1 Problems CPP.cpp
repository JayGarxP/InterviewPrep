// CH1 Problems CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "pch.h"
// to check your C++ program for leaks: https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2019
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
// copy the above three lines, run '_CrtDumpMemoryLeaks();' when you want to check for leaks valgrind style, like at bottom of main
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// 1.2 reverse a null terminated C string using C or C++
void reverse(char* str); // whiteboard solution
void reverse(char* str, int strlen); // in VS IDE version using debugger after trying to do it recursively.
void swap(char& x, char& y); // swap chars in place; strlen / 2 times
const char* reverse(const char* str); // 'reverse' a const cstring


const int ARBITRARY_MAX_STR_LEN = 1024;

// The best laid schemes o' mice an' men Gang aft agley
// tried with smart pointers // https://docs.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=vs-2019
// no point, std::string already is managed
// tried it with string.reverse()

// CTtI Chapter1 1.2 reverse string
int main()
{
    std::cout << "Hello World!\n"; 

	
	const char* labor = "Labor";
	// arbitrary max str len
	int laborstrLen = strnlen_s(labor, ARBITRARY_MAX_STR_LEN); //strlen does not count null
	// + 1 since strlen does not count null
	char* twine = new char[laborstrLen + 1];

	rsize_t laborstrLenBytes = laborstrLen * sizeof(char);

	// Liberty taken with not implementing own strcpy for now.
	//char string[80];
	//strcpy_s(string, _countof(string), "Hello world from ");
	strcpy_s(twine, laborstrLenBytes + sizeof(char), labor);
	// I think strcpy_s will append '\0' for me?

	//char rope[] = "Sailor";

	// print out string
	cout << twine << endl;

	// CtCI on paper I came up with, uses buffer as 'stack'
	reverse(twine);

	// print out reversed string
	cout << twine << endl;

	// Tried to recurse, figured out that just swapping in place strlen / 2 times works great.
	reverse(twine, laborstrLen);

	// print out reversed string
	cout << twine << endl;

	// The way SANE & BEAUTIFUL people reverse strings
	string twineString = twine;
	reverse(twineString.begin(), twineString.end());
	cout << twineString << endl;

	// returning address of local function variable is working here?
	const char* ProcuraDeLei = (reverse("Felina"));

	cout << ProcuraDeLei << endl;

	// string.c_str is pointer to const char* on stack, always save this value as any use of the string that made it can wipe it.
	//const char* c_strTest = twineString.c_str;

	delete[] twine;

	// an 8 byte "leak" is from the string twineString, since it hasn't gone out of scope yet,
	// if you check for leaks above the delete[] above you will see more "leaks"
	_CrtDumpMemoryLeaks();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// whiteboard version, after fixing mistakes (wrong char used for NULL, off by 1 in overwrite index, but rest was OK!)
void reverse(char* str) 
{
	// find strlen by looking for '\0'?
	// push onto stack until hit null, then pop for number of pushes until hit num pushes

	char currentChar = 'j';
	short numCharsPushed = 0;
	// use a char[] as a fake stack.
	char fakeStack[ARBITRARY_MAX_STR_LEN];

	// push all chars in string except null to 'stack'; then overwrite string in reverse order, leave null where it is, that sleeping dog.
	bool endOfString = false;
	while (endOfString == false)
	{
		currentChar = str[numCharsPushed];
		if (currentChar == '\0')
		{
			endOfString = true;
		}
		else 
		{
			// push non null char onto stack
			fakeStack[numCharsPushed] = str[numCharsPushed];
			numCharsPushed++;
		}
		
	}
	// minus one to be zero indexed
	int overwriteIndex = numCharsPushed - 1;

	for (int i = 0; i < numCharsPushed; i++)
	{
		str[overwriteIndex] = fakeStack[i];
		overwriteIndex--;
	}

}

const char* reverse(const char* str)
{
	// find strlen by looking for '\0'?
	// push onto stack until hit null, then pop for number of pushes until hit num pushes


	char currentChar = 'p';
	short numCharsPushed = 0;
	// use a char[] as a fake stack.
	char fakeStack[ARBITRARY_MAX_STR_LEN];

	// push all chars in string except null to 'stack'; then overwrite string in reverse order, leave null where it is, that sleeping dog.
	bool endOfString = false;
	while (endOfString == false)
	{
		currentChar = str[numCharsPushed];
		if (currentChar == '\0')
		{
			endOfString = true;
		}
		else
		{
			// push non null char onto stack
			fakeStack[numCharsPushed] = str[numCharsPushed];
			numCharsPushed++;
		}

	}
	// big security flaw to have empty buffer past null
	char reversedString[ARBITRARY_MAX_STR_LEN];

	// add null to end
	reversedString[numCharsPushed] = '\0';

	// minus one to be zero indexed
	int overwriteIndex = numCharsPushed - 1;

	for (int i = 0; i < numCharsPushed; i++)
	{
		reversedString[overwriteIndex] = fakeStack[i];
		overwriteIndex--;
	}
	

	return reversedString;

}

// if know length of string can just swap first half of chars with last half
void reverse(char* str, int strlen) 
{
	// Zero indexed strlen
	int endCharIndex = strlen - 1;
	//robaL -> L a b o r
	for (int i = 0; i < strlen / 2; i++)
	{
		swap(str[i], str[endCharIndex]);
		endCharIndex--;	
	}

}


//// function definition to swap the values, give address of char i.e. char*
void swap(char& x, char& y) {

	char temp;
	temp = x; /* save the value at address x */
	x = y;    /* put y into x */
	y = temp; /* put x into y */

	return;
}

