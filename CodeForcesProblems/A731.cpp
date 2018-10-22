////////////////////Name: Night at the Museum ///////////////////
//Problem Link: http://codeforces.com/contest/731/problem/A
//
//Idea: initialize total moves to zero.
//      Each time, you have the abosulte value of the 
//      difference between two consecutive moves less than 13
//      (which is half cost of the complete cycle), add it
//      Otherwise subtract it from 26 nd add the result to the total moves.
// 
//Note: Coverage of both direcctions (clockwise and counter clockwise)
//      Also coverage of the idea that char are not necessarily increasing.
////////////////////////////////////////////////////////////



#include <iostream>
#include <string>

int main (){

    std::string Word;
    std::cin >> Word;

    int steps= ((Word[0] - 'a') > 13 )? (26 - (Word[0] - 'a')) : (Word[0] - 'a');

    int curstep;
    for(int i =1; i < Word.length(); i++){
        curstep = (Word[i] - Word[i-1]);
        curstep = (curstep < 0) ? (-1 * curstep) : curstep;
        steps += ( curstep > 13 )? (26 - curstep) : curstep;
    }

    std::cout << steps;

    return 0;
}