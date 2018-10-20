////////////////////Name: Magnets /////////////////////////////
//Problem Link: http://codeforces.com/contest/344/problem/A
//
//Idea: There is at least one group
//      Each time 2 consecutive magnets are not identical, increase a group
////////////////////////////////////////////////////////////

#include <iostream>

int main(){

    int n;
    std::cin >> n;

    int groupsNum = 1;

    int prev, cur;
    std::cin >> prev;
    for (int i =1; i < n; i++){
        std::cin >> cur;
        if(prev != cur){
            groupsNum++;
        }
        prev = cur;
    }

    std::cout<< groupsNum;

    return 0;
}