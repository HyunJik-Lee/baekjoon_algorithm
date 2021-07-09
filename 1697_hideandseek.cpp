#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int dist[200001];
int N, K;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	queue<int> q;
	fill(dist, dist + 200001, -1);
	cin >> N >> K;
	dist[N] = 0;
	q.push(N);
	while (dist[K] == -1) {
		int cur = q.front(); q.pop();
		for (int nxt : {cur - 1, cur + 1, 2 * cur}) {
			if (nxt < 0 || nxt > 100000) continue;
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}
	cout << dist[K];

}
