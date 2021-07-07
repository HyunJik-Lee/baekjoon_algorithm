#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int input[4];

int clock(int x) {
	int min = x;
	for (int i = 0; i < 3; i++) {
		x = (x % 10) * 1000 + (x / 10);
		if (min > x) min = x;
	}
	return min;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	for (int i = 0; i < 4; i++) {
		cin >> input[i];
	}
	int t = input[0] * 1000 + input[1] * 100 + input[2] * 10 + input[3];
	int clockn = clock(t);
	int nth = 0;
	for (int i = 1111; i <= clockn; i++) {
		if (clock(i) == i) nth++;
	}
	cout << nth;
}
