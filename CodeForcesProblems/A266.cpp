////////////////////Name: Stones on the Table /////////////////////////////
//Problem Link: http://codeforces.com/contest/266/problem/A
//
//Idea: Count the number of each two identical consecutive colors
//
//Potential improvments: Use string instead and iterate on it
//                       to reduce the call over head for input operator
////////////////////////////////////////////////////////////


#include <iostream>

using namespace std;

int main (){

    int StonesNum;
    cin >> StonesNum;

    char prev;
    cin >> prev;

    char cur;
    int removed = 0;
    for (int i =1; i<StonesNum; i++){
        cin >> cur;
        if(cur == prev){
            removed++;
        }
        prev = cur;
    }

    cout << removed;

    return 0;
}