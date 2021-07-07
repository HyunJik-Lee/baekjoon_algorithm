#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll input[100001];
int N;
ll dc(int a, int b) {
	if (a == b) return input[a] * input[a];
	int mid = a + b >> 1;
	ll ret = 0;
	ret = max(ret, dc(a, mid));
	ret = max(ret, dc(mid + 1, b));
	int l = mid, r = mid + 1;
	ll height = min(input[l], input[r]);
	ll sum = input[l] + input[r];
	while (a != l || b != r) {
		if (l == a) { r++; sum += input[r]; }
		else if (r == b) {
			l--; sum += input[l];
		}
		else if (input[l - 1] > input[r + 1]) {
			l--; sum += input[l];
		}
		else {
			r++; sum += input[r];
		}
		height = min({ height, input[l], input[r] });
		ret = max({ ret, 1LL * sum * height });
	}
	return ret;
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
		cin >> input[i];
	}
	cout << dc(0, N - 1) << '\n';
}
