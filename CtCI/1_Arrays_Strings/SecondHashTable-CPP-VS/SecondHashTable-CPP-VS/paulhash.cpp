#include "pch.h"
#include "paulhash.h"

#include <iostream>

PaulHash::PaulHash()
{
    // allocate array of HTitems
    for(int i = 0; i < tableSize; i++)
    {
        HashuTable[i] = new HTitem;
        HashuTable[i]->name = defaultName;
        HashuTable[i]->drink = defaultDrink;
        HashuTable[i]->next = nullptr;
    }
}

/* Recursive Function to delete the entire linked list */
void PaulHash::deleteList(const HTitem* head)
{
    if (head == nullptr)
    {
        return;
    }

    deleteList(head->next);
    // delete other HTitem or node struct memory allocs here
    delete (head);
}


PaulHash::~PaulHash()
{
    if(HashuTable != NULL)
    {
        for(int i = 0; i < tableSize; i++)
        {
            // delete all chained HTitems
            HTitem* temp = HashuTable[i]->next;
            if(temp != nullptr)
            {
                deleteList(HashuTable[i]->next);
            }

            // finally delete original HTitem
            delete HashuTable[i];
        }
    }
}

void PaulHash::AddItem(std::string name, std::string drink)
{
    // bucket location to store new item
    int index = Hash(name);

    // inspect bucket to see if occupied
    if(HashuTable[index]->name == defaultName)
    {
        HashuTable[index]->name = name;
        HashuTable[index]->drink = drink;
    }
    else
    {
        // if occupied then add chain to bucket
        HTitem* Ptr = HashuTable[index];
        HTitem* newPtr = new HTitem;

        newPtr->name = name;
        newPtr->drink = drink;
        newPtr->next = nullptr;

        // traverse chain list until last
        while(Ptr->next != nullptr)
        {

            Ptr = Ptr->next;
        }

        Ptr->next = newPtr;
    }
}

//// in code blocks highlight -> edit -> Uncomment (CTRL+SHIFT+X)
//int PaulHash::Hash(std::string key)
//{
//    int index;
//
//    int hashu = 0;
//
//    for(int i = 0; i < key.length(); i++)
//    {
//        // accumulate ascii values of key chars into hashu variable
//        hashu = hashu + (int)key[i];
//        //std::cout << "hash = " << hashu << std::endl;
//    }
//
//    // basic hash function to modulo ascii total of key string by max tablesize
//    index = hashu % tableSize;
//
//    return index;
//}


int PaulHash::Hash(std::string key)
{
    int index;

    int hashu = 0;

    for(int i = 0; i < key.length(); i++)
    {
        // accumulate ascii values of key chars into hashu variable
        hashu = hashu + (int)key[i];
        //std::cout << "hash = " << hashu << std::endl;
    }

    // basic hash function to modulo ascii total of key string by max tablesize
    index = hashu % tableSize;

    return index;
}


int PaulHash::NumberOfItemsInIndex(int index)
{
    int kount = 0;

    if(HashuTable[index]->name == defaultName)
    {
        kount = 0;
    }
    else
    {

        kount++;
        // point to beginning of chain link list in bucket
        HTitem* Ptr = HashuTable[index];
        while(Ptr->next != nullptr)
        {
            kount++;
            Ptr = Ptr->next;
        }
    }

    return kount;
}

 void PaulHash::PrintItemsInIndex(int index)
 {
    HTitem* Ptr = HashuTable[index];

    if(Ptr->name == defaultName){
            std::cout << " bucket = " << index << " is empty, 0 items\n";
    }else{
     std::cout << " bucket = " << index << " contains following items: \n";

     while(Ptr != nullptr)
        {
        std::cout << "-----------------------\n";
        std::cout << Ptr->name << std::endl;
        std::cout << Ptr->drink << std::endl;
        std::cout << "-----------------------\n";
        Ptr = Ptr->next;
        }
    }

 }


void PaulHash::PrintTable()
{
    int number;
    for(int i = 0; i < tableSize; i++)
    {
        number = NumberOfItemsInIndex(i);
        std::cout << "----------\n";
        std::cout << "index = " << i << std::endl;
        std::cout << HashuTable[i]->name << std::endl;
        std::cout << HashuTable[i]->drink << std::endl;
        std::cout << "# of items = " << number << std::endl;
        std::cout << "----------\n";
    }
}

std::string PaulHash::FindDrink(std::string name){
int index = Hash(name);
bool foundName = false;

std::string drink;

HTitem* Ptr = HashuTable[index];
while(Ptr != nullptr)
    {
    if(Ptr->name == name){
            // TODO: how handle matching keys or similar keys?
        foundName = true;
        drink = Ptr->drink;
    }
    Ptr = Ptr->next;
    }

    if(foundName == false)
        {
           drink = "404: Drink Not Found";
        }

return drink;

}

 short PaulHash::RemoveItem(std::string name)
 {
    int index = Hash(name);
short retCode;

    HTitem* delPtr;
    HTitem* P1;
    HTitem* P2;

    // case 0 bucket is empty
if(HashuTable[index]->name == defaultName)
    {
        std::cout << name << " was not found in HashTable\n";
retCode = PH_FAILURE;

    }else if(HashuTable[index]->name == name && HashuTable[index]->next == nullptr){
    // case 1 only a single item in indexbucket; name matches
         HashuTable[index]->name = defaultName;
         HashuTable[index]->drink = defaultDrink;
         retCode = PH_SUCCESS;
          std::cout << name << " was removed/reset from the HashTable!\n";
    }
    else if(HashuTable[index]->name == name)
        {
            // case 2 there is match in first item in bucket; but there are more items chain linked to it

        delPtr = HashuTable[index];
        HashuTable[index] = HashuTable[index]->next;
        delete delPtr;
        retCode = PH_SUCCESS;
        std::cout << name << " was removed form the HashTable!\n";
        }else
        {

    // case 3 bucket contains items but first item is NOT a match
    // Make P2 trail P1 pointer in remove from singly linked list style
    P1 = HashuTable[index]->next;
    P2 = HashuTable[index];

    // While lookahead pointer P1 is not at end of list, and
    //        is not equal to delete key; traverse singly linked list
    while(P1 != nullptr && P1->name != name){
        P2 = P1;
        P1 = P1->next;

    }

    if (P1 == nullptr)
        {
          // case 3.1 no match in this whole bucket
          std::cout << name << " was not found in hashTable\n";
          retCode = PH_FAILURE;
        }
        else{
    // case 3.2 match found in chain links of this bucket
    // delPtr point to item want to remove, save where item marked for death was found
    delPtr = P1;
    P1 = P1->next;
    P2->next = P1; // stitch over hole in list

    delete delPtr;
    retCode = PH_SUCCESS;
        std::cout << name << " was removed form the HashTable!\n";
        }}


 return retCode;
 }



