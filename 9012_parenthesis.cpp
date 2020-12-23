#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	stack<char> st;
	int N;
	cin >> N;
	string t;

	for (int i = 0; i < N; i++) {
		cin >> t;
		while (!st.empty()) st.pop();
		st.push('f');
		for (int j = 0; j < t.size(); j++) {
			if (t[j] == ')' && !st.empty()) {
				st.pop();
			}
			if (t[j] == '(')
				st.push(t[j]);

		}
		if (!st.empty() && st.top() == 'f')
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}
