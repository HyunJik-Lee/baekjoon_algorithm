#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	stack<pii> st;
	vector<int> v;
	int N, a;
	cin >> N;
	cin >> a;
	st.push({ a, 1 });
	v.push_back(0);
	for (int i = 2; i <= N; i++) {
		cin >> a;
		if (st.top().first < a) {
			while (!st.empty() && st.top().first < a)
				st.pop();
			if (st.empty()) v.push_back(0);
			else v.push_back(st.top().second);
			st.push({ a, i });
		}
		else {
			v.push_back(st.top().second);
			st.push({ a, i });
		}


	}
	for (int i : v) {
		cout << i << ' ';
	}
}
