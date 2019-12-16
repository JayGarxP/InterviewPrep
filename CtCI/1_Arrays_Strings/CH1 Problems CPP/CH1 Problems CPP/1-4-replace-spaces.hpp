#pragma once
/* Chapter 1 Arrays and Strings problem 1-4
*  Write a method to replace all spaces in a string with '%20'
*  assume string has space at end to hold additional chars
*  you are given the "True Length" of the string
*  Please use character array to do this "in place"
*/


// mangle string in place with URL friendly %20 to replace spaces
void spaceReplaceInPlace(char* buff, int buffSize, int cCount);


// TODO: freestyle string.replace(' ', "%20");
// TODO: single pass working backwards cpp adaptation of book solution

//BOOST_TEST(spaceReplaceFreeStyle(input) == output);