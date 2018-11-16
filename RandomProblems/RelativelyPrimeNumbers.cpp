#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int gcd (int m, int n) {
    int k = m % n;

    if (k == 0)
        return n;
    else
        return gcd (n, k);
}

int RelativePrimeNumbersInRange(int start, int end, vector<pair<int, int>>& nums){
    int count = 0;

    for (int i = start; i <= end; i++){
        for (int j = 1; j < i; j++){
            if (gcd(i,j) == 1){
                nums.push_back(pair<int,int>(i,j));
                ++count;
            }
        }
    }

    return count;
}


int main(){

    vector<pair<int, int>> nums;
    int n;
    cin >>n;
    
    RelativePrimeNumbersInRange(1, n, nums);

    for (pair<int, int>& memo : nums){
        cout << memo.first << "\t" << memo.second << "\n";
    }

    return 0;
}