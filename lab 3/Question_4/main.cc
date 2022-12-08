#include <iostream>
using namespace std;

double CombineNumber(int a, int b);
void add(float c[3][4], float a[3][4], float b[3][4]);

int main() {
        cout << CombineNumber(3, 4) << '\n';
        cout << CombineNumber(34, 25) << '\n';
	float a[3][4] = {
		{1, 2, 3, 4},
		{3, 4, 5, 6},
		{7, 1, 2, 3}
	};
	float b[3][4] = {
		{1, 2, 3, 4},
		{3, 4, 5, 6},
		{7, 1, 2, 3}
	};
	float c[3][4];
	add(c, a, b); // the add function should compute c = a + b for 3x4 matrices
	cout << "The 3x4 matrices c after add operation is:"<< endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}