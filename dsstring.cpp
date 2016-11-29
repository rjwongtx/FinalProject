#include <iostream>
#include "dsstring.h"
using namespace std;

String::String():data(nullptr), length(0), capacity(0){}//creates the constructor and sets everything to zero or null

String::String(const char* rhs)//takes in characters and converts it to an array of chars and transfer it to data
{
    if(rhs!=nullptr)//if there is something in the function
    {
    data = new char[strlen(rhs)+1];//creates an array of chars based on the length of the string in the function
    this->length=strlen(rhs);//sets the length of the current data to the length of the string passed in the function
    this->capacity=length+2;//sets the capacity of the data while giving room for the null character at the end
    for(int i = 0; i<length; i++)
        data[i]=rhs[i];//assigns the char of each rhs to the char of each data
    data[length]='\0';//puts a null character at the very end
    }
    else//if there is nothing, it keeps nothing
    {
        data=nullptr;
        this->capacity=0;
        this->length=0;
    }
}

String::String(const String& rhs)//takes in a string reference instead
{
    if(rhs.data!=nullptr)
        {
        data=new char[(rhs.length+14)];//this was one at first
        this->length=rhs.length;//same as the previous function bbut different code since we are dealing with a string instead of a char
        this->capacity=length+2;
        for(int i = 0; i<length; i++)
            data[i]=rhs.data[i];
        data[length]='\0';//puts a null character at the very end
        }
        else
        {
            data=nullptr;
            this->capacity=0;
            this->length=0;
        }
}
String& String::operator= (const char* rhs)//creating an assignment operator for functions that take in chars
{
    if(rhs!=nullptr)//if there is something in the function
    {
        data = new char[strlen(rhs)+1];//assigns rhs to the current data.
        length=strlen(rhs);//transfer the string length
        capacity=length+2;//transfers the capactiy. includes the null terminator
        for(int i=0; i<length; i++)
        {
            data[i]=rhs[i];//converts the char to make sure they are the same
        }
       data[length]='\0';//puts a null terminator at the end
    }
    else
    {
       data=nullptr;
       capacity=0;
       length=0;
    }
    return *this;
}
String:: ~String()      //Deconstructor for the String object
   {
//    if(data!=nullptr)
//    {
//     delete[]data;
//    }
//    delete[]data;
    data=nullptr;
    capacity=0;
    length=0;
   }

String& String::operator=(const String &rhs)//makes assignment operator for function taht takes in a string
{
    if(this!=&rhs)//make sure that they are different
        {
         if(rhs.data!=nullptr)//make sure that there is something in the right hand side
           {
            if(data!=nullptr)//make sure there is something in the left hand side
            {

                capacity=rhs.capacity;//copies the right hand side into the left side. makes the capacity the same
                length=rhs.length;//does the same but for the length
                for(int i=0;i<length;i++)
                    data[i]=rhs.data[i];//copies what's inside the rhs to data
            }
            else
            {
                data=new char[rhs.length+1];//if there is nothing in data, creates a new data so rhs can be transfered into the new data
                length = rhs.length;
                capacity =rhs.length+2;//make sure it has enough room for a null terminator
                for (int i = 0; i<length; i++)
                    data[i]=rhs.data[i];
                data[length]='\0';
            }
         }

      else//if there is nothing in data then keep nothing
        {
            data=nullptr;
            capacity=0;
            length=0;
        }
    }
    else
        return *this;//in the end return the new data variable
}

String String::operator+ (const String& rhs)//when you need to add two strings together
{
    String obj = *this;//stores what is currently the data variable into a string obj
    int i = 0;
    obj.length = obj.length + rhs.length;//combines the length of obj and rhs together
    obj.capacity = obj.capacity + rhs.capacity;//does it for capacity
    for(int a = this->size(); a<obj.length; a++)//create a for loop based on the size of the current data. the obj.length is the combination of the current data and new data string lengths
    {
        obj.data[a]=rhs.data[i];//starts adding the strings together
        i++;
    }
    return obj;
}
bool String::operator== (const char* rs)//creats an == operators for char
{
    if(this->size()!=strlen(rs))//if the lengths of the two strings aren't equal, immediately return false
        return 0;
    for(int i = 0; i<this->size(); i++)
        {
           if(this->data[i]!=rs[i])//compares each on individually
               return 0;
        }
    return 1;
}
bool String::operator== (const String& rhs)//the same as the pprevious one but with string
{
    if(this->size()!=rhs.length)
        return false;
    for(int i = 0; i<this->size(); i++)
        {
            if(this->data[i]!=rhs.data[i])
                return false;
        }
    return true;
}
bool String::operator!=(const String& rhs)
{
    if(this->size()!=rhs.length)
        return 1;
    for(int i = 0; i<this->size(); i++)
        {
            if(this->data[i]!=rhs.data[i])
                return 1;
        }
    return 0;

}
bool String::operator> (const String& rhs) const//compares the ASCII values of the string to see which one is greater
{
    int i =0;
    while(this->data[i]==rhs.data[i])//keeps going until a letter is different
        i++;
    if (this->data[i]>rhs.data[i])//sees which letter is greater
        return 1;
    else
        return 0;
}
bool String::operator< (const String& rhs) const//compares the ASCII values of the string to see which one is greater
{
    int i =0;
    while(this->data[i]==rhs.data[i])//keeps going until a letter is different
        i++;
    if (this->data[i]<rhs.data[i])//sees which letter is greater
        return 1;
    else
        return 0;
}
char& String::operator[] (const int i)
{
    if (i>=0)
        return data[i];//returns the value at that position
    else
        return data[strlen(data)+i];//if the position is given at a negative value, changes it to a positive
}

int String::size()//figures out the size
{
    return this->length;
}

String String::substring(int begin, int end)//substring function
{
    int number=0;//initializez variable int
    String initial="";//initializes a string
    int x=this->length;//x is the length of the current data
    for(int i=begin; i<end; i++)
    {
        while(number<(end-begin))//while loop that goes until it reaches the difference of the end and begin.
        {
            initial.data[number]=this->data[i];//deep copies all the current data in thos positions into the new concactenated string
            number++;//number goes up
            break;
        }
        initial.data[end-begin]='\0';
    }
    length=x;//length is still x
    initial.length=number;//new length is the difference
    return initial;//returns the new concatenated string

}

char* String::c_str()
{
    int obj = this->size()+1;//creates a obj based on the length of current data
    char* rhs=new char[obj];//creates an array of chars based on the obj
    for(int i =0; i<obj; i++)
        rhs[i]=this->data[i];//copies everything over
    return rhs;
}

ostream& operator<< (ostream& os, const String& rhs)
{
    os<<rhs.data;
    return os;
}

String String::get()
{
    return this->data;
}
