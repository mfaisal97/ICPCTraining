//Problem Link: http://codeforces.com/contest/791/problem/A

//Idea: Mathematic Problem Based on finding the log

//Possible issues: precedance of operations and possible data loss before promotion.


#include <iostream>

int main(){

    float a,b;
    std::cin>>a>>b;

    int year = 0;
    float Div = a/b;
    float Ratio = 0.3/0.2;
    while(Div <= 1){
        Div = Div *Ratio;
        year++;
        //std::cout << year << "\t" << Div <<"\n";
    }

    std::cout << year;


    return 0;
}