#include <iostream>

using namespace std;

int main() {
	int count = 0, size = 0;
	int begin = 0, end = 0, num = 0;

	cin >> size >> count;

	int buckets[101] = { 0 };
	fill_n(buckets, size + 1, 0);

	for (int i = 0; i < count; i++)
	{
		cin >> begin >> end >> num;

		for (int b = begin; b <= end; b++) {
			buckets[b] = num;
		}
	}

	for (int i = 1; i <= size; i++) {
		cout << buckets[i] << " ";
	}
}