#ifndef CHARCOUNT
#define CHARCOUNT
#include "dsstring.h"
#include <hashtable.h>
class CharCount
{
    public:
        CharCount(String, double&, double&, ofstream&, String);
};
#endif // CHARCOUNT

CharCount::CharCount(String d, double& OS, double& NF, ofstream& out, String BorV)
{
    double score=0;
    int numChars=0;
    int lineCount=0;
    HashTable hashy;
    char buffer[500]={'\0'};
    ifstream fin;
    fin.open(d.c_str());
    while(!fin.eof())
    {
        fin.getline(buffer, 500);
        if(buffer[0]!='\0')
        {
            lineCount++;
            for(int i=0; i<500; i++)
            {
                if(buffer[i]!='\0')
                    numChars++;
            }
        }
    }

    cout<<d<<endl;
    cout<<"Line Count: "<<lineCount<<endl;
    cout<<"Char Count: "<<numChars<<endl;
//    hashy.add("Line Count", lineCount);
//    hashy.add("Number of Chars", numChars);
    fin.close();

}
