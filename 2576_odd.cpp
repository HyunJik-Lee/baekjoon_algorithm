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
	int sum = 0, min = 101, a = 0;
	for (int i = 0; i < 7; i++) {
		cin >> a;
		if (a % 2) {
			sum += a;
			if (min > a) min = a;
		}
	}
	if (sum == 0) cout << -1;
	else {
		cout << sum << '\n' << min;
	}
}
