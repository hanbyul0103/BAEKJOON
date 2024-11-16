#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int students[31] = { {0} };

	for (int i = 0; i < 28; ++i) {
		int temp;

		cin >> temp;

		students[temp] = temp;
	}

	for (int i = 1; i < 31; ++i)
	{
		if (students[i] == 0) cout << i << "\n";
	}
}