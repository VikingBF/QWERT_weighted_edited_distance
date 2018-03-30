//
// Created by Viking.Fristrom on 2018-03-28.
//

#include <c++/iostream>
#include <c++/vector>
#include <algorithm>
#include "functions.h"

double is_neigbour (const char &key1, const char &key2){
    vector <int> neigbours(8);
    /*
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
            case 'g'
    }

    */
    if(std::find(neigbours.begin(), neigbours.end(), key2) != neigbours.end()){
        return 0.5;
    }
    else{
        return 1;
    }
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


