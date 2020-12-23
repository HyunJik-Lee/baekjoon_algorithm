#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int input[100001];

ll dc(int a, int b) {
	if (a == b) return input[a];
	int mid = (a + b) / 2;
	ll ret = 0;
	ret = max(ret, dc(a, mid));
	ret = max(ret, dc(mid + 1, b));

	int l = mid, r = mid;
	int height = min(input[l], input[r]);
	while (a != l || b != r) {
		if (l == a) r++;
		else if (r == b) l--;
		else if (input[l - 1] > input[r + 1]) l--;
		else r++;
		height = min({ height, input[l], input[r] });
		ret = max({ ret, 1LL * ((ll)r - l + 1) * height });
	}
	return ret;

}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> input[i];
	}
	cout << dc(0, N) << endl;
}
