#include <vector>
#include <iostream>
#include "input_loop.h"

using namespace std;



void input_loop(std::istream& input, std::ostream& output, const Dictionary& dict){

    string word;
    output << "Input words: " << endl;
    while (getline(input,word)){
        comb_cont combs;
        findCombinations(word,combs);
        output << "Entries found: " << endl;
        printEntries(combs,dict,output);
    }


}

void findCombinations(const string& word, comb_cont& combs){



    typedef vector<string> temp_cont;
    temp_cont v;
    v.push_back(string(1,word.at(0)));

    for (string::size_type i = 1; i < word.size(); ++i){
        temp_cont::size_type vsize = v.size();

        for (temp_cont::size_type j = 0; j < vsize; ++j){
            string temp(v.at(j));
            temp += word.at(i);

            v.push_back(temp);
        }

        v.push_back(string(1,word.at(i)));

    }


    for (temp_cont::size_type k = 0; k < v.size(); ++k) combs.insert(v.at(k));

    //combs now contains all unique combinations of the word letters, and they are sorted

}

void printEntries(const comb_cont& combs,const Dictionary& dict,std::ostream& output){
    const Dictionary::Dict_cont& data = dict.get_data();

    for (comb_cont::const_iterator comb_p = combs.begin(); comb_p != combs.end(); ++comb_p){

        typedef Dictionary::Dict_cont::const_iterator dict_const_iter;
        std::pair<dict_const_iter, dict_const_iter> range;
        range = data.equal_range(*comb_p);

        for (dict_const_iter dict_p = range.first; dict_p != range.second; ++dict_p){
            output << dict_p->second << endl;
        }

    }
}

