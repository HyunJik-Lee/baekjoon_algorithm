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
	string input;
	list<char> lst;
	int M = 0;
	char op = 0, opend = 0;
	cin >> input;
	for (char c : input)
		lst.push_back(c);
	auto it = lst.end();
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> op;
		if (op == 'L') {
			if (it != lst.begin()) --it;
		}
		else if (op == 'D') {
			if (it != lst.end()) ++it;
		}
		else if (op == 'B') {
			if (it != lst.begin()) {
				it--;
				it = lst.erase(it);
			}
		}
		else if (op == 'P') {
			cin >> opend;
			lst.insert(it, opend);
		}

	}
	for (char c : lst) {
		cout << c;
	}

}
