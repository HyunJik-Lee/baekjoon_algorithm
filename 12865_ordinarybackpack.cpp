#include <bits/stdc++.h>
#include <list>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, K;
int weight[102];
int value[102];
int memo[102][100002];

int dp(int i, int w) {
	if (i == 0 && w == 0)
		return 0;
	if (i > N)
		return 0;
	if (w < 0)
		return -999999999;
	if (memo[i][w] != 0)
		return memo[i][w];

	memo[i][w] = max(value[i] + dp(i + 1, w - weight[i]), dp(i + 1, w));

	return memo[i][w];

}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N >> K;
	int w, v;
	for (int i = 0; i < N; i++) {
		cin >> w >> v;
		weight[i] = w;
		value[i] = v;
	}

	cout << dp(0, K);
}
