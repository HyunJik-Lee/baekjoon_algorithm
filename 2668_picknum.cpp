#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> G[101];
bool visited[101];
bool finish[101];
int N;
vector<int> ans;

void dfs(int id) {
	for (int x : G[id]) {
		if (visited[x] && finish[x]) {
			ans.push_back(x);
			continue;
		}
		if (visited[x]) continue;
		visited[x] = 1;
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
	fill(visited, visited + 100, 0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int t = 0;
		cin >> t;
		G[i].push_back(t);
	}
	for (int i = 1; i <= N; i++) {
		fill(visited, visited + 100, 0);
		visited[i] = 1;
		finish[i] = 1;
		dfs(i);
		visited[i] = 0;
		finish[i] = 0;
	}
	cout << ans.size() << '\n';
	for (int x : ans) {
		cout << x << '\n';
	}
}
