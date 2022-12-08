#include <iostream>
using namespace std;

int main() {
  for (int a = 0; a < 10; a++) 
		cout << a << ' ';
  cout << '\n';

  for (uint8_t i = 1; i < 10; i++) 
		cout << i << ' ';
  cout << '\n';

  // this will fail here (infinite loop)
  // for (uint8_t i = 0; i < 1000; i++)
	
	//on the arduino, this will fail! works here
  for (int i = 0; i < 1000; i++)
    ;
  for (int i = 10; i >= 0; i--) {
    cout << i;
    }
    cout << "blastoff\n";
    for (int i = 10; i < 0; i--){
			
			
			
		} 
}