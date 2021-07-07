#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

deque<int> dq;
int T, N;
string p;
string t;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> T;
	while (T--) {
		int cnt = 0;
		bool way = true;
		bool error = false;
		cin >> p >> N >> t;
		for (int i = 0; i < t.size(); i++) {
			int num = 0;
			if (t[i] != '[' && t[i] != ']' && t[i] != ',') {
				num = t[i] - '0';
				int j = i + 1;
				while (t[j] != '[' && t[j] != ']' && t[j] != ',') {
					num *= 10;
					num += t[j] - '0';
					j++;
					i++;
				}
				dq.push_back(num);
			}
		}

		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R')
				way = !way;
			else if (p[i] == 'D')
			{
				if (dq.empty()) {
					cout << "error" << '\n';
					error = true;
					break;
				}
				if (way) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
		}
		if (error)
			continue;
		cout << '[';
		if (way && !dq.empty()) {
			for (int i = 0; i < dq.size() - 1; i++) {
				cout << dq[i] << ',';
			}
			cout << dq[dq.size() - 1];
		}
		else if (!dq.empty()) {
			for (auto i = dq.end() - 1; i != dq.begin(); i--) {
				cout << *i << ',';
			}
			cout << *(dq.begin());
		}
		cout << ']' << '\n';
		dq.clear();
	}
}
