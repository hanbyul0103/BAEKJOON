#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int BFS(vector<vector<int>>& map, int startX, int startY, int endX, int endY) {
	queue<pair<int, int>> q;

	int n = map.size();
	int m = map[0].size();

	vector<vector<int>> memo(n, vector<int>(m, 0));

	q.push({ startX, startY });
	memo[startX][startY] = 1;

	while (!q.empty()) {
		pair<int, int> current = q.front();
		q.pop();

		if (current.first == endX && current.second == endY) {
			return memo[endX][endY]; // 시작점부터의 거리
		}

		for (int i = 0; i < 4; ++i) { // 네 방향 체크
			int nx = current.second + dx[i];
			int ny = current.first + dy[i];

			// 맵을 넘어섰거나, 벽이거나, 이미 간 적이 있는 곳을 방문하지 않게
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || map[ny][nx] == 1 || memo[ny][nx])
				continue;

			memo[ny][nx] = memo[current.first][current.second] + 1; // 거리 업데이트
			q.push({ ny, nx }); // 새 위치를 큐에 삽입
		}
	}
	return -1; // 경로가 존재하지 않을 경우
}

int main() {
	int n, m;
	int startX, startY, endX, endY;

	cin >> n;
	m = n;

	vector<vector<int>> map(n, vector<int>(m));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> map[i][j];

	cin >> startX >> startY >> endX >> endY;

	cout << BFS(map, startX - 1, startY - 1, endX - 1, endY - 1);
}