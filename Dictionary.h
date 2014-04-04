#pragma once
#include <fstream>
#include <string>
#include <map>

class Dictionary {
    public:
    // Dictionary container
    // 'key' is a word from dictionary, sorted by character values
    // 'value' is original word from dictionary
    // example: key = "dorw", value = "word"
    // There can be several words with the same key.
    typedef std::multimap<std::string,std::string> Dict_cont;

    Dictionary(const std::string& filename); // fills dictionary with pairs of sorted and unsorted words

    void printall(std::ostream& out) const;

    const Dict_cont& get_data() const {return data;}

    private:
    typedef std::pair<std::string,std::string> Dict_pair;

    std::ifstream input;

    Dict_cont data;
};
