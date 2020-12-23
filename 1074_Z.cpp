#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
int N, R, C;

int dc(int n, int r, int c) {
	int cnt = 0;
	if (n == 1) {
		if (r == 0 && c == 0)
			return 0;
		else if (r == 0 && c == 1)
			return 1;
		else if (r == 1 && c == 0)
			return 2;
		else return 3;
	}
	int t = ((1 << n - 1));
	//1사분면
	if (r <= ((1 << n - 1) - 1) && c <= ((1 << n - 1) - 1)) {
		return dc(n - 1, r, c);
	}
	//2사분면
	else if (r <= ((1 << n - 1) - 1) && c >= ((1 << n - 1) - 1)) {
		cnt = t * t + dc(n - 1, r, (c - t));
		return cnt;
	}
	//3사분면
	else if (r >= ((1 << n - 1) - 1) && c <= ((1 << n - 1) - 1)) {
		cnt = 2 * t * t + dc(n - 1, (r - t), c);
		return cnt;
	}
	//4사분면
	else if (r >= ((1 << n - 1) - 1) && c >= ((1 << n - 1) - 1)) {
		cnt = 3 * t * t + dc(n - 1, (r - t), (c - t));
		return cnt;
	}

}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N >> R >> C;
	cout << dc(N, R, C) << '\n';
}
