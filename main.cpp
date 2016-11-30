//CATCH_CONFIG_RUNNER tells the catch library that this
//project will now explicitly call for the tests to be run.
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "avltree.h"
#include "dsstring.h"
#include "vector.h"
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

    String dirname=argv[1];
    String outfile=argv[2];//this is the output
    ofstream out(outfile.c_str());
    ifstream fin(dirname.c_str());
    char file[50];
    fin>>file;
    String filepath(file);
    Parse p(filepath, out);
//    char buffer[100]={'S','t','r','i',':',':','S','t','r','i'};
//    char classname[100];
//    for (int i=0;i<30; i++)
//    {
//        if(buffer[i]==':'&&buffer[i+1]==':')
//        {
//            for(int j=0; j<i; j++)
//                classname[j]=buffer[j];
//            break;
//        }
//        else
//            continue;
//    }
//    String a(classname);
//    cout<<a;

}
