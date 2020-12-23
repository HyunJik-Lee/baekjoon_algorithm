#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N, M;
int a, b, c;
vector<pii> G[502];
ll dist[502];
bool nagativeCycle = false;
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
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (pii nxt : G[j]) {
				if (dist[nxt.first] > dist[j] + nxt.second && dist[j] != 9e18) {
					dist[nxt.first] = dist[j] + nxt.second;
					if (i == N)
						nagativeCycle = true;
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
