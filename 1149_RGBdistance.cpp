#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
int memo[1001][3];
int input[1001][3];
int N;

int dp(int i, int rgb) { //i번째 집을 rgb로 색칠했을 때 i-1까지 칠하는 최소비용
	int& ret = memo[i][rgb];
	if (ret != 0)
		return ret;

	memo[i][0] = min(dp(i - 1, 1), dp(i - 1, 2)) + input[i][0];
	memo[i][1] = min(dp(i - 1, 0), dp(i - 1, 2)) + input[i][1];
	memo[i][2] = min(dp(i - 1, 0), dp(i - 1, 1)) + input[i][2];

	return ret;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++)
			cin >> input[i][j];
	}
	memo[0][0] = input[0][0];
	memo[0][1] = input[0][1];
	memo[0][2] = input[0][2];

	cout << min({ dp(N - 1, 0), dp(N - 1, 1), dp(N - 1, 2) }) << '\n';
}
