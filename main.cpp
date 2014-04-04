#include <iostream>
#include <stdexcept>

#include "Arguments.h"
#include "Dictionary.h"
#include "input_loop.h"

using namespace std;

int main(int argc, char* argv[])
try
{
    Arguments arg(argc,argv);
    Dictionary d(arg.filename());
    input_loop(cin,cout,d);

    return 0;
}
catch (exception& e){
    cout << e.what() << endl;
}
catch (...) {
    cout << "Unknown exception" << endl;
}


