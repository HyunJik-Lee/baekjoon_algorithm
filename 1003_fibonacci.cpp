#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
int zero = 0, one = 0;
int N;
int memo[41];
int fibonacci(int n) {
	if (n == 0) {
		return memo[0] = 0;
	}
	else if (n == 1) {
		return memo[1] = 1;
	}
	if (memo[n] != 0) return memo[n];

	memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
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
	for (int i = 0; i < N; i++) {
		zero = 0, one = 0;
		int in = 0;
		cin >> in;
		fibonacci(in);
		if (in == 0) cout << 1 << ' ' << 0 << '\n';
		else if (in == 1) cout << 0 << ' ' << 1 << '\n';
		else cout << memo[in - 1] << ' ' << memo[in] << '\n';
	}
}
