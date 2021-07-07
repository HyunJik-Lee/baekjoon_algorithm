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
	while (true) {
		string in;
		stack<int> st;
		getline(cin, in);
		bool flag = true;
		if (in == ".")
			break;
		for (auto& c : in) {
			if (c == '[')
				st.push(1);
			else if (c == '(')
				st.push(2);
			else if (c == ']') {
				if (!st.empty() && st.top() == 1)
					st.pop();
				else if (st.empty() || st.top() != 1)
					flag = false;

			}
			else if (c == ')') {
				if (!st.empty() && st.top() == 2)
					st.pop();
				else if (st.empty() || st.top() != 2)
					flag = false;
			}
		}
		if (st.empty() && flag)
			cout << "yes\n";
		else cout << "no\n";
	}
}
