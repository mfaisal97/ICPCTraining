//Problem Link: http://codeforces.com/contest/734/problem/A

//Parsing string to compare character occurences

//Since only two types, No Need to count both occurences
//because they complement each other
 
//The game condition allows us not to wait till the end to know the result
//instead you may decide earlier somewhere after n/2
//but this will increase the cost if game is decided in the far end (Risky :D)

#include <iostream>

int main(){
    int n;
    std::cin >> n;

    char c;
    int Anton = 0;
    for (int i = 0;  i < n; i++){
        std::cin >> c;
        if (c=='A')
            Anton++;
    }

    if (Anton > (n - Anton))
        std::cout << "Anton";
    else if((n - Anton) > Anton)
        std::cout << "Danik";
    else 
        std::cout << "Friendship";
    return 0;
}