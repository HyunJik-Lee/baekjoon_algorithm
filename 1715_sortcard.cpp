#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	priority_queue<int, vector<int>, greater<>> pq;
	int N;
	cin >> N;
	int t;
	int cnt = 0;
	if (N == 1) {
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 0; i < N; i++) {
		cin >> t;
		pq.push(t);
	}
	while (pq.size() != 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		cnt += a + b;
		pq.push(a + b);
	}
	cout << cnt << '\n';
}
