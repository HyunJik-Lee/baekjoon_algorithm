#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> G[1002];
priority_queue<pii> pq;
int dist[1002];
bool finished[1002];
int s, e;
int N, M;
int a, b, c;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		G[a].push_back({ b,c });
	}
	cin >> s >> e;
	fill(dist, dist + N + 1, 1e9);
	dist[s] = 0;
	pq.push({ 0,s });
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

	cout << dist[e];
}
