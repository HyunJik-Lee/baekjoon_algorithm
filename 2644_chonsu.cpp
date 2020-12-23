#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
int N, M;
vector<int> G[102];
queue<int> bfs;
int visited[102];

//void bfs() {
//
//}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	fill(visited, visited + 102, -1);
	int start, end;
	cin >> N >> start >> end >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	bfs.push(start);
	visited[start] = 0;
	int cur;
	while (!bfs.empty()) {
		cur = bfs.front(); bfs.pop();
		for (int x : G[cur]) {
			if (visited[x] != -1) continue;
			bfs.push(x);
			visited[x] = visited[cur] + 1;
		}
	}
	cout << visited[end];
}
