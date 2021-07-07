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
	string a, b;
	cin >> a >> b;
	map<char, int> m1, m2;
	for (char c1 : a) {
		if (m1[c1]) m1[c1]++;
		else m1[c1] = 1;
	}
	for (char c2 : b) {
		if (m2[c2]) m2[c2]++;
		else m2[c2] = 1;
	}

	int q = 0;

	for (auto i = 'a'; i <= 'z'; i++) {
		int a = m1[i]; int b = m2[i];
		if (a > b) {
			q += a - b;
		}
		else if (a < b) {
			q += b - a;
		}
		else q += 0;
	}
	cout << q;
}
