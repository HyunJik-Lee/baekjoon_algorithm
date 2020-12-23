#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll N, M;
ll input[10003];

int check(int x) {
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		if (input[i] > x)
			sum += x;
		else
			sum += input[i];
	}
	return sum <= M;
}

ll bc(ll l, ll r) {
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
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	cin >> M;
	sort(input, input + N);
	cout << bc(0, input[N - 1] + 1);
}
