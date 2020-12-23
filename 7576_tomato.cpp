#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int input[1002][1002];
int visited[1002][1002];
int M, N;
int dx[4] = { -1, 1, 0, 0 }; //상하좌우
int dy[4] = { 0, 0, -1, 1 };
queue<pii> bfs;

bool isBound(int x, int y) {
	return (x >= 0) && (y >= 0) && (x < N) && (y < M);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	memset(visited, -1, sizeof(visited));
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input[i][j];
			if (input[i][j] == 1) {
				bfs.push(make_pair(i, j));
				visited[i][j] = 0;
			}
		}
	}
	while (!bfs.empty()) {
		pii p = bfs.front(); bfs.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = p.first + dx[i];
			int next_y = p.second + dy[i];
			if (isBound(next_x, next_y) && input[next_x][next_y] == 0 && visited[next_x][next_y] == -1) {
				visited[next_x][next_y] = visited[p.first][p.second] + 1;
				bfs.push(make_pair(next_x, next_y));
			}
		}
	}
	int day = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			day = max(day, visited[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == -1 && input[i][j] == 0) {
				day = -1;
				break;
			}
		}
	}



	cout << day << '\n';

}
