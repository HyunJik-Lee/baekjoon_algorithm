#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

char input[31][31][31];
int dist[31][31][31];
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };
int L, R, C;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	cin >> L >> R >> C;
	while (L && R && C) {
		for (int i = 0; i < 31; i++) {
			fill(dist[0][0], dist[i][31], -1);
			fill(input[0][0], input[i][31], 0);
		}
		for (int a = 0; a < L; a++) {
			for (int b = 0; b < R; b++) {
				cin >> input[a][b];
			}
		}
		pair<int, pii> start, end;
		for (int a = 0; a < L; a++) {
			for (int b = 0; b < R; b++) {
				for (int c = 0; c < C; c++) {
					if (input[a][b][c] == 'S') start = { a, {b,c} };
					else if (input[a][b][c] == 'E') end = { a, {b,c} };
				}
			}
		}
		queue<pair<int, pii>> q;
		dist[start.first][start.second.first][start.second.second] = 0;
		q.push({ start.first, {start.second.first, start.second.second} });
		while (!q.empty()) {
			pair<int, pii> cur = q.front(); q.pop();
			for (int i = 0; i < 6; i++) {
				int nz = cur.first + dz[i];
				int nx = cur.second.first + dx[i];
				int ny = cur.second.second + dy[i];

				if (nz < 0 || nx < 0 || ny < 0 || nz >= L || nx >= R || ny >= C) continue;
				if (dist[nz][nx][ny] != -1 || input[nz][nx][ny] == '#') continue;
				dist[nz][nx][ny] = dist[cur.first][cur.second.first][cur.second.second] + 1;
				q.push({ nz, {nx,ny} });
			}
		}
		if (dist[end.first][end.second.first][end.second.second] == -1)
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << dist[end.first][end.second.first][end.second.second] << " minute(s).\n";
		cin >> L >> R >> C;
	}


}
