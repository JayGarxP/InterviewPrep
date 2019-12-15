#pragma once
// 1-2-reverse-c-string.h
#include <cstring>
// 1.2 reverse a null terminated C string using C or C++

void reverse(char* str); // whiteboard solution; swap strlen / 2 times
void reverse(char* str, int strlen); // in VS IDE version using debugger after trying to do it recursively.
void swap(char& x, char& y); // swap chars in place; 
const char* reverse(const char* str); // 'reverse' a const cstring
void testReverse(); // temporary test to print output


const int ARBITRARY_MAX_STR_LEN = 1024;