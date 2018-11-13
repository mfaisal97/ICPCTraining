#include <iostream>

using namespace std;

//T(0) = 0, ai = 1, bi = 8, and T(n) = 8n
double SalesRecursive (int t, double s, double c, double sum){
    if (t==0)
        return s;
    else {
        double d = rand() / double(32767);      //One Operations : Divison
        double R = 0.04* d + 0.98;              //Two Operations : Division and addition
        double val = sum * c*(1+R) / t;         //4   Operations : 2 Multiplication 
        return SalesRecursive(t - 1, val, c, sum + val);        //One Operation : Addition
    }
        
}

double Sales (int t, double x, int c){ //T(t) = 0 + T'(t)
    return SalesRecursive (t, x, c, x);
}

int main(){

    long double x = 5;
    int t = 0;
    double c = 1;

    cout << Sales(t,x,c) << endl;

    system("pause");
    return 0;
}