#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
int N, M, V;

vector<int> v[1001];
bool d_visited[1001];
bool b_visited[1001];
queue<int> bfs;

void dfs(int id) {
	cout << id << ' ';
	for (int x : v[id]) {
		if (d_visited[x]) continue;
		d_visited[x] = 1;
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

	cin >> N >> M >> V;

	int a = 0, b = 0;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}
	d_visited[V] = true;
	dfs(V);
	cout << '\n';
	bfs.push(V);
	b_visited[V] = true;
	int cur; // 현재 방문하는 번호
	while (!bfs.empty()) {
		cur = bfs.front(); bfs.pop();
		cout << cur << ' ';
		for (int x : v[cur]) {
			if (b_visited[x]) continue;
			bfs.push(x);
			b_visited[x] = true;
		}
	}

}
