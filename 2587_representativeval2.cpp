#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n[5];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int a = 0;
	for (int i = 0; i < 5; i++) {
		cin >> n[i];
		a += n[i];
	}
	sort(n, n + 5);
	cout << a / 5 << '\n' << n[2];
}
