#include <iostream>
#include <exception>

#include "Arguments.h"
#include "Dictionary.h"
#include "input_loop.h"

using namespace std;

int main(int argc, char* argv[])
try
{
    Arguments arg(argc,argv);   // deal with arguments
    Dictionary d(arg.filename());   // create dictionary
    input_loop(cin,cout,d); // parse input

    return 0;
}
catch (exception& e){
    cout << e.what() << endl;
    return 1;
}
catch (...) {
    cout << "Unknown exception" << endl;
    return 2;
}


