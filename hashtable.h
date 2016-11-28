#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <cstdlib>
#include "dsstring.h"
#include <iostream>

class HashTable
{
public:
    int Hash(String);
    HashTable();
    int NumItemsAtIndex(int);
    void add(String, int);
    void printTable();
    void printItemsAtIndex(int);
    int findCount(String);
    void remove(String);
    ~HashTable();

private:
    static const int tableSize=10;

    struct item{
        String name;
        int times;
        item* next;
    };
    item* HTable[tableSize];
};

#endif // HASHTABLE_H
