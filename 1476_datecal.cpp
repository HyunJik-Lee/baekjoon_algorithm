#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int E, S, M;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> E >> S >> M;
	int year = 0;
	while (true) {
		int x = year % 15, y = year % 28, z = year % 19;
		if (x == E - 1 && y == S - 1 && z == M - 1) break;
		++year;
	}
	cout << year + 1;
}
