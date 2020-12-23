#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;
ll memo[1001] = { 0, 1, 3, };

ll dp(int n) {
	if (n < 1) return 0;
	if (memo[n]) return memo[n];
	memo[n] = (dp(n - 1) % 10007 + (2 * dp(n - 2)) % 10007)%10007;
		
	return memo[n];
}

int main() {
	int N;
	cin >> N;
	cout << dp(N) << endl;
}