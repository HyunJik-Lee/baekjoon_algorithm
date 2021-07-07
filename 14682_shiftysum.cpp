#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N, K;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N >> K;
	int res = 0;
	++K;
	while (K--) {
		res += N;
		N *= 10;
	}
	cout << res;
}
