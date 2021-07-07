#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ll a = 0, b = 0;
	cin >> a >> b;
	if (a == b) {
		cout << 0;
		return 0;
	}
	else {
		if (a < b) {
			cout << b - a - 1 << '\n';
			for (ll i = a + 1; i < b; i++)
				cout << i << ' ';
		}
		else {
			cout << a - b - 1 << '\n';
			for (ll i = b + 1; i < a; i++)
				cout << i << ' ';
		}
	}
}
