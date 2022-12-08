#include <iostream>
using namespace std;

// write your function below
float CombineNumber(int a, int b) {
    double out = 0;
    out = a;
    double temp = b;
    while(temp > 1) {
        temp = temp / 10;
    }
    out += temp;
    cout << "Complete this CombineNumber function." << endl;
    return out;
}

void add(float c[3][4], float a[3][4], float b[3][4]){
  for(int i = 0; i < 3; i++){
      for(int n = 0; n < 4; n++) {
          c[i][n] = a[i][n] + b[i][n];
      }
  }
  cout << "adding matrix a and matrix b:" << endl;
}