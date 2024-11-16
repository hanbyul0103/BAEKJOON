#include <iostream>

using namespace std;

int main() {
	bool results[42] = {};
	int count = 0;

	for (int i = 0; i < 10; i++) {
		int input;

		cin >> input;

		int result = input % 42;

		if (results[result]) // 전에 있었으면 건너뛰고
			continue;
		else {
			results[result] = true; // 없었으면 그 위치를 있었다고 체크해주고
			count++; // 카운팅
		}
	}

	cout << count;
}