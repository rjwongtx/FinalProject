//CATCH_CONFIG_RUNNER tells the catch library that this
//project will now explicitly call for the tests to be run.
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "avltree.h"
#include "dsstring.h"
#include "dirent.h"
#include "parse.h"
#include <sys/types.h>
#include <iostream>
#include <cstdlib>
#include "hashtable.h"
#include <fstream>
//A macro used in main to determine if you want to run
//the tests or not. If you don't want to run your tests,
//change true to false in the line below.
//-v input.txt output.txt
#define TEST false


int runCatchTests(int argc, char* const argv[])
{
    //This line of code causes the Catch library to
    //run the tests in the project.
    return Catch::Session().run(argc, argv);
}

int main( int argc, char* const argv[] )
{

    if (TEST)
    {
        return runCatchTests(argc, argv);
    }
    String BorV=argv[1];
    String dirname=argv[2];
    String outfile=argv[3];//this is the output
    ofstream out(outfile.c_str());
    ifstream fin(dirname.c_str());
    double OS1=0;
    double OS2=0;
    double OS3=0;
    double OS4=0;
    double OS5=0;
    double NF=0;
    char file[50];
    fin>>file;
    String filepath(file);
    out<<"Parsing files through Metrics"<<endl;
    Parse p(BorV, filepath, out, true, NF, OS1, OS2,OS3,OS4,OS5);
    cout<<"Number of file: "<<NF<<endl;
    HashTable h;
    h.add("Metric1", OS1/NF);
    h.add("Metric2", OS2/NF);
    h.add("Metric3", OS3/NF);
    h.add("Metric4", OS4/NF);
    h.add("Metric5", OS5/NF);
    h.printTable();

}
