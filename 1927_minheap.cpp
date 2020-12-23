#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
int input[100001];
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	int res;
	priority_queue<int, vector<int>, greater<>> pq;
	for (int i = 0; i < N; i++) {
		if (input[i] == 0) {
			if (!pq.empty()) {
				res = pq.top();
				pq.pop();
				cout << res << '\n';
			}
			else cout << 0 << '\n';
		}
		else pq.push(input[i]);
	}
}
