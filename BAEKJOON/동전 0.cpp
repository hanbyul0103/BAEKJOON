#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int coinAmount, coin, count = 0;

	cin >> coinAmount >> coin;

	vector<int> coins(coinAmount);

	for (int i = 0; i < coinAmount; i++) {
		cin >> coins[i];
	}

	sort(coins.rbegin(), coins.rend());

	for (int i = 0; i < coinAmount; i++) {
		while (coin >= coins[i]) {
			coin -= coins[i];
			count++;
		}
	}

	cout << count;
}