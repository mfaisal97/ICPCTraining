////////////////////Name: Gravity Flip ////////////////////
//Problem Link: http://codeforces.com/contest/405/problem/A
//
//Idea: Since we know that each block would stay in his level
//      and also no columns would have empty blocks
//      and number of blocks are constant, 
//      we have a simple ascending sorting problem
//
//Possible issues: Not implementing the problem with dynamic array
//           also: Not knowing the functions in the algoritm class
////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    int n =1;
    std::cin >> n;

    std::vector<int> Nums(n,1);

    for(int i =0; i < n; i++){
        std::cin >> Nums[i];
    }

    std::sort(Nums.begin(), Nums.end());

    for(int i=0; i < n; i++){
        std::cout << Nums[i] << " ";
    }

    return 0;
}