#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int input[101][101];
bool visited[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
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
		for (int j = 0; j < N; j++) {
			cin >> input[i][j];
		}
	}
	int cnt = 0;
	int height = 1;
	int res = 0;
	while (height != 100) {
		fill(visited[0], visited[101], false);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (input[i][j] < height || visited[i][j]) continue;
				cnt++;
				queue<pii> q;
				visited[i][j] = true;
				q.push({ i,j });
				while (!q.empty()) {
					pii cur = q.front(); q.pop();
					for (int a = 0; a < 4; a++) {
						int nx = cur.first + dx[a];
						int ny = cur.second + dy[a];

						if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
						if (visited[nx][ny] || input[nx][ny] < height) continue;
						visited[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		res = max(cnt, res);
		cnt = 0;
		height++;
	}
	cout << res;
}
