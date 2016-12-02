#ifndef VECTOR_H
#define VECTOR_H

#include<iostream>
#include"dsstring.h"

template<class T>
class Vector{

  public:

      Vector();
      Vector(int);
      Vector(double);
      Vector(const char*);
      Vector(const String&);
      Vector(const Vector<T>&);

      void add(T);
      void add(T, int);//needs work
      T get(int);


      ~Vector();

      int size();
      void sort();
      void swap(int *, int*);

      T& operator[](int);
      Vector<T>& operator=(Vector<T>&);
      Vector<T>& operator+=(T);
      Vector<T>& operator==(Vector<T>&);

  private:

      void resize();
      int capacity;
      T* data;
      int length;
      int ascending(int, int);


};
#endif


template<class T>
Vector<T>& Vector<T>::operator==(Vector<T>& str)
{

}
template <class T>
Vector<T>::Vector()
{
    length=0;
    capacity=1;
    data = new T[capacity];
}

template<class T>
Vector<T>::Vector(int size)
{
    length=0;
    capacity = size;
    data = new T[capacity];
}

template<class T>
Vector<T>::Vector(double d)
{
    capacity = d;
    data = new T[capacity];
    length=0;

}

template<class T>
Vector<T>::Vector(const char* stored)
{
    if(stored!=NULL)//if there is something in the function
    {
    data = new T[strlen(stored)+1];//creates an array of chars based on the length of the string in the function
    this->length=strlen(stored);//sets the length of the current data to the length of the string passed in the function
    this->capacity=length+2;//sets the capacity of the data while giving room for the null character at the end
    for(int i = 0; i<length; i++)
        data[i]=stored[i];//assigns the char of each rhs to the char of each data
    data[length]='\0';//puts a null character at the very end
    }
    else//if there is nothing, it keeps nothing
    {
        data=NULL;
        this->capacity=0;
        this->length=0;
    }

}

template<class T>
Vector<T>::Vector(const String& stored)
{
    if(stored.data!=NULL)
    {
    data=new T[(stored.length+1)];
    this->length=stored.length;//same as the previous function bbut different code since we are dealing with a string instead of a char
    this->capacity=length+2;
    for(int i = 0; i<length; i++)
        data[i]=stored.data[i];
    data[length]='\0';//puts a null character at the very end
    }
    else
    {
        data=NULL;
        this->capacity=0;
        this->length=0;
    }
}

template<class Chip>
Vector<Chip>::Vector(const Vector<Chip> & stored)
{
    if(stored.data!=NULL)
      {
        data=new Chip[(stored.length+1)];
        this->length=stored.length;//same as the previous function bbut different code since we are dealing with a string instead of a char
        this->capacity=length+2;
        for(int i = 0; i<length; i++)
            data[i]=stored.data[i];
        data[length]='\0';//puts a null character at the very end
      }
    else
        {
          data=NULL;
          this->capacity=0;
          this->length=0;
        }
}
template<class T>
void Vector<T>::add(T obj)
{
    if(length+1>capacity)
        resize();

    data[length]=obj;
    length++;
}

template<class T>
void Vector<T>::add(T obj, int a)
{
    for(int i = length; i>0; i=-2)
    {
        data[i+1] = data[i];
        data[i] = data[i-1];
    }
    data[a]=obj;
    length++;
}

template<class T>
Vector<T>& Vector<T>::operator+=(T a)
{
    data[length]=a;
    length++;
}

template <class T>
Vector<T>& Vector<T>::operator=(Vector<T> & a)
{
    if(this!=&a)//make sure that they are different
        {
         if(a.data!=NULL)//make sure that there is something in the right hand side
           {
            if(data!=NULL)//make sure there is something in the left hand side
            {

                capacity=a.capacity;//copies the right hand side into the left side. makes the capacity the same
                length=a.length;//does the same but for the length
                for(int i=0;i<length;i++)
                    data[i]=a.data[i];//copies what's inside the rhs to data
            }
            else
            {
                data=new T[a.length+1];//if there is nothing in data, creates a new data so rhs can be transfered into the new data
                length = a.length;
                capacity = length+2;//make sure it has enough room for a null terminator
                for (int i = 0; i<length; i++)
                    data[i]=a.data[i];
                data[length]='\0';
            }
         }

      else//if there is nothing in data then keep nothing
        {
            data=NULL;
            capacity=0;
            length=0;
        }
    }
    else
        return *this;
}

template<class T>
int Vector<T>::size()
{
    return this->length;
}

template<class T>
T Vector<T>::get(int a)
{
    if(a>capacity)
        throw 0;
    else if(a<0)
        throw 0;
    else
        return this->data[a];
}

template<class T>
T& Vector<T>::operator[] (const int a)
{
    if(a>=0)
        return data[a];
    else
        return data[this->length+a];
}

template<class T>
Vector<T>::~Vector()
{
//    if(capacity!=0)
//    {
//       data=NULL;
//       length=0;
//       capacity=0;
//    }
    delete[]data;
}

template<class T>
void Vector<T>::resize()
{
   this->capacity=length*2;//increases the capacity by 1.5
   T* temp= new T[capacity];
   for(int i =0; i<length; i++)
        temp[i]=data[i];
   delete[] data;
   data=temp;

}

template<class T>
void Vector<T>::swap(int *initial, int *final)
{
    int temp;
    temp=*initial;
    *initial=*final;
    *final=temp;
}

template<class T>
int Vector<T>::ascending(int a, int b)
{
    return b < a;
}

template<class S>
void Vector<S>::sort()//sort function
{
    S temp;//vector containing temp
    int lowestNumber;
    for(int i=0; i<length; i++)//length is length of the vector
    {
       temp = this->data[i];//puts all the current data into the temp vector
       lowestNumber = i;//holds onto the lowestNumber
       for(int j=i+1; j<length; j++)
       {
           if(temp>this->data[j])//if the vector is higher than the next data vector
           {
               lowestNumber=j;//replaces the new lowest vector
               temp=this->data[j];//puts it into the temp vector
           }
       }
       //data[i+j]=data[i];
       this->data[lowestNumber]=NULL;//clears it just in case
       this->data[lowestNumber]=this->data[i];
       this->data[i]=NULL;
       this->data[i]=temp;
    }
}
