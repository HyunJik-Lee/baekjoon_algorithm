#include <iostream>
#include <algorithm>

using namespace std;
int memo[4][301];
int input[301];
int num;

int f(int n, int cnt) {
	int u1, u2;

	if (cnt == 3)
		return -5000000;
	if (n == num)
		return input[n];
	if (n == num + 1)
		return -5000000;
	int& ret = memo[cnt][n];
	if (ret != 0)
		return ret;

	u1 = f(n + 1, cnt + 1) + input[n];
	u2 = f(n + 2, 1) + input[n];
	ret = max(u1, u2);
	return ret;
}
int main() {
	cin >> num;
	for (int i = 1; i <= num; i++) {
		cin >> input[i];
	}
	cout << f(0, 0);
}

