#include <iostream>

int main(){

    long long n, k;
    std::cin >> n >>k;

    long long prev = 0 , curr;
    long long bags = 0;
    long long currbags = 0;
    for(int i =0; i < n; i++){
        std::cin >> curr;
        currbags = (prev+curr) / k;
        if(prev > 0 && currbags < 1 ){
            bags +=1;
            prev = 0;

        } else{
            bags += currbags;
            prev = (prev + curr) % k;

        }
    }

    std::cout << bags + ((prev > 0)? 1 : 0);


    return 0;
}