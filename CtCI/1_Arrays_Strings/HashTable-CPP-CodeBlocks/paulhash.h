
#ifndef PAULHASH_H
#define PAULHASH_H
#include <string>
/*
Hash table
bucket == index
*/
class PaulHash
{

// using GCC, not enough look-ahead, need to declare everything before it is used
private:
    static const int tableSize = 10;
    static const short PH_SUCCESS = 0;
    static const short PH_FAILURE = -1;
    const std::string defaultName = "default Name";
    const std::string defaultDrink = "default Drink";

    struct HTitem
    {
        std::string name;
        std::string drink;
        HTitem* next;
    };


    // hashtable is an array with HTitem elements
    HTitem* HashuTable[tableSize];

public:
    int Hash(std::string key);
    PaulHash();
    ~PaulHash();
    void deleteList(const HTitem* head);
    void AddItem(std::string name, std::string drink);
    int NumberOfItemsInIndex(int index);
    // Print first items and how many items in each bucket/index of table
    void PrintTable();
    void PrintItemsInIndex(int index);
    // if key name is in hash table, return its value, drink
    std::string FindDrink(std::string name);

    short RemoveItem(std::string name);


};


#endif // PAULHASH_H
