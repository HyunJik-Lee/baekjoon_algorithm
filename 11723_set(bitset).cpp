#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
bitset<21> res;
int M;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> M;
	for (int i = 0; i < M; i++) {
		string t;
		int a = 0;
		cin >> t;
		if (t == "add") {
			cin >> a;
			res.set(a, true);
		}
		else if (t == "remove") {
			cin >> a;
			res.set(a, false);
		}
		else if (t == "check") {
			cin >> a;
			cout << res.test(a) << '\n';
		}
		else if (t == "toggle") {
			cin >> a;
			res.flip(a);
		}
		else if (t == "all") {
			res.set();
		}
		else if (t == "empty") {
			res.reset();
		}
	}
}
