#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<pair<int, bool>> integers(3);
	bool isAllEven = true;
	int sum = 1;

	for (int i = 0; i < integers.size(); i++) {
		int temp;

		cin >> temp;

		integers[i] = { temp,  temp % 2 != 0 };

		if (integers[i].second) isAllEven = false;
	}

	for (int i = 0; i < 3; i++) {
		if (isAllEven) {
			if (!integers[i].second) {
				sum *= integers[i].first;
			}
		}
		else {
			if (integers[i].second) {
				sum *= integers[i].first;
			}
		}
	}

	cout << sum;
}