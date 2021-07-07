#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;
string pass;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	while (N--) {
		list<char> L;
		cin >> pass;
		auto cursor = L.end();
		for (char c : pass) {
			if (c == '<') {
				if (cursor != L.begin())
					cursor--;
			}
			else if (c == '>') {
				if (cursor != L.end())
					cursor++;
			}
			else if (c == '-') {
				if (cursor != L.begin()) {
					cursor--;
					cursor = L.erase(cursor);
				}
			}
			else {
				L.insert(cursor, c);
			}
		}
		for (auto a : L) cout << a;
		cout << '\n';
	}
}
