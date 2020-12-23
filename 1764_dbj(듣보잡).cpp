#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int d, b;
	int all;
	cin >> d >> b;
	all = d + b;
	int cnt = 0;
	string t;
	set<string> se;
	vector<string> v;
	for (int i = 0; i < all; i++) {
		cin >> t;
		if (se.find(t) != se.end()) {
			cnt++;
			v.push_back(t);
		}
		se.insert(t);
	}
	sort(v.begin(), v.end());
	cout << cnt << '\n';
	for (string i : v) {
		cout << i << '\n';
	}
}
