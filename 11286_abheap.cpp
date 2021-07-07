#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
int t;
int t2;
priority_queue<pii, vector<pii>, greater<>> pq;

int ab(int a) {
	return (a > 0) ? a : -a;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t;
		if (t == 0) {
			if (!pq.empty()) {
				cout << pq.top().second << '\n';
				pq.pop();
			}
			else cout << 0 << '\n';
		}
		else {
			t2 = ab(t);
			pq.push({ t2, t });
		}
	}
}
