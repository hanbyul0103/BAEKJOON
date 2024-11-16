#include <iostream>

bool AllSame(int a, int b, int c) {
	return (a == b) && (b == c);
}

bool AllDiff(int a, int b, int c) {
	return (a != b) && (b != c) && (c != a);
}

bool TwoSame(int a, int b, int c) {
	return (!AllSame(a, b, c) && !AllDiff(a, b, c));
}

int SameNum(int a, int b, int c) {
	if (a == b || a == c) return a;
	else if (b == c) return b;
}

int main() {
	int a, b, c;

	std::cin >> a >> b >> c;

	if (AllSame(a, b, c)) std::cout << 10000 + a * 1000;
	else if (TwoSame(a, b, c)) std::cout << 1000 + SameNum(a, b, c) * 100;
	else if (AllDiff(a, b, c)) std::cout << std::max(a, std::max(b, c)) * 100;
}