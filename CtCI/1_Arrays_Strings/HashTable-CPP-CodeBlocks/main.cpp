/*
 Basic Hashtable implementation in C++
 Following along with Paul Programming Vids https://youtu.be/m6n_rozU8dA
 Removed memory leaks and improved the hash function
 Going to port to C# and use this cpp hashtable in C# with C++/CLI DLL
 then compare the speeds
*/
#include "paulhash.h"
#include <iostream>
#include <cstdlib>
#include <string>

// crypto++ v8.2 open source library
//#include "dll.h"
///#include "cryptlib.h"

//#include "sha3.h"
// Can't seem to compile crypto++ with GNU GCC 8.1 through MinGW on Windows,
// tried to run nmake, and cygwin makes, did not spit out usable .dll or .lib files or .o files
// Oddly this same .cb codeblocks project builds on ubuntu...

using namespace std;

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
//    PaulTable.PrintTable();
//    PaulTable.PrintItemsInIndex(0);
//     PaulTable.RemoveItem("Maria");
//     PaulTable.PrintItemsInIndex(0);

//  using namespace CryptoPP;
//
//    SHA3_256 hash;
//    std::cout << "Name: " << hash.AlgorithmName() << std::endl;
//    std::cout << "Digest size: " << hash.DigestSize() << std::endl;
//    std::cout << "Block size: " << hash.BlockSize() << std::endl;

    return 0;
}
