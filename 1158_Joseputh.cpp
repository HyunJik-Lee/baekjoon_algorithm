#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N, K;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	list<int> L;
	vector<int> v;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		L.push_back(i);
	}
	auto it = L.begin();
	while (L.size() != 1) {
		for (int i = 0; i < K - 1; i++) {
			++it;
			if (it == L.end()) it = L.begin();
		}
		v.push_back(*it);
		it = L.erase(it);
		if (it == L.end())
			it = L.begin();
	}
	cout << "<";
	for (int i : v) cout << i << ", ";
	cout << *it << ">" << '\n';
}
