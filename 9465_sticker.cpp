#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;


int input[2][100001];
int memo[2][100001];
int T, N;
int dp(int i, int j) { //i , j 까지 왔을때 최대 점수
	if (j < 0)
		return 0;
	int c1, c2;
	int& ret = memo[i][j];
	if (ret != -1)
		return ret;
	if (i == 0)
	{
		ret = input[i][j] + max(dp(i + 1, j - 1), dp(i + 1, j - 2));
	}
	else if (i == 1) {
		ret = input[i][j] + max(dp(i - 1, j - 1), dp(i - 1, j - 2));
	}
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> T;
	for (int t = 0; t < T; t++) {
		for (int k = 0; k < 2; k++) {
			memset(input[k], -1, sizeof(input[k]));
			memset(memo[k], -1, sizeof(memo[k]));
		}
		cin >> N;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> input[i][j];
			}
		}
		memo[0][0] = input[0][0];
		memo[1][0] = input[1][0];
		memo[0][1] = input[0][1] + memo[1][0];
		memo[1][1] = input[1][1] + memo[0][0];

		cout << max(dp(0, N - 1), dp(1, N - 1)) << '\n';
	}
}
