////////////////////Name: Word Capitalization //////////////
//Problem Link: http://codeforces.com/contest/281/problem/A
//
//Idea: #SolveMeProblem :D just assure first letter is upper
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

int main(){

    string Word;
    cin >> Word;
    Word[0] = toupper(Word[0]);
    cout << Word;

    return 0;
}