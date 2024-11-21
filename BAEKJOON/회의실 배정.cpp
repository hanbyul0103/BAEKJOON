#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, start, end;

	cin >> n;

	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		v[i] = { end, start };
	}

	sort(v.begin(), v.end());

	int endTime = 0, count = 0;

	for (auto& n : v) {
		if () {

			count++;
		}
	}

	cout << cout;
}