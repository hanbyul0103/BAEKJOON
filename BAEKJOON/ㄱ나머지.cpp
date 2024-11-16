#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> remainVector;

	for (int i = 0; i < 10; ++i) {
		int temp = 0, remain = 0;

		cin >> temp;

		remain = temp % 42;

		find(remainVector.begin(), remainVector.end(), remain);
		remainVector.push_back(remain);
	}

	for (int i = 0; i < remainVector.size(); i++)
	{
		cout << remainVector[i] << " ";
	}
}