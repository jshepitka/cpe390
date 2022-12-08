   
// write your functions below: (Q1-Q3)
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
float sum_forward(int n) {
    float sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += (double) 1/i;
    }
    return sum;
}

float sum_backward(int n) {
    float sum = 0;
    for(int i = n; i > 0; i--) {
        sum += (double) 1/i;
    }
    return sum;
}

float mys_sum_1(int i) {
    float sum = 0;
    for(int x = 1; x <= i; x++) {
        sum += (double) 1/(x*x);
    }
    return sum;
}

float mys_sum_2(uint64_t i) {
    float sum = 0;
    for(uint64_t x = 1; x <= i; x++) {
        sum += (double) 1/(x*x);
    }
    return sum;
}
void demean(float x[], int n) {
    float average = 0;
    for(int i = 0; i < n; i++) {
        average += x[i];
    }
    average = average / n;
    for(int y = 0; y < n; y++) {
        x[y] = x[y] - average;
    }
}


int main(){
    // Q1:
    cout << "sum of 1/1, 1/2, 1/3,...,1/100 = " << sum_forward(100) << endl;

    cout << "sum of 1/100, 1/99, 1/98,...,1/2, 1/1 = " << sum_backward(100) << endl;
  
    // Q2:
    float s1 = mys_sum_1(30000);
    cout << "sqrt(6 * sum) = " << sqrt(6 * s1) << endl;
    
    float s2 = mys_sum_2(100000);
    cout << "sqrt(6 * sum) = " << sqrt(6 * s2) << endl;
    // Q3:
    float arr[] = {3,4,5,6,7,8,9,10};
    demean(arr, 8);
    for (int i = 0; i < 8; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}