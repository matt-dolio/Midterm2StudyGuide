#include <iostream>
using namespace std;

int iFib(int n) { // O(n) runtime
	int a = 0, b = 1, c;
	if (n == 0) return a;
	// Utilizes a for loop
	for (int i = 2; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

int rFib(int n) { // O(2^n) runtime, unusable for big n
	if (n == 1 or n == 0) return n;
	else return (rFib(x - 1) + rFib(x - 2));
}
