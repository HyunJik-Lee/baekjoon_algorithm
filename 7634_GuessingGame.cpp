
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> G[1002];
queue<int> q;
int N, M, Q;
int i, j, c;
bool nagativeCycle = false;
int inq[1002];
int cnt[1002];
ll dist[1002];
char eq[2];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N >> M >> Q;
	while (N && M && Q) {

		fill(dist, dist + 1002, 3e18);

		for (int a = 0; a < Q; a++) {
			cin >> i >> j >> eq >> c;
			if (eq[0] == '<') {
				G[j + N].push_back({ i,c });
			}
			else {
				G[i].push_back({ j + N, -c });
			}
		}
		dist[1] = 0;
		for (int i = 1; i <= N + M; i++) {
			for (int j = 1; j <= N + M; j++) {
				for (pii nxt : G[j]) {
					if (dist[nxt.first] > dist[j] + nxt.second) {
						dist[nxt.first] = dist[j] + nxt.second;
						if (i == N + M)
							nagativeCycle = true;
					}
				}
			}
		}

		if (nagativeCycle)
			cout << "Impossible" << '\n';
		else cout << "Possible" << '\n';
		cin >> N >> M >> Q;
		nagativeCycle = false;
		for (int i = 1; i <= M + N; i++) {
			G[i].clear();
		}
	}

}
