#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int dist[301][301];
int dx[8] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int dy[8] = { -1, 1, 2, 2, 1, -1, -2, -2 };

int T, L;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> T;
	while (T--) {
		fill(dist[0], dist[300], -1);
		int a, b;
		pii start;
		int cnt = 0;
		queue<pii> q;
		cin >> L;
		cin >> a >> b;
		start.first = a;
		start.second = b;
		dist[a][b] = 0;
		q.push({ a,b });
		cin >> a >> b;
		if (start.first == a && start.second == b) {
			cout << "0" << '\n';
			continue;
		}
		while (dist[a][b] == -1) {
			pii cur = q.front(); q.pop();
			for (int i = 0; i < 8; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= L || ny < 0 || ny >= L) continue;
				if (dist[nx][ny] != -1) continue;

				dist[nx][ny] = dist[cur.first][cur.second] + 1;
				q.push({ nx,ny });
			}
		}
		cout << dist[a][b] << '\n';

	}
}
