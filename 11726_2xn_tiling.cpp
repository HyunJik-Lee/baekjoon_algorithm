#include <bits/stdc++.h>
#define MOD 10007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;
ll memo[1001] = { 0,1,2 };

ll dp(int n) {
	if (n < 1) return 0;
	if (memo[n] != 0) return memo[n];
	memo[n] = ((dp(n - 1) % MOD) + (dp(n - 2) % MOD) % MOD);

	return memo[n] % MOD;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	cout << dp(N);
}
