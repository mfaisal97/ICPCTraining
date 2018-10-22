//you can just igonre first stored data
//Assuming no team has both same colors


#include <iostream>
#include <vector>

int main(){

    int teamsNums;
    std::cin >> teamsNums;

    int GuestColorsCount [100];
    for (int i = 0; i < 100; i ++){
        GuestColorsCount[i] = 0;
    }

    std::vector<int> HostColors(teamsNums);

    int guest;
    for (int i=0; i < teamsNums; i++){
        std::cin >> HostColors[i] >> guest;
        GuestColorsCount[guest-1]++;
    }

    int conflictsNum = 0;
    for (int i =0; i< teamsNums; i++){
        conflictsNum+= GuestColorsCount[HostColors[i] -1 ];
    }

    std::cout <<conflictsNum;


    return 0;
}