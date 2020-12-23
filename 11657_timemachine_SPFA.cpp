#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, M;
int a, b, c;
vector<pii> G[502];
ll dist[502];
queue<pii> q; //(거리, 정점) 정점만 넣어도됨
bool nagativeCycle = false;
int inq[502];
int cnt[502];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	fill(dist, dist + 502, 9e18);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		G[a].push_back({ b,c });
	}
	dist[1] = 0;
	inq[1] = true;
	cnt[1]++;
	q.push({ 0, 1 });

	while (!q.empty()) {
		int cur = q.front().second; q.pop();
		cnt[cur]++;
		inq[cur] = false;
		if (cnt[cur] == N) { nagativeCycle = true; break; }

		for (pii x : G[cur]) {
			int nxt = x.first, w = x.second;
			if (dist[nxt] > dist[cur] + w) {
				dist[nxt] = dist[cur] + w;
				if (!inq[nxt]) {
					q.push({ -dist[nxt], nxt });
					inq[nxt] = true;
				}

			}
		}
	}


	if (nagativeCycle)
		cout << -1;
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == 9e18)
				cout << -1 << '\n';
			else
				cout << dist[i] << '\n';
		}
	}
}
