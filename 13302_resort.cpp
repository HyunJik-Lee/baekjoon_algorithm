#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
int input[101];
int memo[101][101];
int N, M;
int dp(int day, int coupon) {
	int c1 = 99999999, c2 = 99999999, c3 = 99999999;
	if (day >= N + 1)
		return 0;
	int& ret = memo[day][coupon];
	if (ret != 0)
		return ret;
	if (input[day] == 1)
		ret = dp(day + 1, coupon);
	else {
		c1 = dp(day + 1, coupon) + 10000;
		c2 = dp(day + 3, coupon + 1) + 25000;
		c3 = dp(day + 5, coupon + 2) + 37000;
		ret = min({ c1,c2,c3 });
		if (coupon >= 3)
			ret = min(ret, dp(day + 1, coupon - 3));
	}
	return ret;
}
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		input[a] = 1;
	}
	cout << dp(1, 0);
}
