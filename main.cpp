#include <iostream>
#include <stdexcept>

#include "Filename.h"
#include "Dictionary.h"
#include <map>
using namespace std;

int main(int argc, char* argv[])
try
{
    Filename fn(argc,argv);
    Dictionary d(fn.name());
    d.printall(cout);

    return 0;
}
catch (exception& e){
    cout << e.what() << endl;
}
catch (...) {
    cout << "Unknown exception" << endl;
}
