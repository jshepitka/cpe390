#include <cstdint>
#include <iostream>

typedef uint64_t u64;

int main() { 
	uint32_t a = 1234567890;	//fits, max = 4.2 billion
  u64 b = 123456789012345678ULL; // big unsigned integer

  int age;
  cout << "Please enter your age:	";
  cin >> age;

  int ageInSeconds = age * 365 * 24 * 60 * 60;
  cout << ageInSeconds << '\n';
}