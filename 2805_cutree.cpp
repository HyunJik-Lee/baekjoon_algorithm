#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
int N, M;
int input[1000001];

int check(int x) {
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		ll t = input[i] - x;
		if (t > 0)
			sum += t;
	}
	return sum >= M;
}

int abc(ll l, ll r, ll a) {
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
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	sort(input, input + N);
	cout << abc(0, input[N - 1] + 1, M);
}
