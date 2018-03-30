//
// Created by Viking.Fristrom on 2018-03-29.
//

#ifndef R_FUNCTIONS_HASHENTRY_H
#define R_FUNCTIONS_HASHENTRY_H
#include <string>
#include <c++/vector>
#include <c++/iostream>
class HashNeighbour {

private:
    char key;
    //const int NUMBER_OF_NEIGBOURS = 8;
    std::vector<int> neighbours;


public:
    HashNeighbour(const HashNeighbour& HN) : key(HN.key) , neighbours(HN.neighbours) {}; // Copy constructor
    HashNeighbour(const char& key_, const std::vector<int> neighbours_ ); // Constructor
    ~HashNeighbour(); // Destructor.

    //Member functions
    char get_key();
    std::vector<int> get_neigbours();


};


#endif //R_FUNCTIONS_HASHENTRY_H
