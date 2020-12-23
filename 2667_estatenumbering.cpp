#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
int input[27][27];
int group[27][27];
int N;
int dx[4] = { -1, 1, 0, 0 }; //상하좌우
int dy[4] = { 0, 0, -1, 1 };
int num = 0;
bool isBound(int x, int y) {
	return (x >= 0) && (y >= 0) && (x < N) && (y < N);
}

void dfs(int x, int y) {
	if (input[x][y] == 0) return;
	input[x][y] = 0;
	group[x][y] = num;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (isBound(next_x, next_y) && input[next_x][next_y])
			dfs(next_x, next_y);
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	string in;
	vector<int> v;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> in;
		for (int j = 0; j < in.size(); j++) {
			input[i][j] = in[j] - '0';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (input[i][j]) {
				num++;
				dfs(i, j);
			}
		}
	}
	for (int i = 0; i < num; i++) {
		v.push_back(0);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (group[i][j]) {
				v[group[i][j] - 1]++;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << num << '\n';
	for (int x : v)
		cout << x << '\n';
	return 0;
}
