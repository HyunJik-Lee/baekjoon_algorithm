#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int dist[100002];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	fill(dist, dist + 100002, -1);
	int n, k;
	cin >> n >> k;
	deque<int> dq;
	dist[n] = 0;
	dq.push_back(n);
	while (!dq.empty()) {
		int cur = dq.front(); dq.pop_front();
		if (2 * cur < 100002 && dist[2 * cur] == -1) {
			dist[2 * cur] = dist[cur];
			dq.push_front(2 * cur);
		}
		for (int nxt : {cur - 1, cur + 1}) {
			if (nxt < 0 || nxt >= 100002 || dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			dq.push_back(nxt);
		}
	}
	cout << dist[k];


}
