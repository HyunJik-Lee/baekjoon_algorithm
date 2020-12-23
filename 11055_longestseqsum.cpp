#include <iostream>
#include <algorithm>

using namespace std;
int input[1001];
int memo[1001];
int N;

int dp(int a) {
	int mx = 0;
	if (a == N - 1)
		return input[a];
	if (memo[a] != 0)
		return memo[a];

	for (int i = a + 1; i < N; i++) {
		if (input[a] < input[i]) {
			mx = max(mx, dp(i));
		}
	}
	memo[a] = mx + input[a];

	return memo[a];

}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	int mx = -99999999;
	for (int i = 0; i < N; i++) {
		mx = max(mx, dp(i));
	}
	cout << mx;


}
