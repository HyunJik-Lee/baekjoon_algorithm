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
	string t;
	int sum = 0;
	stack<char> st;
	cin >> t;
	for (auto i = 0; i < t.size(); i++) {
		if (t[i] == '(') {
			st.push(t[i]);
		}
		else if (t[i] == ')' && t[i - 1] == '(') {
			st.pop();
			sum += st.size();
		}
		else {
			sum++;
			st.pop();
		}
	}
	cout << sum;
}
