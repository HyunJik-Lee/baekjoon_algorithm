#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int M, N;
int input[501][501];
ll memo[501][501];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int dp(int i, int j) {
	ll& ret = memo[i][j];
	if (ret != -1) return ret;
	if ((i < 0) || (j < 0) && (i >= M) && (j >= N)) return 0;
	if (i == 0 && j == 0) return 1;

	ret = 0;
	for (int a = 0; a < 4; a++) {
		int nx = i + dx[a];
		int ny = j + dy[a];
		if (input[nx][ny] > input[i][j])
			ret += dp(nx, ny);
	}
	return ret;

}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> M >> N;
	fill(&memo[0][0], &memo[500][501], -1);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input[i][j];
		}
	}

	cout << dp(M - 1, N - 1);

}
