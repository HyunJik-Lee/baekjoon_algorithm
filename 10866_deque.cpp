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
	deque<int> dq;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string in;
		int a;
		cin >> in;
		if (in == "push_front") {
			cin >> a;
			dq.push_front(a);
		}
		else if (in == "push_back") {
			cin >> a;
			dq.push_back(a);
		}
		else if (in == "pop_front") {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}

		}
		else if (in == "pop_back") {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (in == "size") {
			cout << dq.size() << '\n';
		}
		else if (in == "empty") {
			cout << dq.empty() << '\n';
		}
		else if (in == "front") {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
			}
		}
		else if (in == "back") {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
			}
		}
	}
}
