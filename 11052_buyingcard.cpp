#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll memo[1001];
ll input[1001];
int N;

ll dp(int n) {
	if (n < 1) return 0;
	if (n == 1) return input[1];
	if (memo[n]) return memo[n];
	ll& res = memo[n];
	for (int i = 1; i <= n; i++) {
		res = max(res, dp(n - i) + input[i]);
	}
	return memo[n] = res;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> input[i];
	}
	cout << dp(N);
}
