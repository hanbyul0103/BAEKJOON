#include <iostream>
#include <vector>

using namespace std;

int fibonacci[101] = { 0, 1 };

long Fibonacci(long value) {
	if (value <= 1 || fibonacci[value] != 0) return fibonacci[value];
	else {
		fibonacci[value] = Fibonacci(value - 1) + Fibonacci(value - 2);
		return fibonacci[value];
	}
}

int main() {
	int count;
	cin >> count;
	cout << Fibonacci(count);
}

// Àç±ÍX
//#include <iostream>
//
//using namespace std;
//
//int main() {
//	vector<int> fibonacci = { 0, 1 };
//	int count;
//
//	cin >> count;
//
//	for (int i = 0; i < count - 1; i++) {
//		fibonacci.push_back(fibonacci[i] + fibonacci[i + 1]);
//	}
//
//	cout << fibonacci.back();
//}