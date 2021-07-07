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
	vector<int> v;
	for (int i = 1; i <= 20; i++) {
		v.push_back(i);
	}
	int s = 0, e = 0;
	for (int i = 0; i < 10; i++) {
		cin >> s >> e;
		reverse(v.begin() + s - 1, v.begin() + e);
	}
	for (int i : v)
		cout << i << ' ';
}
