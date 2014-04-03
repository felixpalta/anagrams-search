#pragma once
#include <stdexcept>
#include <string>

class Filename {
    public:
    Filename(int argc, char* argv[])
    :name_s()
    {
        if (argc < 2) throw std::invalid_argument("Dictionary file name is required");
        name_s = argv[1];
    }
    const std::string& name() {return name_s;}
    private:
    std::string name_s;
};
