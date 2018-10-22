////////////////////Name: Police Recruits ///////////////////
//Problem Link: http://codeforces.com/contest/427/problem/A
//
//Idea: count number of policemen such that the count is updated
//      if the day change is increase in the policemen 
//      or the number of police men is bigger than zero.
//      Count days when such update is not possible and print it
//
//Note: The crimes per day is limited to max one.
////////////////////////////////////////////////////////////


#include <iostream>

int main(){

    int DaysNum;
    std::cin >> DaysNum;

    int Policemen = 0;
    int Untreated = 0;

    int DayChange;
    for (int i = 0; i < DaysNum; i++){
        std::cin >> DayChange;
        if (Policemen > 0 || DayChange != -1 ){
            Policemen += DayChange;
        } else {
            Untreated++;
        }
    }

    std::cout << Untreated;
    return 0;
}