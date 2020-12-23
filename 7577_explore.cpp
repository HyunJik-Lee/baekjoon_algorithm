#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> G[42];
ll dist[42];
int K, N;
int a, b, c;
bool negativeCycle = false;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	fill(dist, dist + 42, 3e18);
	cin >> K >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;

		G[a - 1].push_back({ b,c });
		G[b].push_back({ a - 1,-c });
	}
	for (int i = 1; i <= K; i++) {  // 0 <= ai - ai-1 <= 1
		G[i - 1].push_back({ i,1 });
		G[i].push_back({ i - 1,0 });
	}
	dist[0] = 0;
	for (int i = 0; i <= K; i++) {
		for (int j = 0; j <= K; j++) {
			for (pii p : G[j]) {
				if (dist[p.first] > dist[j] + p.second) {
					dist[p.first] = dist[j] + p.second;
					if (i == K)
						negativeCycle = true;
				}

			}
		}
	}

	if (negativeCycle) {
		cout << "NONE";
	}
	else {
		for (int i = 1; i <= K; i++) {
			if (!(dist[i] - dist[i - 1]))
				cout << '-';
			else cout << '#';
		}

	}

}
