#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
int cnt;
bool board[17][17];

bool check(int id, int i) {
	//3방향 체크
	//위
	for (int q = 1; id - q > 0; q++) {
		if (board[id - q][i])
			return false;
	}
	//왼쪽위
	for (int q = 1; id - q > 0 && i - q > 0; q++) {
		if (board[id - q][i - q])
			return false;
	}
	//오른쪽위
	for (int q = 1; id - q > 0 && i + q <= N; q++) {
		if (board[id - q][i + q])
			return false;
	}
	return true;
}

void dfs(int id) {
	if (id == N + 1) {
		cnt++;
		return;
	}
	for (int j = 1; j <= N; j++) {
		board[id][j] = true;
		if (check(id, j))
			dfs(id + 1);
		board[id][j] = false;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	dfs(1);
	cout << cnt;
}
