#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;
vector<int> v, l;
map<int, int> m;
int cnt;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t = 0;
		cin >> t;
		v.push_back(t);
		l.push_back(t);
	}
	sort(v.begin(), v.end());
	for (int a : v) {
		if (m.find(a) == m.end())
			m.insert({ a, cnt++ });
	}
	for (int a : l) {
		cout << m[a] << '\n';
	}
}
