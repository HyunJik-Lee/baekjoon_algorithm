#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int input[501][501];
bool visited[501][501];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int N, M;
int cnt, mx;

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
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (input[i][j] == 0 || visited[i][j]) continue;
			cnt++;
			queue<pii> q;
			visited[i][j] = 1;
			q.push({ i,j });
			int area = 0;
			while (!q.empty()) {
				pii cur = q.front(); q.pop(); area++;
				for (int i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if (visited[nx][ny] || input[nx][ny] == 0) continue;
					visited[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
			mx = max(area, mx);
		}
	}
	cout << cnt << '\n' << mx;
}
