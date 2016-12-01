#ifndef COMMENTCOUNTER
#define COMMENTCOUNTER
#include "dsstring.h"
class CommentCounter
{
    public:
        CommentCounter(String, double&, double&, ofstream&, String);
};
#endif // COMMENTCOUNTER

CommentCounter::CommentCounter(String d, double& OS, double& NF, ofstream& out, String BorV)
{
    double score=0;
    double comments=0;
    int starcounter=0;
    int lineCount=0;
    char buffer[500]={'\0'};
    ifstream fin;
    fin.open(d.c_str());
    while(!fin.eof())
    {
        fin.getline(buffer, 500);
        if(buffer[0]!='\0')
            lineCount++;
    }
    if(BorV=="-v")
        out<<"Line Count: "<<lineCount<<endl;
    fin.close();

    fin.open(d.c_str());
    while(!fin.eof())
    {
        fin>>buffer;
        for(int i=0; i<500; i++)
        {
            if(buffer[i]=='/' && buffer[i+1]=='/')
            {
                comments++;
                break;
            }
            if(buffer[i]=='/' && buffer[i+1]=='*')
            {
                comments+=10;
                break;
            }
            else if(buffer[i]=='\0')
                break;
            else
                continue;
        }
    }
    fin.close();
    if(BorV=="-v")
       out<<"Comment Count: "<<comments<<endl;
    if(comments==0)
        score=10;
    else
        score = lineCount/comments;
    OS+=score;
    NF++;
    if(BorV=="-v")
    {
        out<<"Score for Metric2 at this file: "<<score<<endl;
        out<<"- -"<<endl;
    }


}
