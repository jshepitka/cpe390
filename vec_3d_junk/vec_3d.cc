#include "vec_3d.hh"
#include <random>
#include <iostream>

using namespace std;



int main() {
  vec_3d a(1.0, 2.5, 3.2);
  vec_3d b(1.5, 2.1); // z should default to 0
  vec_3d c = a + b; // define addition using the friend syntax we reviewed in class.
  vec_3d d = a - b; // very similar to addition
  vec_3d e = a * 2.0; // implement scalar multiplication by a double
  double m = a.mag(); // return the length of the vector (absolute value)
  double msq = a.magsq(); // return the length of the vector, squared
  double dotprod = dot(a,b); // compute the dot product  a.x*b.x + a.y*b.y + ...  //LATER vec_3d f = vec_3d::random_unit_2d(); // create a random unit vector in 2d (z=0)
  //LATER vec_3d g = vec_3d::random_unit(); // create a random unit vector pointing anywhere

  cout << a << '\n'; 
  cout << b << '\n';
  cout << c << '\n'; 
  cout << d << '\n'; 
  cout << e << '\n';
//  cout << f << '\n'; 
//  cout << g << '\n'; 

  cout << m << '\n';
  cout << msq << '\n';
  cout << dotprod << '\n';
}
