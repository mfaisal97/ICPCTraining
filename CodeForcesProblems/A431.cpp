////////////////////Name: Black Square ///////////////////
//Problem Link: http://codeforces.com/contest/431/problem/A
//
//Idea: Count the occurence of each square
//      Print the summation of each suqare's count * its cost
////////////////////////////////////////////////////////////


#include <iostream>
#include <string>

int main(){

    int cost[4] = {0,0,0,0};
    int count[4] = {0,0,0,0};
    std::cin >> cost[0] >> cost[1] >> cost[2] >> cost[3];

    std::string steps;
    std::cin >> steps;

    for(int i = 0; i< steps.length() ; i++){
        count[steps[i] - '1'] ++;
    }

    std::cout << (cost[0] * count[0]) + (cost[1] * count[1]) + (cost[2] * count[2]) + (cost[3] * count[3]);
    return 0;
}