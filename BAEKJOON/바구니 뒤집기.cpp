#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n = 0, m = 0;

    cin >> n >> m;

    vector<int> basketsVector(n);

    for (int i = 0; i < n; i++) {
        basketsVector[i] = i + 1;
    }

    for (int i = 0; i < m; i++) {
        int begin = 0, end = 0;

        cin >> begin >> end;

        reverse(basketsVector.begin() + begin - 1, basketsVector.begin() + end);
    }

    for (int i = 0; i < n; i++) {
        cout << basketsVector[i] << " ";
    }
}
