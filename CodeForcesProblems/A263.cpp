//Problem Link: http://codeforces.com/contest/263/problem/A

//Idea: Find the coordinates of an element in a 2d like-array data
//      and calculate the abosulate difference from its center (Manhattan Distance)

//Possible Issues: Wrong implementation of the Manhattan distance calculation

#include <iostream>

int main(){

    int i_target, j_target;

    const int SIZE = 5;
    const int pivot = 3;
    const int BEGIN = 1;
    int ele;
    for (int i = BEGIN; i <= SIZE; i++){
        for (int j = BEGIN; j <= SIZE; j++){
            std::cin >> ele;
            if(ele==1){
                i_target = i;
                j_target = j;
                while(i<= SIZE){
                    std::cin.ignore(INT_MAX, '\n');
                    i++;
                }
                break;
            }
        }
    }

    std::cout << ((i_target > pivot)? i_target - pivot : pivot - i_target) + ((j_target > pivot) ? j_target - pivot : pivot - j_target);

    return 0;
}