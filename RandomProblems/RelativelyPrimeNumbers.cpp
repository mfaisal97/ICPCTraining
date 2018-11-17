#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int gcd (int m, int n) {    // T(n) = 2 + logn
    int k = m % n;

    if (k == 0)
        return n;
    else
        return gcd (n, k);
}

//T(n) <= 3 (n-1)(n-2)/2 + (n-1)^2 log(n-1) - (n-1) log(n-1) -3(n-1) = O(n^2 logn)
int RelativePrimeNumbersInRange(int start, int end, vector<pair<int, int>>& nums){
    int count = 0;

    for (int i = start; i <= end; i++){         //T <= 3 (end-start)(end-start-1)/2 + (end-start)^2 log(end-start) - (end-start) log(end-start) -3(end-start)
        for (int j = 1; j < i; j++){            //T = (3 + logi) (i-1) = 3i + i logi - logi - 3
            if (gcd(i,j) == 1){                 //T(i) = (2 + logi) + 1 = 3 + logi
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