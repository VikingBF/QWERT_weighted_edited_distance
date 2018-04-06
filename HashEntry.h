//
// Created by Viking.Fristrom on 2018-03-29.
//

#ifndef R_FUNCTIONS_HASHENTRY_H
#define R_FUNCTIONS_HASHENTRY_H

class HashNeighbour {

private:
    char key; // Key
    const int NUMBER_OF_NEIGBOURS = 8; // The number of neigbouring keys on the keyboard
    std::vector<char> neighbours; // Vector with the


public:
    HashNeighbour();
    HashNeighbour(const HashNeighbour& HN) : key(HN.key) , neighbours(HN.neighbours) {}; // Copy constructor
    HashNeighbour(const char& key_, const std::vector<char> neighbours_ ); // Constructor
    ~HashNeighbour() {}; // Destructor.

    // Overloaded Operators
    HashNeighbour operator=(const HashNeighbour&);

    //Member functions
    const char get_key();
    const std::vector<char> get_neigbours();
    void print_key();
    void print_neigbours();

};


#endif //R_FUNCTIONS_HASHENTRY_H
