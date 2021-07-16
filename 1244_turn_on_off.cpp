#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int swit[101];
int N, M;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> swit[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			for (int j = b - 1; j < N; j += b)
				swit[j] ^= 1;
		}
		else {
			int c = 0;
			for (int j = 1; j < N / 2; j++) {
				if (b - j - 1 < 0 || b + j - 1 >= N) continue;
				if (swit[b - j - 1] == swit[b + j - 1]) c++;
				else break;
			}
			for (int j = b - c - 1; j < b + c; j++) {
				swit[j] ^= 1;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cout << swit[i] << ' ';
		cnt++;
		if (cnt == 20) {
			cnt = 0;
			cout << '\n';
		}
	}
}
