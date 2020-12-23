#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char star[2188][2188];

void starfunc(int num, int x, int y) {
	if (num == 1) {
		star[x][y] = '*';
		return;
	}
	int v = num / 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
				continue;
			else starfunc(v, x + (v * i), y + (v * j));
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		memset(star[i], ' ', sizeof(char) * N);
	}
	starfunc(N, 0, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << star[i][j];
		}
		cout << '\n';
	}
}
