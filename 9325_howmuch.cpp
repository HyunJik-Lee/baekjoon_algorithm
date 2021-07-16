#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int T;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> T;
	while (T--) {
		int s = 0, n = 0, q = 0, p = 0, res = 0;
		cin >> s >> n;
		res += s;
		for (int i = 0; i < n; i++) {
			cin >> q >> p;
			res += q * p;
		}
		cout << res << '\n';
	}
}
