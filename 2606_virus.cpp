#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int N, M;
vector<int> G[4951];
int visited[101];
int cnt = 0;
void dfs(int n) {
	for (int x : G[n]) {
		if (visited[x]) continue;
		visited[x] = 1;
		cnt++;
		dfs(x);
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
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	visited[1] = 1;
	dfs(1);
	cout << cnt;
}
