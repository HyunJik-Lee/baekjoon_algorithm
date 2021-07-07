#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
ll memo[101] = { 0,1,1,2 };

ll dp(int n) {
	if (n < 1) return 0;
	if (memo[n] != 0) return memo[n];
	memo[n] = dp(n - 1) + dp(n - 2);

	return memo[n];
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
