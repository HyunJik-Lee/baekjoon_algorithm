#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char board[1001][1001];
int dist[1001][1001][2];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int N, M;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}
	fill(dist[0][0], dist[1000][1001], -1);
	queue<pair<pii, int>> q;
	dist[0][0][0] = 1;
	q.push({ {0,0},0 });

	while (!q.empty()) {
		pair<pii, int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first.first + dx[i];
			int ny = cur.first.second + dy[i];
			int cnt = cur.second;
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (board[nx][ny] == '1') cnt++;
			if (cnt == 2) continue;
			if (dist[nx][ny][cur.second] != -1 && dist[nx][ny][cnt] != -1) continue;
			dist[nx][ny][cnt] = dist[cur.first.first][cur.first.second][cur.second] + 1;
			q.push({ {nx,ny}, cnt });
		}
	}
	if (dist[N - 1][M - 1][0] != -1 && dist[N - 1][M - 1][1] != -1)
		cout << min(dist[N - 1][M - 1][0], dist[N - 1][M - 1][1]);
	else
		cout << max(dist[N - 1][M - 1][0], dist[N - 1][M - 1][1]);

}
