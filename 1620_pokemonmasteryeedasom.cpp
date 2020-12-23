#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
typedef long long ll;
string dogam[100001];
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	map<string, int> m;
	int N, M;
	cin >> N >> M;
	string t;
	for (int i = 0; i < N; i++) {
		cin >> t;
		m[t] = i + 1;
		dogam[i + 1] = t;
	}
	for (int i = 0; i < M; i++) {
		cin >> t;
		if (isdigit(t[0])) {
			cout << dogam[stoi(t)] << '\n';
		}
		else {
			auto it = m.find(t);
			cout << it->second << '\n';
		}

	}

}
