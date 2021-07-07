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
	int N = 0;
	int y = 0, m = 0, a = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		y += 10 * (a / 30 + 1);
		m += 15 * (a / 60 + 1);
	}
	if (y > m)
		cout << "M " << m;
	else if (y < m)
		cout << "Y " << y;
	else
		cout << "Y M " << y;
}
