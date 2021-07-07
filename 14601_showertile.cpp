#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int tile[257][257];
int K, X, Y;
int n;
int cnt = 0;
bool check(int x, int y, int siz) {
	for (int i = x; i < x + siz; i++) {
		for (int j = y; j < y + siz; j++) {
			if (tile[i][j] != 0)
				return false;
		}
	}
	return true;
}
void tiling(int x, int y, int siz) {
	++cnt;
	if (check(x, y, siz >> 1))
		tile[x + (siz >> 1) - 1][y + (siz >> 1) - 1] = cnt;
	if (check(x, y + (siz >> 1), siz >> 1))
		tile[x + (siz >> 1) - 1][y + (siz >> 1)] = cnt;
	if (check(x + (siz >> 1), y, siz >> 1))
		tile[x + (siz >> 1)][y + (siz >> 1) - 1] = cnt;
	if (check(x + (siz >> 1), y + (siz >> 1), siz >> 1))
		tile[x + (siz >> 1)][y + (siz >> 1)] = cnt;
	if (siz == 2)
		return;

	tiling(x, y, siz >> 1);
	tiling(x + (siz >> 1), y, siz >> 1);
	tiling(x, y + (siz >> 1), siz >> 1);
	tiling(x + (siz >> 1), y + (siz >> 1), siz >> 1);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> K >> X >> Y;
	tile[Y - 1][X - 1] = -1;
	tiling(0, 0, 1 << K);
	for (int i = (1 << K) - 1; i >= 0; i--) {
		for (int j = 0; j < 1 << K; j++)
			cout << tile[i][j] << ((j == (1 << K) - 1) ? '\n' : ' ');
	}
}
