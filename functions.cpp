//
// Created by Viking.Fristrom on 2018-03-28.
//

#include <c++/iostream>
#include <c++/vector>
#include <algorithm>
#include "functions.h"

#include <string>


double is_neigbour(const char &key1, const char &key2, HashNeighbour* table){
    vector <char> neigbours = table[hash_function(key1)].get_neigbours();

    if(std::find(neigbours.begin(), neigbours.end(), key2) != neigbours.end()){
        return 0.5;
    }
    else{
        return 1;
    }
}

vector <char> find_neigbour(const char &key1){
    vector <char> neigbours(8);
    switch (key1){
        case 'q' : neigbours = {'w','s','a',NULL,NULL,NULL,NULL,NULL};
            break;
        case 'w' : neigbours = {'q','a', 's', 'd', 'e',NULL, NULL, NULL};
            break;
        case 'e' : neigbours = {'w', 's', 'd', 'f', 'r', NULL, NULL, NULL};
            break;
        case 'r' : neigbours = {'e', 'd', 'f', 'g', 't', NULL, NULL, NULL};
            break;
        case 't' : neigbours = {'r', 'f', 'g', 'h', 'y', NULL, NULL, NULL};
            break;
        case 'y' : neigbours = {'t', 'g', 'h', 'j', 'u', NULL, NULL, NULL};
            break;
        case 'u' : neigbours = {'y', 'h', 'j', 'k', 'i', NULL, NULL, NULL};
            break;
        case 'i' : neigbours = {'u', 'j', 'k', 'l','o', NULL, NULL, NULL};
            break;
        case 'o' : neigbours = {'i', 'k', 'l', 'ö', 'p', NULL, NULL, NULL};
            break;
        case 'p' : neigbours = {'o', 'l', 'ö', 'ä', 'å', NULL, NULL, NULL};
            break;
        case 'å' : neigbours = {'p', 'ö', 'ä', NULL, NULL, NULL, NULL, NULL};
            break;

        case 'a' : neigbours = {'q', 'w', 's', 'x', 'z',NULL ,NULL, NULL};
            break;
        case 's' : neigbours = {'q', 'w', 'r', 'a', 'f', 'z', 'x', 'c'};
            break;
        case 'd' : neigbours = {'w', 'e', 'r', 's', 'f', 'x', 'c', 'v'};
            break;
        case 'f' : neigbours = {'e', 'r', 't', 'd', 'g', 'c', 'v', 'b'};
            break;
        case 'g' : neigbours = {'r', 't', 'y', 'f', 'h', 'v', 'b', 'n'};
            break;
        case 'h' : neigbours = {'t', 'y', 'u', 'g', 'j', 'b', 'n', 'm'};
            break;
        case 'j' : neigbours = {'y', 'u', 'i', 'h', 'k', 'n', 'm', NULL};
            break;
        case 'k' : neigbours = {'u', 'i', 'o', 'j', 'l', 'm', NULL, NULL};
            break;
        case 'l' : neigbours = {'i', 'o', 'p', 'k', 'ö', NULL, NULL, NULL};
            break;
        case 'ö' : neigbours = {'o', 'p', 'å', 'l', 'ä', NULL, NULL, NULL};
            break;
        case 'ä' : neigbours = {'p', 'å', 'ö', NULL, NULL, NULL, NULL, NULL};
            break;

        case 'z' : neigbours = {'a', 's', 'x', NULL, NULL, NULL, NULL, NULL};
            break;
        case 'x' : neigbours = {'a', 's', 'd', 'z', 'c', NULL, NULL, NULL};
            break;
        case 'c' : neigbours = {'s', 'd', 'f', 'x', 'v', NULL, NULL, NULL};
            break;
        case 'v' : neigbours = {'d', 'f', 'g', 'c', 'b', NULL, NULL, NULL};
            break;
        case 'b' : neigbours = {'f', 'g', 'h', 'v', 'n', NULL, NULL, NULL};
            break;
        case 'n' : neigbours = {'g', 'h', 'j', 'b', 'm', NULL, NULL, NULL};
            break;
        case 'm' : neigbours = {'h', 'j', 'k', 'n', NULL, NULL, NULL, NULL};

        default: neigbours = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
            break;
    }
    return neigbours;
}

