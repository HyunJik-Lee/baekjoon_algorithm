#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
int input[100002];

int search(int l, int r, int a) {
	while (l + 1 < r) {
		int c = l + r >> 1;
		if (input[c] <= a)
			l = c;
		else
			r = c;
	}
	return input[l] == a;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int N = 0, M = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	sort(input, input + N);

	cin >> M;
	int a = 0;
	for (int i = 0; i < M; i++) {
		cin >> a;
		if (search(0, N, a))
			cout << 1 << '\n';
		else cout << 0 << '\n';
	}

}
