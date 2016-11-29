#ifndef METRIC1
#define METRIC1
#include "dsstring.h"
class Metric1
{
    public:
        Metric1(String);
        int numOfFunctions(String);
        bool hasOpenBracketatEnd(char* );
        int charlength(char* dname);
        bool findsclassfunction(char*,char*);
    private:


};

#endif // METRIC1

Metric1::Metric1(String d)
{
    double score=0;
    int lineCount=0;
    char buffer[250];
    ifstream fin;
    fin.open(d.c_str());
    while(!fin.eof())
    {
        fin.getline(buffer, 250);
        if(buffer[0]!='\0')
          lineCount++;
    }
    cout<<"Line Count: "<<lineCount<<endl;
    fin.close();
    int numfunc = numOfFunctions(d);
    cout<<"Function count: "<<numfunc<<endl;
    if(numfunc==0)
        score=10;
    else
        score = lineCount/numfunc;
    cout<<"Overall Score for Metric1: "<<score<<endl;
    cout<<"------------------------------------"<<endl;
}

int Metric1::numOfFunctions(String d)
{
    double classCount=0;
    double templateCount=0;
    ifstream fin;
    char buffer[250];
    char classname[250];
    double functionCount=0;
    fin.open(d.c_str());
    while(!fin.eof())
    {
        fin>>buffer;
        String a(buffer);
        if(a=="class")//finds the classname
        {
            fin>>buffer;
            if(hasOpenBracketatEnd(buffer))
            {
                for(int i=0; i<charlength(buffer)-1; i++)
                {
                    classname[i]=buffer[i];
                }
            }
            else
            {
                for(int i=0; i<charlength(buffer); i++)
                {
                    classname[i]=buffer[i];
                }
            }
        }
        else if(findsclassfunction(buffer,classname))
        {
            classCount++;
        }
        else if(a=="template"||a=="template<class")
        {
            templateCount++;
        }
        else if(a=="void")
            functionCount+=0.5;
        else if(buffer[0]=='~')
            functionCount++;
        else if(a=="int")//sees if the int is a function or a variable
        {
            fin>>buffer;
            if(hasOpenBracketatEnd(buffer))
            {
                functionCount++;
            }
        }
        else if(a=="bool")//sees if the bool is a function of a variable
        {
            fin>>buffer;
            if(hasOpenBracketatEnd(buffer))
            {
                functionCount++;
            }
        }
        else
            continue;
    }
    fin.close();
    if(templateCount>10)
        functionCount+=templateCount;
    else
        functionCount+=classCount;
    return functionCount;
}
bool Metric1::hasOpenBracketatEnd(char* dname)
{
    for(int i=0; i<20; i++)
    {
        if (dname[i]=='{'||dname[i]=='(')
        {
            return true;
        }
        else
            continue;
    }
    return false;
}
int Metric1::charlength(char* dname)
{
    for(int i=0; i<20; i++)
    {
        if (dname[i]=='\0')
            return i;
    }
}
bool Metric1::findsclassfunction(char *buffer, char*classname)
{
    for(int i=0; i<charlength(classname); i++)
    {
        if(classname[i]!=buffer[i])
            return false;
        else
            continue;
    }
    return true;
}
