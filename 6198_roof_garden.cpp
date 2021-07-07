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
	stack<int> st;
	int N, a;
	ll sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		while (!st.empty() && st.top() <= a)
			st.pop();
		st.push(a);
		sum += st.size() - 1;
	}

	cout << sum;
}
