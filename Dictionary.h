#pragma once
#include <fstream>
#include "dictionary_container.h"

class Dictionary {
    public:
    Dictionary(const std::string& filename);
    void printall(std::ostream& out);

    private:
    std::ifstream input;
    Dict_cont data;
};
