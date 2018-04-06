//
// Created by Viking.Fristrom on 2018-03-28.
//

#ifndef R_FUNCTIONS_FUNCTIONS_H
#define R_FUNCTIONS_FUNCTIONS_H

#include "HashEntry.h"

using namespace std;

vector <char> find_neigbour(const char &key1);
double is_neigbour (const char &key1, const char &key2, HashNeighbour* table);
int levenshtien_distance(const string &s1, const string &s2);
double levenshtien_distance_qwerty(const string &S1, const string &S2, HashNeighbour* table);
double overlap_distance(const string &word1, const string &word2, HashNeighbour* table);
int hash_function(const char &letter);
HashNeighbour* create_qwerty_hash();

#endif //R_FUNCTIONS_FUNCTIONS_H
