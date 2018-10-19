//Problem Link: http://codeforces.com/contest/231/problem/A

//Idea: Count occurences of a predefinied repeated structure with elements having some minimum sum

//Possible issues: Notice usage of variables for each smaller element
//                 using a variable and iterate to get the sum will overhead.

#include <iostream>

int main(){
    int n;
    int ToBeSolved = 0;

    int Petya, Vasya, Tonya;

    std::cin >> n;
    for (int i =0; i < n; i++){
        std::cin >> Petya >> Vasya >> Tonya;
        if((Petya + Vasya + Tonya) >= 2 )
            ToBeSolved++;
    }

    std::cout << ToBeSolved;

    return 0;
}