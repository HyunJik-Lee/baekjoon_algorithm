#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int input[100002];
bool visited[100002];
bool finished[100002];
int T, N, cnt;

void dfs(int x) {
	visited[x] = true;
	int nxt = input[x];
	if (visited[nxt]) {
		if (!finished[nxt]) {
			for (int i = nxt; i != x; i = input[i]) cnt++;
			cnt++;
		}
	}
	else {
		dfs(nxt);
	}
	finished[x] = true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	cin >> T;
	while (T--) {
		fill(visited, visited + 100002, false);
		fill(finished, finished + 100002, false);
		cnt = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> input[i];
		}
		for (int i = 1; i <= N; i++) {
			if (visited[i]) continue;
			dfs(i);
		}
		cout << N - cnt << '\n';
	}
}
