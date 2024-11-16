#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int repeat = 0;
	float sum = 0;

	cin >> repeat;

	float* points = new float[repeat];

	for (int i = 0; i < repeat; i++) {
		cin >> points[i];
	}

	float max = *max_element(points, points + repeat);

	for (int i = 0; i < repeat; i++) {
		points[i] = (points[i] / max) * 100.0f;

		sum += points[i];
	}

	cout << sum / repeat;

	delete[] points;
}