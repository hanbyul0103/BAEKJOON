#include <iostream>

using namespace std;

int main() {
	bool results[42] = {};
	int count = 0;

	for (int i = 0; i < 10; i++) {
		int input;

		cin >> input;

		int result = input % 42;

		if (results[result]) // ���� �־����� �ǳʶٰ�
			continue;
		else {
			results[result] = true; // �������� �� ��ġ�� �־��ٰ� üũ���ְ�
			count++; // ī����
		}
	}

	cout << count;
}