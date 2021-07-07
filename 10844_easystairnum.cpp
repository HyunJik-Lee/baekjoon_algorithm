#include <bits/stdc++.h>
constexpr auto MOD = 1000000000;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll memo[101][11];
int N;

ll dp(int n, int x) {
	if (n == 1) return memo[n][x];
	if (memo[n][x]) return memo[n][x];
	ll& ret = memo[n][x];
	if (x == 0)
		return ret = dp(n - 1, x + 1) % MOD;
	else if (x == 9)
		return ret = dp(n - 1, x - 1) % MOD;
	else
		return ret = (dp(n - 1, x - 1) + dp(n - 1, x + 1)) % MOD;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	memo[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		memo[1][i] = 1;
	}
	for (int i = 0; i < 10; i++) {
		dp(N, i);
	}

	ll res = 0;
	for (int i = 0; i < 10; i++) {
		res = (res + memo[N][i]) % MOD;
	}
	cout << res;
}
