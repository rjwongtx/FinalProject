#ifndef METRIC1
#define METRIC1
#include "dsstring.h"
class Metric1
{
    public:
        Metric1(String, double&, double&, ofstream&);
        int numOfFunctions(String, ofstream&);
        bool hasOpenBracketatEnd(char* );
        int charlength(char* dname);
        bool findsclassfunction(char*,char*);
    private:


};

#endif // METRIC1

Metric1::Metric1(String d, double& OS, double& NF, ofstream& out)
{
    double score=0;
    int lineCount=0;
    char buffer[500];
    ifstream fin;
    fin.open(d.c_str());
    while(!fin.eof())
    {
        fin.getline(buffer, 500);
        if(buffer[0]!='\0')
          lineCount++;
    }
    out<<"Line Count: "<<lineCount<<endl;
    fin.close();
    int numfunc = numOfFunctions(d,out);
    out<<"Function count: "<<numfunc<<endl;
    if(numfunc==0)
        score=10;
    else
        score = lineCount/numfunc;
    OS+=score;
    NF++;
    out<<"Score for Metric1 at this file: "<<score<<endl;
    out<<"- -"<<endl;
}

int Metric1::numOfFunctions(String d, ofstream& out)
{
    double voidCount=0;
    double classCount=0;
    double templateCount=0;
    ifstream fin;
    char buffer[250];
    char classname[250];
    classname[0]='\0';
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
                classname[charlength(buffer)-1]='\0';
            }
            else
            {
                for(int i=0; i<charlength(buffer); i++)
                {
                    classname[i]=buffer[i];
                }
                classname[charlength(buffer)]='\0';
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
        {
            voidCount=voidCount+0.5;
            functionCount=functionCount+0.5;
        }
        else if(buffer[0]=='~')
            functionCount++;
        else if(a=="#include"||a=="#define")
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
    fin.close();//need to work on classname[0]==null
    if(classname[0]=='\0')
        out<<d<<endl;
    else
    {
        for(int i=0; i<charlength(classname); i++)
        {
            out<<classname[i];
        }
        out<<endl;
    }
    if(templateCount>10)
        functionCount=templateCount;
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
