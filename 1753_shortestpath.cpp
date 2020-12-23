#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<pii> G[20002];
//G[a].push_back( {b,c} ) a->b로 가는 c 가중치인 간선
priority_queue<pii> pq;
int dist[20002];
bool finished[20002];
int V, E;
int start;
int a, b, c;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> V >> E >> start;
	fill(dist, dist + V + 1, 1e9);
	dist[start] = 0;
	pq.push({ 0,start });
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		G[a].push_back({ b,c });
	}

	while (!pq.empty()) {
		int cur = pq.top().second; pq.pop();
		if (finished[cur]) continue;
		for (pii x : G[cur]) {
			int nxt = x.first, w = x.second;
			if (dist[nxt] > dist[cur] + w) {
				dist[nxt] = dist[cur] + w;
				pq.push({ -dist[nxt], nxt });
			}
		}
		finished[cur] = 1;
	}

	for (int i = 1; i <= V; i++) {
		if (i == start)
			cout << 0 << '\n';
		else if (dist[i] == 1e9)
			cout << "INF\n";
		else cout << dist[i] << '\n';
	}
}
