#ifndef STRING
#define STRING

#include <iostream>
#include <cstring>


class String{


    private:
        char* data;
        int length;
        int capacity;


    public:

        String();//check
        String(const char*);//check
        String(const String&);//check

        String& operator= (const char*);//check
        String& operator= (const String&);//check
        String operator+ (const String&);
        bool operator== (const char*);
        bool operator== (const String&) const;
        bool operator!=(const String&);
        bool operator> (const String&) const;
        bool operator< (const String&) const;
        char& operator[] (const int);
        String get();
        int size();
        String substring(int, int);
        char* c_str();

        friend std::ostream& operator<< (std::ostream&, const String&);

        ~String();//check


};


#endif

