#include <vector>
#include <iostream>
#include <algorithm>
#include "input_loop.h"

using namespace std;


// Read a string from input,
// find all it's unique combinations
// and print dictionary entries, that match those combinations
void input_loop(std::istream& input, std::ostream& output, const Dictionary& dict){

    string word;
    output << "Input words: " << endl;
    while (true){
        output << "> ";
        getline(input,word);
        if (!input) return;

        comb_cont combs;
        findCombinations(word,combs);
        output << "Entries found: " << endl;
        printEntries(combs,dict,output);
    }


}

// Find all unique combinations of a string characters
// and store them in combination container
void findCombinations(const string& word, comb_cont& combs){

    // Temporary combination container
    // Stores all combinations, that can be made from the word
    // Some combinations may repeat, if there are repeating characters in the word.
    // Total number of combinations for a string of length N is 2^N-1.
    typedef vector<string> temp_cont;
    temp_cont v;
    v.push_back(string(1,word.at(0)));  // first simplest combination is a first character of a string

    for (string::size_type i = 1; i < word.size(); ++i){
        temp_cont::size_type vsize = v.size();  // storing the size of a vector for this iteration, before pushing in it.

        for (temp_cont::size_type j = 0; j < vsize; ++j){
            string temp(v.at(j));
            temp += word.at(i); // make a combinations of a current character with all the combinations in the temp_cont
            sort(temp.begin(),temp.end());  // then sort resulting combination by character values
            v.push_back(temp);
        }
        v.push_back(string(1,word.at(i)));
    }

    // Now putting all the combinations in the combinations container
    // It will be sorted and will contain only unique combinations.
    for (temp_cont::size_type k = 0; k < v.size(); ++k)
        combs.insert(v.at(k));

}

void printCombinations(const comb_cont& combs, ostream& output){
    output << "All unique combinations: " << endl;
    int n = 0;
    for (comb_cont::const_iterator comb_p = combs.begin(); comb_p != combs.end(); ++comb_p){
        cout << *comb_p << endl;
        ++n;
    }
    output << "N of unique combinations: " << n << endl;
}

void printEntries(const comb_cont& combs,const Dictionary& dict,std::ostream& output){
    const Dictionary::Dict_cont& data = dict.get_data();

    // searching for combinations in the dictionary

    for (comb_cont::const_iterator comb_p = combs.begin(); comb_p != combs.end(); ++comb_p){

        typedef Dictionary::Dict_cont::const_iterator dict_const_iter;
        std::pair<dict_const_iter, dict_const_iter> range;
        range = data.equal_range(*comb_p);  // there can be several words found for each combination

        for (dict_const_iter dict_p = range.first; dict_p != range.second; ++dict_p){
            output << dict_p->second << endl;
        }

    }
}