int hash_function(const char &letter){

    if ((int(letter) > 96) && int(letter) <123 )
        return  (letter)-97;
    else if (int(letter) == -27)
        return 26;
    else if (int(letter) == -28)
        return 27;
    else if (int(letter) == -10)
        return 28;
    else {
        return 29;
    }
};

HashNeighbour* create_qwerty_hash(){
    const int TABLE_SIZE = 30; // Number of keys (29 + Default option)
    HashNeighbour* table = new HashNeighbour[TABLE_SIZE]; // Allocate memory for table

    const char KEYS[TABLE_SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                                   'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                                   'u', 'v', 'w', 'x', 'y', 'z', 'å', 'ä', 'ö'}; // The alphabet

    for (int i = 0 ; i < TABLE_SIZE ; i++){
        table[i] = HashNeighbour(KEYS[i], find_neigbour(KEYS[i])); // Create a hash entry for each key
    };

    return table;
}

int levenshtien_distance(const string &S1, const string &S2){
    // Store the string sizes
    string s1, s2;
    if(S1.size() < S2.size()){
        s1 = S1;
        s2 = S2;
    }else{
        s1 = S2;
        s2 = S1;
    }
    int s1_len = s1.size();
    int s2_len = s2.size();
    // Initilize the distance vectors
    vector<int> col(s2_len+1), prev_col(s2_len+1);

    // Add data to distance vector
    for (int i = 0 ; i < prev_col.size() ; i++){
        prev_col[i] = i;
    }

    // Calculate levenshtein distance
    for (int i = 0 ; i < s1_len ; i++){
        col[i] = i+1;
        for (int j = 0; j < s2_len; j++) {
            col[j+1] = min(prev_col[j+1]+1, min(col[j]+1, prev_col[j] + (s1[j] == s2[j] ? 0 : 1 )));
        }
        col.swap(prev_col);
    }
    return prev_col[s2_len];
}

double levenshtien_distance_qwerty(const string &S1, const string &S2, HashNeighbour* table){
    // Store the string sizes
    string s1, s2;
    if(S1.size() < S2.size()){
        s1 = S1;
        s2 = S2;
    }else{
        s1 = S2;
        s2 = S1;
    }
    int s1_len = s1.size();
    int s2_len = s2.size();
    // Initilize the distance vectors
    vector<double> col(s2_len+1), prev_col(s2_len+1);

    // Add data to distance vector
    for (int i = 0 ; i < prev_col.size() ; i++){
        prev_col[i] = i;
    }

    // Calculate levenshtein distance
    for (int i = 0 ; i < s1_len ; i++){
        col[i] = i+1.0;
        for (int j = 0; j < s2_len; j++) {
            col[j+1] = min(prev_col[j+1.0]+1.0, min( col[j]+1.0, prev_col[j] + (s1[j] == s2[j] ? 0.0 : is_neigbour(S1[j], S2[j], table)) ));
        }
        col.swap(prev_col);
    }
    return prev_col[s2_len];
}

double overlap_distance(const string &word1, const string &word2, HashNeighbour* table) {
    string full_string, sub_string;
    int big, small;
    double min_distance, sub_distance;
    int length1 = word1.size();
    int length2 = word2.size();

    if (length1 == length2)
        return levenshtien_distance_qwerty(word1, word2, table);
    else if (length1 > length2){
        full_string = word1;
        sub_string = word2;
        big = length1;
        small = length2;
    } else {
        full_string = word2;
        sub_string = word1;
        big = length2;
        small = length1;
    }
    min_distance = big;


    for (int i = 0 ; i <= big-small+1; i++){
        sub_distance = levenshtien_distance_qwerty(sub_string, full_string.substr(i,small), table);
        min_distance = min(min_distance, sub_distance);
    }

    return min_distance;
}



