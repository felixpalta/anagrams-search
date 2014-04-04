#pragma once
#include <stdexcept>
#include <string>

class Arguments {
    public:
    Arguments(int argc, char* argv[])
    :name_s()
    {
        if (argc < 2) throw std::invalid_argument("Dictionary file name is required");
        name_s = argv[1];
    }
    const std::string& filename() const {return name_s;}
    private:
    std::string name_s;
};
