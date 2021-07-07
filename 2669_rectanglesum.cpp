#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int rect[101][101];
int input[4][4];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> input[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int q = input[i][0]; q < input[i][2]; q++) {
			for (int w = input[i][1]; w < input[i][3]; w++) {
				rect[q][w] = 1;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (rect[i][j])
				sum++;
		}
	}
	cout << sum;
	return 0;
}
