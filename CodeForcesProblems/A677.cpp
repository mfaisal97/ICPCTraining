//http://codeforces.com/contest/677/problem/A


#include <iostream>

int main(){

    int n,h;
    std::cin >> n >>h;

    int x;
    int num = 0;
    for(int i =0; i < n ; i++){
        std::cin >>x;
        num = num + (x>h? 1:0);
    }

    std::cout << n +num;

    return 0;
}