#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char star[3073][6147];

void starfunc(int n, int x, int y) {
	if (n == 3) {
		//꼭지점
		star[x][y] = '*';
		//양옆
		star[x + 1][y - 1] = '*';
		star[x + 1][y + 1] = '*';
		//밑변
		star[x + 2][y - 2] = '*';
		star[x + 2][y - 1] = '*';
		star[x + 2][y] = '*';
		star[x + 2][y + 1] = '*';
		star[x + 2][y + 2] = '*';
		return;
	}
	starfunc(n / 2, x, y);
	starfunc(n / 2, x + n / 2, y - (n / 2));
	starfunc(n / 2, x + n / 2, y + (n / 2));
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	//#ifdef LOCAL
	//	freopen("input.txt", "r", stdin);
	//#endif
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			star[i][j] = ' ';
		}
	}
	starfunc(N, 0, N - 1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			cout << star[i][j];
		}
		if (i != N - 1) cout << '\n';
	}
}
