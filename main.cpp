#include <iostream>
#include <c++/vector>
#include "functions.h"
int main() {

    HashNeighbour* qwerty_neigbours = create_qwerty_hash();

    string word_a = "kat";
    string word_b = "hat";
    string word_c = "lat";;

    cout << levenshtien_distance(word_a, word_b) << endl;
    cout << levenshtien_distance_qwerty(word_a, word_b, qwerty_neigbours) << endl;
    cout << levenshtien_distance_qwerty(word_a, word_c, qwerty_neigbours) << endl;


    string word = "abcABC";
    string word11 = "abc";
    cout << levenshtien_distance_qwerty(word, word11, qwerty_neigbours) << endl;
    cout << overlap_distance(word, word11, qwerty_neigbours) << endl;
    return 0;
}