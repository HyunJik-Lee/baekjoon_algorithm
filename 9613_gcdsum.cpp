#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int T;
int C;
int input[101];

ll getgcd(int n, int m) {
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
	cin >> T;
	while (T--) {
		ll sum = 0;
		cin >> C;
		for (int i = 0; i < C; i++) {
			cin >> input[i];
		}
		for (int i = 0; i < C; i++) {
			for (int j = i + 1; j < C; j++) {
				sum += getgcd(input[i], input[j]);
			}
		}
		cout << sum << '\n';
	}
}
