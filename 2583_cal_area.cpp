#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int M, N, K;
int board[101][101];
bool visited[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> M >> N >> K;
	for (int i = 0; i < M; i++) {
		fill(board[i], board[i] + N, 1);
	}


	for (int i = 0; i < K; i++) {
		pii left = {}, right = {};
		cin >> left.first >> left.second >> right.first >> right.second;
		for (int q = left.second; q < right.second; q++) {
			for (int w = left.first; w < right.first; w++) {
				board[q][w] = 0;
			}
		}
	}
	int cnt = 0;
	vector<int> arealist;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0 || visited[i][j]) continue;
			cnt++;
			queue<pii> q;
			visited[i][j] = true;
			int area = 0;
			q.push({ i, j });
			while (!q.empty()) {
				pii cur = q.front(); q.pop(); area++;
				for (int a = 0; a < 4; a++) {
					int nx = cur.first + dx[a];
					int ny = cur.second + dy[a];

					if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
					if (visited[nx][ny] || board[nx][ny] == 0) continue;

					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
			arealist.push_back(area);
			area = 0;
		}
	}
	sort(arealist.begin(), arealist.end());
	cout << cnt << '\n';
	for (int i : arealist) {
		cout << i << ' ';
	}

}
