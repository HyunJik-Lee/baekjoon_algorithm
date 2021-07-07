#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N, M;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	deque<int> dq;
	int N, M, cnt = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		dq.push_back(i);
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		int pos = 0;
		for (int j = 0; j < dq.size(); j++) {
			if (dq[j] == a) {
				pos = j;
				break;
			}
		}
		if (pos > dq.size() / 2) {
			while (1) {
				if (a == dq.front()) {
					dq.pop_front();
					break;
				}
				cnt++;
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
		else {
			while (1) {
				if (a == dq.front()) {
					dq.pop_front();
					break;
				}
				cnt++;
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
	}
	cout << cnt;
}
