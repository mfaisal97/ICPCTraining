////////////////////Name: Word /////////////////////////////
//Problem Link: http://codeforces.com/contest/59/problem/A
//
//Idea: Count either upper case letters or lower case ones
//      If only upper case is larger than half (they complement each other)
//      then print each letter in its upper, lower otherwise
//
//Possible issues: Enough to count only one type
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

int main(){
    string word;
    cin >> word;

    int upper = 0;

    for(int i =0; i <word.length(); i++){
        if(isupper(word[i])){
            upper++;
        }
    }

    if(upper > (word.length()/2)){
        for(int i =0; i<word.size(); i++)
            cout << (char)toupper(word[i]);
    } else {
        for(int i =0; i<word.size(); i++)
            cout << (char)tolower(word[i]);
    }

    return 0;
}