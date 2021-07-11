#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int field[2501][2501];
bool visited[2501][2501];
int T, M, N, K;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> T;
	while (T--) {

		fill(field[0], field[2500], 0);
		fill(visited[0], visited[2500], false);
		int cnt = 0;
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int a = 0, b = 0;
			cin >> a >> b;
			field[a][b] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] || field[i][j] != 1) continue;
				cnt++;
				queue<pii> q;
				visited[i][j] = true;
				q.push({ i,j });

				while (!q.empty()) {
					pii cur = q.front(); q.pop();
					for (int a = 0; a < 4; a++) {
						int nx = cur.first + dx[a];
						int ny = cur.second + dy[a];

						if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
						if (visited[nx][ny] || field[nx][ny] == 0) continue;
						visited[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		cout << cnt << '\n';
		cnt = 0;
	}
}
