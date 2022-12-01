/*
 * AUTHOR: Jacob Tomaszewski
 * Purpose: Generate all possible combinations of a given "set" of characters
 * NOTES: re Set Theory
 *
 * To use just change the character "set" denoted by the cstring/char array set[], to some given group of characters.
 * Then change the length of each combination to however you want. This will then output a list of all possible
 * combinations, if you are looking for proper combination calculations see the combinations' formula.
 * Modify the code as need to meet inclusion/exclusion specifications.
 */

#include <iostream>
#include <string>
using namespace std;


//function prototypes
void str_comb(char[],const string&,int,int);

int main() {
    char set[] = "0123456789";      //set of characters
    int k = 4;                      //length of string
    int n = (*(&set + 1) - set)-1;  //number of characters (NOTE: -1 accounts for \0 present in cstring)
    str_comb(set, "", n, k);
    //EXIT
    return 0;
}

void str_comb(char set[], const string& prefix, int n, int k) {
    if (k == 0) {
        cout << (prefix) << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        string newPrefix;
        newPrefix = prefix + set[i];
        str_comb(set, newPrefix, n, k - 1);
    }
}