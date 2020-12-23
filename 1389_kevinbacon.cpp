#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> G[102];
ll dist[102][102];
int N, M;
int a, b;
vector<pii> result;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	fill(&dist[0][0], &dist[101][102], 3e18);
	for (int i = 1; i <= 101; i++) {
		dist[i][i] = 0;
	}
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		int temp = 0;
		for (int j = 1; j <= N; j++) {
			temp += dist[i][j];
		}
		result.push_back({ temp,i });
	}
	sort(result.begin(), result.end());
	cout << result[0].second;
}
