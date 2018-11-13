//Brute Force algorithm to determine whether a number is prime or not
//Done within the CSCE 321 Algorithms Analysis and design Course
//In the American University in Cairo during Fall 2018
//and taught by Dr Amr Goneid and graduate TA Eng. Ahmed Haitham

#include <iostream>

using namespace std;

//T'(n) = 4 * (n-2) + 1
bool Factor_In_Range(int k, int n){     //For Each iteration, there are 2 comparisons and 2 arithmetic operations .. excpet for the last one
    if(k>=n)                            //one comparison
        return false;
    else if (n%k == 0)                  //one arithmetic operation and one comparison
        return true;
    else
        return Factor_In_Range(k+1, n); //One arithmetic operations
}

bool IsPrime(int n){    //T(n) = 1 + T'(n) = 1 + (4n - 8 + 1) = 4n -6 = O(n)
    return (n>1) && !Factor_In_Range(2,n);      //One Comparison
}

int main(){
    int n;
    cout <<"Enter Number: ";
    cin >> n;

    cout << n <<" is Prime: " << (IsPrime(n) ? "True" : "False") << endl;

    system("pause");
    return 0;
}