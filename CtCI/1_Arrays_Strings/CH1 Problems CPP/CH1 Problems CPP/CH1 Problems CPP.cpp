// CH1 Problems CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

// 1.2 reverse a null terminated C string using C or C++
void reverse(char* str);
void reverse(char* str, int strlen);

const int ARBITRARY_MAX_STR_LEN = 1024;

// The best laid schemes o' mice an' men Gang aft agley
// try it with smart pointers
// try it with string.reverse()
// try it with std::string.c_str()

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

	char rope[] = "Sailor";

	// print out string
	cout << twine << endl;

	reverse(twine);

	// print out reversed string
	cout << twine << endl;

	reverse(twine, laborstrLen);

	// print out reversed string
	cout << twine << endl;

	//TODO: DELETE char[]; first figure out way to check for memory leaks though
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

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

void reverse(char* str, int strlen) 
{
	// Zero indexed strlen
	int endCharIndex = strlen - 1;
	//robaL -> L a b o r
	for (int i = 0; i < strlen; i++)
	{
		// stomps on own memory half way thru DUMBASS!!!!
		// Way to use recurseive fucntion here instead???
		char temp = str[endCharIndex];
		str[i] = temp;
		endCharIndex--;
		
	}

	
}

char hottuSwapu() 
{

}