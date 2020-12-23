#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll dist[252][252];

int N, M;
int U, V, B;
int K, S, E;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	fill(&dist[0][0], &dist[251][252], 3e18);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		dist[i][i] = 0;
	}
	for (int i = 0; i < M; i++) {
		cin >> U >> V >> B;
		if (B == 0) {
			dist[U][V] = 0;
			dist[V][U] = 1;
		}
		else {
			dist[U][V] = 0;
			dist[V][U] = 0;
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> S >> E;
		cout << dist[S][E] << '\n';
	}
}
