#include <iostream>
#include "functions.h"
int main() {
    string b = "ka";
    string a = "katten";
    cout << levenshtien_distance(a, b) <<endl;
    char A = 'a';
    char Q = 'k';
    cout << "are " << A << " and " << Q << " neigbours?" << endl;
    cout << is_neigbour(A,Q);
    return 0;
}