#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
int input[501][501];
int dp[501][501];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> input[i][j];
		}
	}
	dp[0][0] = input[0][0];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + input[i][j];
		}
	}
	int mx = -987526232;
	for (int i = 0; i <= N; i++) {
		if (dp[N - 1][i] > mx)
			mx = dp[N - 1][i];
	}
	cout << mx;
	return 0;

}
