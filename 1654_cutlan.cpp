#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
ll input[10001];
int K, N;
int check(ll x) {
	ll sum = 0;
	for (int i = 0; i < K; i++) {
		ll t = input[i] / x;
		sum += t;
	}
	return sum >= N;
}

ll abc(ll l, ll r) {
	while (l + 1 < r) {
		ll c = l + r >> 1;
		if (check(c))
			l = c;
		else r = c;
	}
	return l;

}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> input[i];
	}
	sort(input, input + K);

	cout << abc(0, input[K - 1] + 1);
}
