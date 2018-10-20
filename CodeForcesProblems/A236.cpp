////////////////////Name: Boy or Girl ///////////////////////
//Problem Link: http://codeforces.com/contest/236/problem/A
//
//Idea: Store only the information about which characters existed
//      Depnding on their number decide the answer.
//      It can be done also using sets
//      but we know already max num of elements is small
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

int main(){
    const int AlphabetSize = 26;

    bool notVisited[AlphabetSize];
    int distinct;

    for (int i =0; i < AlphabetSize; i++){
        notVisited[i] = true;
    }

    std::string name;
    std::cin >> name;

    int ind;
    for (int i = 0; i < name.length(); i++){
        ind  = name[i] - 'a';

        if(notVisited[ind]){
            distinct++;
            notVisited[ind] = false;
        }
    }

    if(distinct%2){
        std::cout << "CHAT WITH HER!";
    } else {
        std::cout << "IGNORE HIM!";
    }

    return 0;
}