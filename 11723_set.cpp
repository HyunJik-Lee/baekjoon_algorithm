#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
unsigned int num;
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
			num |= (1 << a);
		}
		else if (t == "remove") {
			cin >> a;
			num &= ~(1 << a);
		}
		else if (t == "check") {
			cin >> a;
			if ((num & (1 << a)))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (t == "toggle") {
			cin >> a;
			num ^= (1 << a);
		}
		else if (t == "all") {
			num |= (1 << 21) - 1;
		}
		else if (t == "empty") {
			num = 0;
		}
	}
}
