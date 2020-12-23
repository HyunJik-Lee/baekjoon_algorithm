#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
vector<int> G[499500];
int visited[1001];
int N, M;

void dfs(int n) {
	int cnt = 0;
	for (int x : G[n]) {
		if (visited[x]) continue;
		visited[x] = 1;
		cnt++;
		dfs(x);
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N >> M;
	int a, b;
	int c = 0;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			dfs(i);
			c++;
		}
	}
	cout << c;

}
