#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
/*
2 2 map 인경우 (y,x)
# # (0,0) (0,1)
# # (1,0) (1,1)

3 3 map 인경우 (y,x)
# # # 00 01 02
# # # 10 11 12
# # # 20 21 22

*/
// 상, 하, 좌, 우, 좌상, 우상, 좌하, 우하
int dy[8] = { -1,1,0,0,-1,-1,1,1 };
int dx[8] = { 0,0,-1,1,-1,1,-1,1 };
int num = 0;
int landmap[51][51];
int visited[51][51];


int isBound(int y, int x, int w, int h) {
	return (x >= 0) && (y >= 0) && (x < w) && (y < h);
}

void dfs(int y, int x, int w, int h) {
	if (landmap[y][x] == 0) return;
	visited[y][x] = 1;
	for (int i = 0; i < 8; i++) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];
		if (isBound(next_y, next_x, w, h) && landmap[next_y][next_x] && !visited[next_y][next_x]) {
			visited[next_y][next_x] = 1;
			dfs(next_y, next_x, w, h);
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int w = 0, h = 0;
	cin >> w >> h;
	while (w && h) {
		num = 0;
		fill(&landmap[0][0], &landmap[50][51], 0);
		fill(&visited[0][0], &visited[50][51], 0);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> landmap[i][j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (landmap[i][j] && !visited[i][j]) {
					dfs(i, j, w, h);
					num++;
				}

			}
		}
		cout << num << '\n';
		cin >> w >> h;
	}

	return 0;
}
