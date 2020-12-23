#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
queue<pair<pii, char>>  bfs;
int Svisited[52][52];
int Wvisited[52][52];
char input[52][52];
int R, C;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int Si, Sj, Di, Dj;


int check(int x, int y) {
	return (x >= 0) && (y >= 0) && (x < R) && (y < C);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	fill(&Svisited[0][0], &Svisited[51][52], 3000);
	fill(&Wvisited[0][0], &Wvisited[51][52], 3000);
	string in;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> in;
		for (int j = 0; j < in.size(); j++) {
			input[i][j] = in[j];
			if (in[j] == 'S') {
				Si = i; Sj = j;
			}
			else if (in[j] == 'D') {
				Di = i; Dj = j;
			}
			else if (in[j] == '*') {
				bfs.push({ { i,j }, '*' });
				Wvisited[i][j] = 0;
			}
		}
	}
	bfs.push({ { Si, Sj },'S' });
	Svisited[Si][Sj] = 0;
	while (!bfs.empty()) {
		pair<pii, char> p = bfs.front(); bfs.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.first.first + dx[i];
			int ny = p.first.second + dy[i];
			if (p.second == '*') {
				if (check(nx, ny) && input[nx][ny] == '.' && Wvisited[nx][ny] == 3000) {
					Wvisited[nx][ny] = Wvisited[p.first.first][p.first.second] + 1;
					bfs.push({ { nx,ny }, p.second });
				}
			}
			else if (p.second == 'S') {
				if ((check(nx, ny)) && (Wvisited[nx][ny] > Svisited[p.first.first][p.first.second] + 1) && (input[nx][ny] == '.' || input[nx][ny] == 'D') && (Svisited[nx][ny] == 3000)) {
					Svisited[nx][ny] = Svisited[p.first.first][p.first.second] + 1;
					bfs.push({ { nx,ny }, p.second });
				}
			}
		}
	}
	int dist = Svisited[Di][Dj];

	if (dist == 3000) {
		cout << "KAKTUS";
	}
	else {
		cout << dist;
	}
}
