#include <stdexcept>
#include <algorithm>
#include "Dictionary.h"
#include "dictionary_container.h"

using namespace std;

Dictionary::Dictionary(const std::string& filename)
    :   input(filename.c_str()),
        data()
{
    if (!input) throw invalid_argument("Can't open file: " + filename);


    string word;
    string sorted_word;
    while (getline(input,word)){
        sorted_word = word;
        sort(sorted_word.begin(),sorted_word.end());
        data.insert(Dict_pair(sorted_word,word));

    };
}

void Dictionary::printall(ostream& out){
    for (Dict_cont::const_iterator p = data.begin(); p != data.end(); ++p){
        out << p-> first << ": " << p->second << endl;
    }
}
