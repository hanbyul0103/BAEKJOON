#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;

	cin >> n >> k;

	vector<int> dp(k + 1);
	vector<int> coins(n);

	for (int i = 0; i < n; i++)
		cin >> coins[i];

	for (int i = 1; i <= k; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (j >= coins[j]) {
				dp[i] = dp[i - coins[i]] + 1;
				break;
			}
		}
	}

	cout << dp[k];
}