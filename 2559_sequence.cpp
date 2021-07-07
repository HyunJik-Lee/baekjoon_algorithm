#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int mx = -999999999;
int N, K;
int input[100001];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	int a = 0;

	for (int i = 0; i < K; i++) {
		a += input[i];
	}
	for (int i = 0; i < N - K + 1; i++) {
		if (a > mx) {
			mx = a;
		}
		a += input[i + K];
		a -= input[i];
	}
	cout << mx;
}
