// SecondHashTable-CPP-VS.cpp : This file contains the 'main' function. Program execution begins and ends there.
	/*
 Basic Hashtable implementation in C++
 Following along with Paul Programming Vids https://youtu.be/m6n_rozU8dA
 Removed memory leaks and improved the hash function
 Going to port to C# and use this cpp hashtable in C# with C++/CLI DLL
 deleted the code blocks solution on 10/4/2019 since it could not build crypto++
*/

#include "pch.h"





// crypto++ v8.2 open source library
//#include "dll.h"
// crypto++ v8.2 open source library
//#include "cryptlib.h"
//#include "sha3.h" // sha3.h not working with dll
/*5 hours wasted on my part, 
I tried doing what the Readme said, built DLL, linked it, I tried using the static cryptopp project distributed with crypto++ as a dependency, 
copying the entire crypto++ library to the VS project.
I tried nMake, tried using codeblocks, cygwin... 
Keep getting linker errors at runtime, 
always something about bad blocks in heap.h.
The same library distro builds on ubuntu linux on the same computer fine just using the makefile.VS community 2017 with VC++ compiler is just not building crypto++ all.
Hopefully someone will make a nuget package!
*/

#include "paulhash.h"

#include <iostream>
#include <cstdlib>
#include <string>
//using namespace std;

// Can't seem to compile crypto++ with GNU GCC 8.1 through MinGW on Windows,
// tried to run nmake, and cygwin makes, did not spit out usable .dll or .lib files or .o files
// Oddly this same .cb codeblocks project builds on ubuntu...



int main()
{


		PaulHash PaulTable;
		//PaulTable.PrintTable();

		PaulTable.AddItem("Paul", "Locha");
		PaulTable.AddItem("Big Suzie", "MD2020 Blue Razz");
		PaulTable.AddItem("Dirty Ron", "Long Island");
		PaulTable.AddItem("Lefty", "Melk");
		PaulTable.AddItem("Maria", "horchata"); // 0 index
		PaulTable.AddItem("Maria", "Jarrito Mandarina"); // 0 index with ascii hash
		PaulTable.AddItem("DROP TABLE name);", "Hibiscus Tea"); // 0 index

		//PaulTable.PrintTable();
		//PaulTable.PrintItemsInIndex();

		//cout << "Paul Drink: " + PaulTable.FindDrink("Paul") << endl;

	//    PaulTable.RemoveItem("Paul");
	//    PaulTable.RemoveItem("DROP TABLE name);"); // works!
	//
	//
		PaulTable.PrintTable();
		//    PaulTable.PrintItemsInIndex(0);
		//     PaulTable.RemoveItem("Maria");
		//     PaulTable.PrintItemsInIndex(0);



			return 0;
		
	

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
