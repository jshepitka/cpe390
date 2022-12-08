#include <iostream>
#include <random>
using namespace std;

class vec_3d {
private:
  double x;
  double y;
  double z;
public:
  vec_3d(double x1 = 0, double y1 = 0, double z1 = 0) {
    //this -> x = x1;
    x = x1;
    y = y1;
    z = z1;
  }
  friend vec_3d operator +(vec_3d a, vec_3d b) {
    return vec_3d(a.x + b.x, a.y + b.y, a.z +b.z);
  } 
  friend vec_3d operator -(vec_3d a, vec_3d b) {
    return vec_3d(a.x - b.x, a.y - b.y, a.z - b.z);
  }
  friend vec_3d operator *(vec_3d a, double b) {
    return vec_3d(b*a.x, b*a.y, b*a.z);
  }
  double mag() {
    return sqrt(x*x + y*y + z*z);
  }
  double magsq() {
    return x*x + y*y + z*z;
  }
  double dotprod(vec_3d a, vec_3d b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
  }
};

