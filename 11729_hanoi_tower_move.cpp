#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;

void move(int a, int b, int n) {
	if (n == 1) {
		cout << a << ' ' << b << '\n';
	}
	else {
		move(a, 6 - a - b, n - 1);
		cout << a << ' ' << b << '\n';
		move(6 - a - b, b, n - 1);
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	cout << (1 << N) - 1 << '\n';
	move(1, 3, N);
}
