#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int input[301][301];
int cinput[301][301];
bool visited[301][301];
int dx[4] = { -1,1,0,0 };
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
		for (int j = 0; j < M; j++) {
			cin >> input[i][j];
		}
	}
	int time = 0;
	while (1) {
		fill(visited[0], visited[301], false);
		fill(cinput[0], cinput[301], 0);
		// bfs로 빙산 개수 파악
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (input[i][j] == 0 || visited[i][j]) continue;
				cnt++;
				queue<pii> q;
				visited[i][j] = true;
				q.push({ i,j });
				while (!q.empty()) {
					pii cur = q.front(); q.pop();
					for (int a = 0; a < 4; a++) {
						int nx = cur.first + dx[a];
						int ny = cur.second + dy[a];

						if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
						if (visited[nx][ny] || input[nx][ny] == 0) continue;
						visited[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		if (cnt >= 2) { cout << time; break; }
		if (cnt == 0) { cout << 0; break; }
		// 빙산 녹이기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (input[i][j] == 0) continue;
				int water = 0;
				for (int a = 0; a < 4; a++) {
					int nx = i + dx[a];
					int ny = j + dy[a];
					if (input[nx][ny] == 0) water++;
				}
				cinput[i][j] = input[i][j] - water;
				if (cinput[i][j] < 0) cinput[i][j] = 0;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				input[i][j] = cinput[i][j];
			}
		}
		time++;
	}

}
