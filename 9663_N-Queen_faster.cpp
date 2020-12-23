#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
int cnt;
int r[17], c[17], lc[34], rc[34]; // 가로 세로 왼쪽대각선 오른쪽대각선

bool check(int id, int i) {
	if (r[id] > 1 || c[i] > 1 || lc[id - i + N] > 1 || rc[id + i] > 1)
		return false;
	else return true;
}

void place(int id, int i) {
	r[id]++;
	c[i]++;
	lc[id - i + N]++;
	rc[id + i]++;
}

void unplace(int id, int i) {
	r[id]--;
	c[i]--;
	lc[id - i + N]--;
	rc[id + i]--;
}

void dfs(int id) {
	if (id == N + 1) {
		cnt++;
		return;
	}
	for (int j = 1; j <= N; j++) {
		place(id, j);
		if (check(id, j))
			dfs(id + 1);
		unplace(id, j);
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	//#ifdef LOCAL
	//	freopen("input.txt", "r", stdin);
	//#endif
	cin >> N;
	dfs(1);
	cout << cnt;
}
