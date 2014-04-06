#pragma once

#include <set>
#include <string>
#include <istream>
#include <ostream>

#include "Dictionary.h"

// Combinations container
// Contains a sorted sequence of all unique combinations (not permutations),
// that can be made from a string of N characters;
// comb_cont::size() equals 2N-1 or less, if there are repeating characters in the string.
typedef std::set<std::string> comb_cont;

void input_loop(std::istream& input, std::ostream& output, const Dictionary& dict);

void findCombinations(std::string& word, comb_cont& combs);
void printCombinations(const comb_cont& combs, std::ostream& output);

void printEntries(const comb_cont& combs,const Dictionary& dict,std::ostream& output);


