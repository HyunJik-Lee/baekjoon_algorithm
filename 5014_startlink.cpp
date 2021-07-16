#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int F, S, G, U, D;
int dist[1000001];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	fill(dist, dist + 1000001, -1);
	cin >> F >> S >> G >> U >> D;
	queue<int> q;
	dist[S] = 0;
	q.push(S);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int c : {U, -D}) {
			int nxt = cur + c;
			if (nxt > F || nxt <= 0) continue;
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}
	if (dist[G] == -1) cout << "use the stairs";
	else cout << dist[G];
}
