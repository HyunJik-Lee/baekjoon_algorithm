#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<pii> G[501];
ll dist[501];
bool negativeCycle;

int TC, N, M, W;
int S, E, T;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> TC;
	while (TC--) {
		cin >> N >> M >> W;
		fill(dist, dist + 501, 9e18);
		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			G[S].push_back({ E,T });
			G[E].push_back({ S,T });

		}
		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			G[S].push_back({ E,-T });
		}
		dist[1] = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (pii nxt : G[j]) {
					if (dist[nxt.first] > dist[j] + nxt.second) {
						dist[nxt.first] = dist[j] + nxt.second;
						if (i == N)
							negativeCycle = true;
					}
				}
			}
		}

		for (int i = 0; i <= N; i++) {
			G[i].clear();
		}

		if (negativeCycle) {
			cout << "YES\n";
			negativeCycle = false;
		}
		else cout << "NO\n";

	}
}
