#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int dice[7];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int a = 0;
	for (int i = 0; i < 3; i++) {
		cin >> a;
		dice[a]++;
	}
	int num = 0, big = 0, that = 0;
	for (int i = 1; i < 7; i++) {
		if (num < dice[i]) {
			num = dice[i];
			that = i;
		}
		if (dice[i] && big < i) big = i;
	}
	if (num == 3) cout << 10000 + that * 1000;
	else if (num == 2) cout << 1000 + that * 100;
	else cout << big * 100;
}
