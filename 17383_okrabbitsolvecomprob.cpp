#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
int N;
int input[100001];

bool check(ll x)
{
	int s = 1, i;
	for (i = 0; i < N; i++)
		s += (input[i] - 1) / x - 1;

	return s <= 0;
}
ll bc(ll l, ll r) {
	while (l + 1 < r) {
		ll c = l + r >> 1;
		if (check(c))
			r = c;
		else l = c;
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
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	cout << bc(0, 1e10);
}
