#ifndef DUPLICATION
#define DUPLICATION
#include "dsstring.h"
#include "vector.h"
class Duplication
{
    public:
        Duplication(String, double&, double&, ofstream&, String);
        bool ifDuplicates(Vector<String>&, String);
        bool actualCode(String, int&);
};
#endif // DUPLICATION

Duplication::Duplication(String d, double& OS, double& NF, ofstream& out, String BorV)
{
    Vector<String> original(100);
    Vector<String> duplicates(100);
    Vector<int> test(100);
    int minus=0;
    duplicates.add("fsfsdfdsfas");
    double score=0;
    int duplicate=0;
    char buffer[500]={'\0'};
    ifstream fin;
    fin.open(d.c_str());
    fin.getline(buffer, 500);

    while(!fin.eof())
    {
        if(buffer[0]!='\0')
        {
            String a(buffer);
            original.add(a);
        }
        fin.getline(buffer, 500);

    }
    fin.close();

    fin.open(d.c_str());
    fin.getline(buffer, 500);
    while(!fin.eof())
    {
        if(buffer[0]!='\0')
        {
            String b(buffer);
            if(actualCode(b, minus))
            {

                if(!ifDuplicates(duplicates, b))
                {
                    int okay=0;
                    for(int j=0; j<original.size(); j++)
                    {
                        if(b==original[j])
                        {
                           if(okay>0)
                           {
                               duplicate++;
                               duplicates.add(b);
                               test.add(j);
                           }
                           else
                               okay++;
                        }
                    }
                }
            }
        }
        fin.getline(buffer, 500);
    }
    fin.close();
//    out<<"Originals: "<<endl;
//    for(int i=0; i<original.size(); i++)
//        out<<original[i]<<endl;
//    out<<endl;
//    out<<"Duplicates: "<<endl;
//    for(int i=0; i<duplicates.size(); i++)
//    {
//       out<<duplicates[i]<<endl;
//    }
//    out<<endl;
    int adjust = duplicate-minus;
    if(BorV=="-v")
        out<<"# of duplicates: "<<adjust<<endl;
    score=adjust/6;
    if(score>10)
        score=10;
    OS+=score;
    NF++;
    if(BorV=="-v")
    {
        out<<"Score for Metric4 at this file: "<<score<<endl;
        out<<"- -"<<endl;
    }
}
bool Duplication::ifDuplicates(Vector<String>& duplicates, String b)
{
    for(int i=0; i<duplicates.size(); i++)
    {
        if(b==duplicates[i])
            return true;
        else
            continue;
    }
    return false;
}

bool Duplication::actualCode(String word, int& minus)
{
    if(word=="{")
    {
        minus++;
        return false;
    }
    else if(word=="}")
    {
        minus++;
        return false;
    }
    else if(word=="else")
        return false;
    else if(word=="/*")
        return false;
    else if(word=="*/")
        return false;
    else if(word=="#endif")
        return false;
    else if(word=="#else")
        return false;
    else if(word=="{}")
        return false;
    else if(word=="};")
        return false;
    else if(word=="break;")
        return false;
    else
        return true;
}
