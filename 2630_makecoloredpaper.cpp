#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int paper[129][129];
int N;
int wcnt, bcnt;

bool checksquarecolor(int x, int y, int size) {
	int cur = paper[y][x];
	for (int i = y; i < size + y; i++) {
		for (int j = x; j < size + x; j++) {
			if (cur != paper[i][j])
				return false;
		}
	}
	return true;
}

void dc(int x, int y, int size) {
	if (size == 1) {
		if (paper[y][x] == 0)
			wcnt++;
		else bcnt++;
		return;
	}
	else if (checksquarecolor(x, y, size)) {
		if (paper[y][x] == 0)
			wcnt++;
		else bcnt++;
		return;
	}
	else {
		dc(x, y, size >> 1);
		dc(x + (size >> 1), y, size >> 1);
		dc(x, y + (size >> 1), size >> 1);
		dc(x + (size >> 1), y + (size >> 1), size >> 1);
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}
	dc(0, 0, N);
	cout << wcnt << '\n' << bcnt;
}
