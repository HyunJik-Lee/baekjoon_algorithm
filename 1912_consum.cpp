#include <iostream>
#include <algorithm>
using namespace std;

int memo[100001];
int input[100001];
long long n;

int f(int i) {
	if (i == n - 1) return input[n - 1];
	if (memo[i] != 0)
		return memo[i];
	memo[i] = max(input[i], input[i] + f(i + 1));
	return memo[i];
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	int max = f(n - 1);
	int t = 0;
	for (int i = 0; i < n - 1; i++) {
		t = f(i);
		if (max < t)
			max = t;
	}
	cout << max;
}
