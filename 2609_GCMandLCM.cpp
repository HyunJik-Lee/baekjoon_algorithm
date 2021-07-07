#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int getgcd(int n, int m) {
	int res = 99;
	while (res) {
		res = n % m;
		n = m;
		m = res;
	}
	return n;
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int a, b;
	cin >> a >> b;
	int gcd = getgcd(a, b);
	cout << gcd << '\n' << a * b / gcd;
}
