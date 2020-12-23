#include <iostream>
#include <algorithm>

using namespace std;

int memo[11] = { 0, 1, 2, 4 };

int dp(int n) {

	if (n < 0) return 0;
	if (n <= 3) return memo[n];
	if (memo[n] != 0) return memo[n];
	int ret = dp(n - 1) + dp(n - 2) + dp(n - 3);
	return ret;
}

int main() {
	int N, T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << dp(N) << endl;
	}

}
