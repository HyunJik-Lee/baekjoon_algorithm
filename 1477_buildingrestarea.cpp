#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
int N, M, L;
int input[110];

int check(int x) {
	int cnt = 0;
	int t = 0;
	for (int i = 1; i <= N + 1; i++) {
		t = input[i] - input[i - 1];
		if (t > x) {
			cnt += (t - 1) / x;
		}
	}
	return cnt > M;
}

ll bc(ll l, ll r) {
	while (l + 1 < r) {
		ll c = l + r >> 1;
		if (check(c))
			l = c;
		else r = c;
	}
	return r;
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N >> M >> L;
	for (int i = 1; i <= N; i++) {
		cin >> input[i];
	}
	input[N + 1] = L;
	sort(input, input + N + 1);
	cout << bc(0, L);

}
