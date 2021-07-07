#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int alpha[26];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	string a;
	cin >> a;
	for (char c : a) {
		alpha[c - 'a']++;
	}
	for (int i : alpha) {
		cout << i << ' ';
	}
}
