#include <iostream>

using namespace std;

int main() {
	string input;
	int alphabets[26] = { 0 };

	for (int i = 0; i < 26; i++) {
		alphabets[i] = -1;
	}

	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		int index = input[i] - 'a';

		if (alphabets[index] == -1) {
			alphabets[index] = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << alphabets[i] << " ";
	}
}