#ifndef VARIABLENAMES
#define VARIABLENAMES
#include "dsstring.h"
#include "avltree.h"
class VariableNames
{
    public:
        VariableNames(String, double&, double&, ofstream&, String);
        bool hasOpenBracketatEnd(char* );
        bool isVariable(String);
        bool badvariable(char*);
    private:
};
#endif // VARIABLENAMES
VariableNames::VariableNames(String d, double& OS, double& NF, ofstream& out, String BorV)
{
    double score=0;
    char buffer[500]={'\0'};
    char variablename[40]={'\0'};
    int badvariablenames=0;
    int goodvaribalenames=0;
    double good=0;
    double bad=0;
    ifstream fin;
    fin.open(d.c_str());
    while(!fin.eof())
    {
        fin>>buffer;
        String a(buffer);
        if(isVariable(a))
        {
            fin>>buffer;
            if(!hasOpenBracketatEnd(buffer))
            {
                for(int i=0; i<40; i++)
                {
                    variablename[i]=buffer[i];
                }
            }
            if(variablename[0]!='\0')
            {
                if(badvariable(variablename))
                {
                    badvariablenames++;
                    bad++;
                }
                else
                {
                    goodvaribalenames++;
                    good+=0.2;
                }
            }

        }
    }
    fin.close();
    if(BorV=="-v")
    {
        out<<"Bad Variable Names: "<<badvariablenames<<endl;
        out<<"Good Variable Names: "<<goodvaribalenames<<endl;
        out<<"Good Points: "<<good<<endl;
        out<<"Bad Points: "<<bad<<endl;
    }
    score=good-bad;
    if(score>10)
        score=0;
    else if(score<0)
        score=10;
    else if(bad==0)
        score=0;
    else
        score=10-score;
    OS+=score;
    NF++;
    if(BorV=="-v")
    {
        out<<"Score for Metric3 at this file: "<<score<<endl;
        out<<"-  -"<<endl;
    }





}

bool VariableNames::hasOpenBracketatEnd(char* dname)
{
    for(int i=0; i<50; i++)
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

bool VariableNames::isVariable(String a)
{
    AvlTree<String> variables;
    variables.insert("int");
    variables.insert("double");
    variables.insert("char");
    variables.insert("float");
    variables.insert("long");
    variables.insert("bool");
    if (variables.contains(a))
        return true;
    else
        return false;
}

bool VariableNames::badvariable(char* variable)
{
    for(char initial ='!'; initial<'!'+93; ++initial)
      {
       if(variable[0]==initial && variable[1]=='\0')
       {
           for(int i=0; i<100; i++)
           {
               if(variable[i]=='/' && variable[i+1]=='/')
                   return false;
           }
           return true;
       }
       if(variable[0]==initial && variable[1]=='='&&variable[2]=='\0')
       {
           for(int i=0; i<100; i++)
           {
               if(variable[i]=='/' && variable[i+1]=='/')
                   return false;
           }
           return true;
       }
      }
    return false;
}
