#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = N - i; j > 0; j--) cout << ' ';
		for (int j = 0; j < 2 * i - 1; j++) cout << '*';
		cout << '\n';
	}

}
