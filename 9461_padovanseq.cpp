#include <iostream>

using namespace std;

long long memo[101] = { 0,1,1,1,2,2, };
long long dp(int n) {
	if (n <= 5) return memo[n];
	if (memo[n] != 0) return memo[n];
	memo[n] = dp(n - 1) + dp(n - 5);
	return memo[n];
}

int main() {
	int T = 0;
	int N = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << dp(N) << endl;
	}

}
