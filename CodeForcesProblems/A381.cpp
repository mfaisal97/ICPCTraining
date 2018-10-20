////////////////////Name: Sereja and Dima /////////////////////////////
//Problem Link: http://codeforces.com/contest/381/problem/A
//
//Idea: Store the entered nums and then ckeck the boundaries
//      To get last value then update the boundaries
//      To Reflect non taken elements
//
//Note: If the values are not distinct, then you would have to
//      make sure that overall you take the largest values
//      not just the largest in each turn.
////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

int main(){

    int n;
    std::cin >> n;

    int Start = 0, End = n-1;
    std::vector<int> Cards(n,0);
    for(int i = Start; i <= End; i++){
        std::cin >> Cards[i];
    }

    int Sereja =0, Dima =0;

    int iter = 0;
    int wonAmount;
    while(Start <= End){

        if(Cards[Start] > Cards[End]){
            wonAmount = Cards[Start];
            Start++;
        }else{
            wonAmount = Cards[End];
            End--;
        }

        if(iter%2){
            Dima += wonAmount;
        }else{
            Sereja += wonAmount;
        }
        iter++;
    }

    std::cout << Sereja << " " << Dima;

    return 0;
}