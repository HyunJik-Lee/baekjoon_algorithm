#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
int N, M;
int input[100001];
int ori[100001];
ll check(ll x) {
	int cnt = 1;
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		if (input[i] > x) return true;
		else if (sum + input[i] > x) {
			sum = 0;
			i--;
			cnt++;
		}
		else sum += input[i];
	}
	return cnt > M;
}

ll bc(ll l, ll r) {
	while (l + 1 < r) {
		ll c = l + r >> 1;
		if (check(c))
			l = c;
		else r = c;
	}
	return r;
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
	cout << bc(0, 1e9 + 1);
}
