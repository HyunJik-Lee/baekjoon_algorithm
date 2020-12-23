#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
int input[11];
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int N = 0, K = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	int t = K;
	int cnt = 0;
	for (int i = N - 1; i >= 0; i--) {

		cnt += t / input[i];
		t = t % input[i];
		//if (t == 1) break;
	}
	cout << cnt;
}
