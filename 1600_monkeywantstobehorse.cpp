#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//int dhx[8] = { -2, -2, -1, 1, 2, 2, 1, -1 };
//int dhy[8] = { -1, 1, 2, 2, 1, -1, -2, -2 };
//int dx[4] = { 1, -1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
int input[201][201];
int dist[31][201][201];

int dx[12] = { 1, -1, 0, 0,-2, -2, -1, 1, 2, 2, 1, -1 };
int dy[12] = { 0, 0, -1, 1,-1, 1, 2, 2, 1, -1, -2, -2 };
int K, W, H;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	fill_n(&dist[0][0][0], 201 * 201 * 31, -1);
	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			cin >> input[i][j];
	}
	queue<pair<int, pii>> q;
	dist[0][0][0] = 0;
	q.push({ 0, {0,0} });
	while (!q.empty()) {
		pair<int, pii> cur = q.front(); q.pop();
		for (int i = 0; i < 12; i++) {
			int nx = cur.second.first + dx[i];
			int ny = cur.second.second + dy[i];
			int horse = cur.first;
			if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
			if (i < 4) {
				if (input[nx][ny] != 0 || dist[horse][nx][ny] != -1) continue;
				dist[horse][nx][ny] = dist[horse][cur.second.first][cur.second.second] + 1;
				q.push({ horse, {nx,ny} });
			}
			else {
				if (input[nx][ny] != 0 || dist[horse + 1][nx][ny] != -1) continue;
				if (horse >= K) continue;
				dist[horse + 1][nx][ny] = dist[horse][cur.second.first][cur.second.second] + 1;
				q.push({ horse + 1, {nx,ny} });
			}

		}

	}
	int mn = 987654321;
	for (int i = 0; i < 31; i++) {
		if (dist[i][H - 1][W - 1] != -1)
			mn = min(dist[i][H - 1][W - 1], mn);
	}
	if (mn == 987654321) cout << -1;
	else cout << mn;

}
