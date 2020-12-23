#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int input[1000002];
bool selected[1000002];
int N, S;
int cnt = 0;
bool check;
void dfs(int id) {

	if (id == N + 1) {
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			if (selected[i]) {
				sum += input[i];
				check = true;
			}
		}
		if (sum == S && check) {

			cnt++;
		}
		check = false;
		return;
	}

	selected[id] = true;
	dfs(id + 1);
	selected[id] = false;
	dfs(id + 1);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N >> S;
	for (int i = 1; i <= N; i++) {
		cin >> input[i];
	}
	dfs(1);
	cout << cnt;
}
