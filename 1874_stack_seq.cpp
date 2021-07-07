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
	deque<int> in;
	vector<char> v;
	stack<int> st;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		in.push_back(i);
	st.push(-1);
	int a = 0;
	for (int n : in) {
		cin >> a;
		if (a > st.top()) {
			while (a != in.front()) {
				st.push(in.front());
				in.pop_front();
				v.push_back('+');
			}
			st.push(in.front());
			in.pop_front();
			v.push_back('+');
		}
		else if (a == st.top()) {
			st.pop();
			v.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}

		if (!st.empty() && a == st.top()) {
			st.pop();
			v.push_back('-');
		}
	}

	for (char c : v) {
		cout << c << '\n';
	}
}
