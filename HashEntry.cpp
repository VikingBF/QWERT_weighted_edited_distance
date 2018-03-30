w//
// Created by Viking.Fristrom on 2018-03-29.
//

#include "HashEntry.h"

HashNeighbour::HashNeighbour(const char& key_, const std::vector<int> neighbours_ ) {
    const int NUMBER_OF_NEIGBOURS = 8;
    key = key_;
    neighbours.reserve(NUMBER_OF_NEIGBOURS);
    for (int i = 0 ; i < NUMBER_OF_NEIGBOURS ; i++){
        neighbours[i] = neighbours_[i];
    }
}

char HashNeighbour::get_key() {
    return this-> key;
}

std::vector<int> HashNeighbour::get_neigbours() {
    return this-> neighbours;
}

