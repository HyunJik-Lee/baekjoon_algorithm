#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int input[102][102][102];
int visited[102][102][102];
int M, N, H;
int dx[6] = { -1,1,0,0,0,0 }; //상하좌우
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };
queue <pair<int, pii>> bfs;

bool isBound(int x, int y, int z) {
	return (x >= 0) && (y >= 0) && (x < N) && (y < M) && (z >= 0) && (z < H);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	memset(visited, -1, sizeof(visited));
	cin >> M >> N >> H;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> input[k][i][j];
				if (input[k][i][j] == 1) {
					bfs.push({ k,{i,j} });
					visited[k][i][j] = 0;
				}
			}
		}
	}

	while (!bfs.empty()) {
		pair<int, pii> p = bfs.front(); bfs.pop();
		for (int i = 0; i < 6; i++) {
			int nx = p.second.first + dx[i];
			int ny = p.second.second + dy[i];
			int nz = p.first + dz[i];
			if (isBound(nx, ny, nz) && input[nz][nx][ny] == 0 && visited[nz][nx][ny] == -1) {
				visited[nz][nx][ny] = visited[p.first][p.second.first][p.second.second] + 1;
				bfs.push({ nz,{nx,ny} });
			}
		}
	}
	int day = 0;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				day = max(day, visited[k][i][j]);
			}
		}
	}
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[k][i][j] == -1 && input[k][i][j] == 0) {
					day = -1;
					break;
				}
			}
		}
	}

	cout << day << '\n';

}
