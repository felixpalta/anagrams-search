#pragma once

#include <set>
#include <string>
#include <istream>
#include <ostream>

#include "Dictionary.h"



typedef std::set<std::string> comb_cont;

void input_loop(std::istream& input, std::ostream& output, const Dictionary& dict);

void findCombinations(const std::string& word, comb_cont& combs);

void printEntries(const comb_cont& combs,const Dictionary& dict,std::ostream& output);
