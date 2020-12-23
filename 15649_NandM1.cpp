#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, M;
bool selected[10];
vector<int> ans;

void dfs(int cnt) {

	if (cnt == M) {
		for (int x : ans)
		{
			cout << x << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (selected[i]) continue;
		ans.push_back(i);
		selected[i] = true;
		dfs(cnt + 1);
		ans.pop_back();
		selected[i] = false;
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
	dfs(0);
}
