#include <iostream>
using namespace std;

/*
CPE-390 A
Assignment 1
John Shepitka
*/

uint64_t sum(int a, int b) {
	uint64_t s = 0;
	for (int i = a; i <= b; i++)
		s += i;
	return s;
}

double fact(int n) {
	double prod = 1;
	for (int i = 1; i <= n; ++i)
		prod *= i;
	return prod;
}

// note: const int x[] is just promising that we are only reading the array x
// it is not the source of the error!
int sumArray(const int x[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += x[i];
	return sum;
}

int main() {
	cout << sum(1, 3) << '\n';
	cout << sum(5, 10) << '\n';
	cout << sum(1, 1000000) << '\n';
	cout << fact(5) << '\n';
	cout << fact(10) << '\n';
	cout << fact(20) << '\n';
	cout << fact(24) << '\n';
	cout << fact(50) << '\n';
	int a[] = {1, 2, 3, 4};
	int b[] = {9, 8, 7, 1, 3};
	cout << sumArray(a, 4) << '\n';
	cout << sumArray(b, 5) << '\n';
}