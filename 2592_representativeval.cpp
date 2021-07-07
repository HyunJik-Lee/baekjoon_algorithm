#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n[100];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int a = 0, s = 0;
	for (int i = 0; i < 10; i++) {
		cin >> a;
		n[a / 10]++;
		s += a;
	}
	int t = 1, mx = 0;
	for (int i = 1; i < 100; i++) {
		if (mx < n[i]) {
			mx = n[i];
			t = i;
		}
	}
	cout << s / 10 << '\n' << t * 10;
}
