#include <iostream>

using namespace std;

int main() {
	int bucketCount = 0, exchangeCount = 0, temp = 0;
	int buckets[101];

	cin >> bucketCount >> exchangeCount;

	fill_n(buckets, bucketCount, 0);

	for (int i = 0; i < bucketCount; i++)
	{
		buckets[i] = i + 1;
	}

	for (int i = 0; i < exchangeCount; i++) {
		int beginPoint = 0, endPoint = 0;

		cin >> beginPoint >> endPoint;

		swap(buckets[beginPoint - 1], buckets[endPoint - 1]);
	}

	for (int i = 0; i < bucketCount; i++)
	{
		cout << buckets[i] << " ";
	}
}