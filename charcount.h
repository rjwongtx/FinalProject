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
    int charsPerLine=0;
//    int numChars=0;
    int lineCount=0;
    char buffer[500]={'\0'};
    ifstream fin;
    fin.open(d.c_str());
    while(!fin.eof())
    {
        fin.getline(buffer, 500);
        if(buffer[0]!='\0')
        {
            int numChars=0;
            lineCount++;
            for(int i=0; i<500; i++)
            {
                if((buffer[i]=='/'&&buffer[i+1]=='/'))
                    break;
                if((buffer[i]=='/'&&buffer[i+1]=='*'))
                    break;
                if(buffer[i]!='\0')
                {
                    numChars++;
                    charsPerLine++;
                }


            }
            if(numChars>100)
                score++;
            else
                score=score-1;
        }
    }
    fin.close();
    if(score<0)
        score=0;
    else if(score>100)
        score=10;
    else
        score=score/5;
    if (score>10)
        score=score/2;
    OS+=score;
    NF++;
    charsPerLine=charsPerLine/lineCount;
    if(BorV=="-v")
    {
        out<<"Line Count: "<<lineCount<<endl;
        out<<"Average Chars per Line: "<<charsPerLine<<endl;
        out<<"Score for Metric5 at this file: "<<score<<endl;
        out<<"-------------------------------"<<endl;
    }


}
