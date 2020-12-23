#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
int A, B, C;

ld bc(ld l, ld r) {
	int cnt = 1000;
	while (cnt--) {
		ld c = (l + r) / 2;
		if (A * c + B * sinl(c) < C)
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
	cin >> A >> B >> C;
	cout.precision(6);
	cout << fixed;
	cout << bc(0, 100002);
}
