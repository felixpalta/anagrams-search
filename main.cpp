#include <iostream>
#include <stdexcept>

#include "Filename.h"
#include "Dictionary.h"
#include "input_loop.h"
using namespace std;

int main(int argc, char* argv[])
try
{
    Filename fn(argc,argv);
    Dictionary d(fn.name());
    input_loop(cin,cout,d);

    return 0;
}
catch (exception& e){
    cout << e.what() << endl;
}
catch (...) {
    cout << "Unknown exception" << endl;
}


