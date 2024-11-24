#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string input1, input2;

	cin >> input1 >> input2;

	sort(input1.rbegin(), input1.rend());
	sort(input2.rbegin(), input2.rend());
}