#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N, k, cnt;
int p[7][2];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N >> k;
	int a = 0, b = 0;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		p[b][a]++;
	}
	for (int i = 1; i < 7; i++) {
		for (int j = 0; j < 2; j++) {
			cnt += p[i][j] / k + (p[i][j] % k != 0);
		}
	}
	cout << cnt;
}
