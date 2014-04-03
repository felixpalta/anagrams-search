#pragma once
#include <fstream>
#include <string>
#include <map>

class Dictionary {
    public:

    typedef std::multimap<std::string,std::string> Dict_cont;

    Dictionary(const std::string& filename);

    void printall(std::ostream& out) const;

    const Dict_cont& get_data() const {return data;}
    private:
    typedef std::pair<std::string,std::string> Dict_pair;
    std::ifstream input;
    Dict_cont data;
};
