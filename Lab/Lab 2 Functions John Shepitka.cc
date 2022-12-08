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
      return false;
      }
  }
  return true;
}
int sum(int a, int b);
int min(int x[], int n);
int prod(int x[], int n);
Point midpoint(Point p1, Point p2){
  
  
};



int main(){
//2.----------------------------------------
  
  cout << "isPrime(1001)=" << isPrime(1001) << '\n';
  /*
  cout << sum(1, 3) << ' ' << sum(1, 100)
       << '\n'; // should work no problem, right?
  cout << sum(1, 1000000)
       << '\n'; // what should this be? Don't assume it's right, check!
  cout << "arr max=" << min(arr, 4) << '\n';
  cout << "arr max=" << min(arr2, 8) << '\n';
  cout << "arr prod=" << prod(arr, 4) << '\n';
  cout << "arr prod=" << prod(arr2, 8) << '\n';
  Point midP = midpoint(Point(0.7, 0.9), Point(3.4, 12.1));
  cout << "the midpoint between two point is: " << midP.x << "," << midP.y <<'\n';
  */
  return 0;
}