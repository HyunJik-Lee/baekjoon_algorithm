#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, M;
char board[1001][1001];
int Fdist[1001][1001];
int Jdist[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

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
	queue<pii> q;
	pii jstart = { 0,0 };
	fill(Fdist[0], Fdist[1001], -1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 'J')
				jstart = { i,j };
			else if (board[i][j] == 'F') {
				Fdist[i][j] = 0;
				q.push({ i,j });
			}
		}
	}

	while (!q.empty()) {
		pii cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (Fdist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			Fdist[nx][ny] = Fdist[cur.first][cur.second] + 1;
			q.push({ nx,ny });
		}
	}
	fill(Jdist[0], Jdist[1001], -1);
	Jdist[jstart.first][jstart.second] = 0;
	q.push(jstart);
	while (!q.empty()) {
		pii cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
				cout << Jdist[cur.first][cur.second] + 1;
				return 0;
			}
			if (Jdist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			if (Fdist[nx][ny] != -1 && Fdist[nx][ny] <= Jdist[cur.first][cur.second] + 1) continue;
			Jdist[nx][ny] = Jdist[cur.first][cur.second] + 1;
			q.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";

}
