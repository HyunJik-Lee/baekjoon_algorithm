#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
vector<int> G[502];
int visited[502];
int N;
int M;
int cnt = 0;
void dfs(int id) {
	if (id == 1) {
		for (int x : G[id]) {
			visited[x] = 1;
			dfs(x);
		}
	}
	for (int x : G[id]) {
		if (visited[x]) continue;
		visited[x] = 1;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	visited[1] = 1;
	dfs(1);
	for (int i = 2; i <= N; i++) {
		if (visited[i]) cnt++;
	}

	cout << cnt;
}
