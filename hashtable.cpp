#include "hashtable.h"
#include <cstdlib>
#include "dsstring.h"
#include <iostream>
using namespace std;

HashTable::HashTable()
{
    for(int i=0; i<tableSize; i++)
    {
        HTable[i] = new item;
        HTable[i]->name="null";
        HTable[i]->times=0;
        HTable[i]->next=nullptr;
    }
}

int HashTable::Hash(String key)
{
    int h=0;
    int index;

    for(int i =0; i<key.size();i++)
        h = h+(int)key[i];
    index=h%tableSize;
    return index;
}

void HashTable::add(String a, int b)
{
    int index = Hash(a);
    if(HTable[index]->name=="null")
    {
        HTable[index]->name=a;
        HTable[index]->times=b;
    }
    else
    {
//        while(HTable[index]->name!="null")
//        {
//            index++;
//            if(index==tableSize)
//                index=0;
//        }
//        HTable[index]->name=a;
//        HTable[index]->times=b;
        item* curr=HTable[index];
        item* temp = new item;
        temp->name=a;
        temp->times=b;
        temp->next=nullptr;
        while(curr->next!=nullptr)
        {
            curr=curr->next;
        }
        curr->next=temp;
    }
}

int HashTable::NumItemsAtIndex(int i)
{
    int count=0;
    if(HTable[i]->name=="null")
        return count;
    else
    {
        count++;
        item* curr=HTable[i];
        while(curr->next!=nullptr)
        {
            count++;
            curr=curr->next;
        }
    }
    return count;
}

void HashTable::printTable()
{
    int num;
    for(int i=0; i<tableSize; i++)
    {
        num=NumItemsAtIndex(i);
        if(num!=0)
        {
            cout<<"index = "<<i<<endl;
            cout<<"Metric: "<<HTable[i]->name<<endl;
            cout<<"Score: "<<HTable[i]->times<<endl;
            cout<<"# of items in hash table at current index: "<<num<<endl;
            cout<<""<<endl;
        }
    }
}

void HashTable::printItemsAtIndex(int index)
{
    item* curr = HTable[index];
    if(curr->name=="null")
        cout<<"nothing in this index"<<endl;
    else
        while(curr!=nullptr)
        {
            cout<<curr->name<<endl;
            cout<<curr->times<<endl;
            curr=curr->next;
        }
}

int HashTable::findCount(String name)
{
    int index = Hash(name);
//    bool foundObject = false;
    int num;
    item* curr=HTable[index];
    while(curr!=nullptr)
    {
        if(curr->name==name)
        {
         //   foundObject=true;
            num=curr->times;
        }
        curr=curr->next;
    }
//    if(foundObject==true)
//        cout<<"This has been stored this many times: "<<num<<endl;
    return num;
}

void HashTable::remove(String name)
{
    int index = Hash(name);
    item* del;
    item* temp1;
    item* temp2;

    if(HTable[index]->name=="null"&& HTable[index]->times==0)
        cout<<"nothing is there"<<endl;

    else if(HTable[index]->name==name&& HTable[index]->next==nullptr)
    {
        HTable[index]->name="null";
        HTable[index]->times=0;
    }

    else if(HTable[index]->name==name)
    {
        del=HTable[index];
        HTable[index] = HTable[index]->next;
        delete del;
    }

    else
    {
        temp1 = HTable[index]->next;
        temp2 = HTable[index];
        while(temp1!=nullptr && temp1->name!=name)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        if(temp1==nullptr)
            cout<<"not found"<<endl;
        else
        {
            del=temp1;
            temp1=temp1->next;
            temp2->next=temp1;
            delete del;
        }
    }
}

HashTable::~HashTable()
{
    item*curr;
    for(int i=0; i<tableSize; i++)
    {
        while(HTable[i]!=nullptr)
        {
            curr=HTable[i];
            HTable[i]=HTable[i]->next;
            delete curr;
        }
    }
}
