#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char input[1001][1001];
int fdist[1001][1001];
int sdist[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int T, w, h;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> T;
	while (T--) {
		fill(fdist[0], fdist[1001], -1);
		fill(sdist[0], sdist[1001], -1);
		cin >> w >> h;
		bool flag = false;
		for (int i = 0; i < h; i++) {
			cin >> input[i];
		}
		queue<pii> q;
		pii start;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (input[i][j] == '@') {
					start.first = i;
					start.second = j;
				}
				else if (input[i][j] == '*') {
					fdist[i][j] = 0;
					q.push({ i,j });
				}
			}
		}
		// 불 bfs
		while (!q.empty()) {
			pii cur = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (input[nx][ny] == '#' || fdist[nx][ny] != -1) continue;
				fdist[nx][ny] = fdist[cur.first][cur.second] + 1;
				q.push({ nx, ny });
			}
		}
		// 상근 bfs
		sdist[start.first][start.second] = 0;
		q.push(start);
		while (!q.empty()) {
			pii cur = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
					//탈출완료!!!!..
					cout << sdist[cur.first][cur.second] + 1 << '\n';
					flag = true;
					break;
				}
				if (input[nx][ny] == '#' || sdist[nx][ny] != -1) continue;
				if (fdist[nx][ny] != -1 && sdist[cur.first][cur.second] + 1 >= fdist[nx][ny]) continue;
				sdist[nx][ny] = sdist[cur.first][cur.second] + 1;
				q.push({ nx,ny });
			}
			if (flag) {
				break;
			}
		}
		if (!flag) cout << "IMPOSSIBLE\n";
	}
}
