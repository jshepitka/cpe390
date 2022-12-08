#include <iostream>
#include <math.h>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

struct Point{
    double x, y;
    Point(){
        x = 0;
        y = 0;
    }
    Point(double a, double b){
        x = a;
        y = b;
    }
};

bool isPrime(int a) {
  for(int i = 2; i < a; i++) {
    if(a%i == 0){
      cout << "false" << endl;
      return false;
      
      }
  }
  cout << "true" << endl;
  return true;
}
int sum(int a, int b){
  int sum = 0;
  for(int i=a; i <= b; i++){
    sum += i;
  }
  return sum;
}
int min(int x[], int n) {
  int min = x[0];
  for(int i = 0; i < n; i++) {
    int hello = x[i];
    if(hello < min) {
      min = hello;
    }
  }
  return min;
}
int prod(int x[], int n) {
  int product = x[0];
  if(n == 1){
    return x[0];
  }
  else if(n == 2) {
    product = product * x[1];
    return product;
  }
  else{
    for(int i = 1; i < n; i++){
      product = product * x[i];
    }
  }
  return product;
}
Point midpoint(Point p1, Point p2){
    double midX = 0;
    double midY = 0;
    
    if(p1.x < p2.x){
      midX = p2.x - p1.x;
    }
    else {
      midX = p1.x - p2.x;
    }
    if(p1.y < p2.y) {
      midY = p2.y - p1.y;
    }
    else {
      midY = p1.y - p2.y;
    }
    return Point(midX, midY);
};



int main(){
  int arr[] = {1, 4, 3, 2};// n = 4
  int arr2[] = {5, 6, 7, 8, 9, 10, 2, 1};//n = 8
    int arr3[6] = {1, 2, 3, 4, 5, 6};//n = 6
    int arr6[] = {1,2,3,4,5,6,7}; // n = 7
    int arr66[] = {1,2,3,4,5,6,7};
    int r1[] = {1, 2, 3, 4, 5, 6, 7}; // n = 7
    int r2[] = {1, 2, 3, 4, 5, 6, 7, 8};// n = 8
//2.----------------------------------------
  
  cout << "isPrime(5)=" << isPrime(5) << '\n';
  
  cout << sum(1, 3) << ' ' << sum(1, 10)
       << '\n'; // should work no problem, right?
  cout << sum(1, 1000000)
       << '\n'; // what should this be? Don't assume it's right, check!
  cout << "arr prod=" << prod(arr, 4) << '\n';
  cout << "arr prod=" << prod(arr2, 8) << '\n';
  Point midP = midpoint(Point(0.7, 0.9), Point(3.4, 12.1));
  cout << "the midpoint between two point is: " << midP.x << "," << midP.y <<'\n';
  return 1;
}