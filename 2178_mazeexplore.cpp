#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N, M;
int input[102][102];
int visited[102][102];
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
	string in;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> in;
		for (int j = 0; j < in.size(); j++) {
			input[i][j] = in[j] - '0';
		}
	}
	visited[0][0] = 1;
	bfs.push({ 0, 0 });
	while (!bfs.empty()) {
		pii p = bfs.front(); bfs.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.first + dx[i], ny = p.second + dy[i];
			if (isBound(nx, ny) && input[nx][ny] == 1 && visited[nx][ny] == -1) {
				visited[nx][ny] = visited[p.first][p.second] + 1;
				bfs.push({ nx, ny });
			}
		}
	}


	cout << visited[N - 1][M - 1];
}
