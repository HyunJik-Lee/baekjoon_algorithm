#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll memo[4][10001];
int input[10001];
int N;
ll dp(int n, int c) {
	ll score = 0;

	if (c == 3) return -15000000;
	if (n == N) {
		if (c < 2)
			return input[n];
		else return 0;
	}

	if (n >= N + 1) return -15000000;
	if (memo[c][n]) return memo[c][n];

	memo[c][n] = max({ dp(n + 1, c + 1) + input[n], dp(n + 1, 0) });

	return memo[c][n];
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> input[i];
	}
	cout << dp(0, 0) << endl;
	return 0;
}
