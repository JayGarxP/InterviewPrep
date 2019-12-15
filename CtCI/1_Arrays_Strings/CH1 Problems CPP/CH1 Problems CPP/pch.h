// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef PCH_H
#define PCH_H

// Add headers that you want to pre-compile here
// to check your C++ program for leaks: https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2019
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
// copy the above three lines, run '_CrtDumpMemoryLeaks();' when you want to check for leaks valgrind style, like at bottom of main
// If Detected memory leaks! appears in debug window there is leaks; if nothing appears, there is no leaks detected;
// To color code debug output use this: https://marketplace.visualstudio.com/items?itemName=MikeWard-AnnArbor.VSColorOutput

#include <string>
#include <iostream>
using namespace std;
#endif //PCH_H
