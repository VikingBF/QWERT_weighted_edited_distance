//
// Created by Viking.Fristrom on 2018-03-29.
//
#include <string>
#include <c++/vector>
#include <c++/iostream>
#include "HashEntry.h"

HashNeighbour::HashNeighbour(){
    key = 'a';
    neighbours = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};
};

HashNeighbour::HashNeighbour(const char& key_, const std::vector<char> neighbours_ ) {
    key = key_;
    neighbours.reserve(NUMBER_OF_NEIGBOURS);
    for (int i = 0 ; i < NUMBER_OF_NEIGBOURS ; i++){
        neighbours[i] = neighbours_[i];
    }
}

HashNeighbour HashNeighbour::operator=(const HashNeighbour& RHS) {
    key = RHS.key;
    for (int i = 0; i < NUMBER_OF_NEIGBOURS ; i++) {
        neighbours[i] = RHS.neighbours[i];
    }
    return *this;
};


const char HashNeighbour::get_key() {
    return this-> key;
}

const std::vector<char> HashNeighbour::get_neigbours() {
    return this-> neighbours;
}

void HashNeighbour::print_key() {
    std::cout << "The key is: " << key << std::endl;
};

void HashNeighbour::print_neigbours() {
    std::cout << "The Neigbours are:" << std::endl;
    for (int i = 0 ; i < NUMBER_OF_NEIGBOURS ; i++)
        std:: cout << neighbours[i];
};