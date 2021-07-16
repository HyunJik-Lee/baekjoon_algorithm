#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

char board[101][101];
bool visited[101][101];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] != 'R' || visited[i][j]) continue;
			cnt++;
			queue<pii> q;
			visited[i][j] = true;
			q.push({ i,j });
			while (!q.empty()) {
				pii cur = q.front(); q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (visited[nx][ny] || board[nx][ny] != 'R') continue;

					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] != 'B' || visited[i][j]) continue;
			cnt++;
			queue<pii> q;
			visited[i][j] = true;
			q.push({ i,j });
			while (!q.empty()) {
				pii cur = q.front(); q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (visited[nx][ny] || board[nx][ny] != 'B') continue;

					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] != 'G' || visited[i][j]) continue;
			cnt++;
			queue<pii> q;
			visited[i][j] = true;
			q.push({ i,j });
			while (!q.empty()) {
				pii cur = q.front(); q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (visited[nx][ny] || board[nx][ny] != 'G') continue;

					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	cout << cnt << ' ';
	cnt = 0;
	fill(visited[0], visited[100], false);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 'B' || visited[i][j]) continue;
			cnt++;
			queue<pii> q;
			visited[i][j] = true;
			q.push({ i,j });
			while (!q.empty()) {
				pii cur = q.front(); q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (visited[nx][ny] || board[nx][ny] == 'B') continue;

					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] != 'B' || visited[i][j]) continue;
			cnt++;
			queue<pii> q;
			visited[i][j] = true;
			q.push({ i,j });
			while (!q.empty()) {
				pii cur = q.front(); q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (visited[nx][ny] || board[nx][ny] != 'B') continue;

					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	cout << cnt;
}
