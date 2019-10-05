// SecondHashTable-CPP-VS.cpp : This file contains the 'main' function. Program execution begins and ends there.
	/*
 Basic Hashtable implementation in C++
 Following along with Paul Programming Vids https://youtu.be/m6n_rozU8dA
 Removed memory leaks and improved the hash function
 Going to port to C# and use this cpp hashtable in C# with C++/CLI DLL
 deleted the code blocks solution on 10/4/2019 since it could not build crypto++
 Going to try a cool portable hash-library from Stephan I found
 https://create.stephan-brumme.com/hash-library/
 Just download and include the sha256.h and .cpp to run this project.
 I am not including them because of possible license conflict, to be respectful and safe as possible.
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
// SHA2 test program https://create.stephan-brumme.com/hash-library/
#include "sha256.h"
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

		  // create a new hashing object   
		SHA256 sha256;   
		  // hashing an std::string   
		std::cout << sha256("Hello World") << std::endl;   // => a591a6d40bf420404a011733cfb7b190d62c65bf0bcda32b57b277d9ad9f146e   
														   // hashing a buffer of bytes   
		const char* buffer = "How are you";   
		std::cout << sha256(buffer, 11) << std::endl;   // => 9c7d5b046878838da72e40ceb3179580958df544b240869b80d0275cc07209cc   
														
														// or in a streaming fashion (re-use "How are you")   
		SHA256 sha256stream;   
		const char* url = "create.stephan-brumme.com"; 
		// 25 bytes   
		int step = 5;   
		for (int i = 0; i < 25; i += step)     
			sha256stream.add(url + i, step); 
		// add five bytes at a time   
		std::cout << sha256stream.getHash() << std::endl;   // => 82aa771f1183c52f973c798c9243a1c73833ea40961c73e55e12430ec77b69f6

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
