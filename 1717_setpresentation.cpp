#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int parent[1000002];
int N, M;
int a, b, c;

int fi(int element) {
	if (parent[element] == -1) return element;
	return parent[element] = fi(parent[element]);
}

void uni(int ele1, int ele2) {
	int a = fi(ele1), b = fi(ele2);
	if (a == b) return;
	parent[a] = b;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N >> M;
	fill(parent, parent + N + 1, -1);
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (a == 0)
			uni(b, c);
		else if (a == 1) {
			if (fi(b) == fi(c))
				cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
