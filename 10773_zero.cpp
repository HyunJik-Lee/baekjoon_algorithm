#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	stack<int> st;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a = 0;
		cin >> a;
		if (a == 0)
			st.pop();
		else st.push(a);
	}
	int sum = 0;
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	cout << sum;
}
