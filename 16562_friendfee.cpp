#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int M, N, K;
int fee[10002];
int v, w;
int parent[10002];

int fi(int element) {
	if (parent[element] < 0) return element;
	return parent[element] = fi(parent[element]);
}

void uni(int ele1, int ele2) {
	int a = fi(ele1), b = fi(ele2);
	if (a == b) return;
	if (fee[a] > fee[b]) {
		parent[a] = b;
	}
	else {
		parent[b] = a;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N >> M >> K;
	int money = 0;
	fill(parent, parent + N + 1, -1);
	for (int i = 1; i <= N; i++) {
		cin >> fee[i];
	}
	for (int j = 0; j < M; j++) {
		cin >> v >> w;
		uni(v, w);
	}
	for (int i = 1; i <= N; i++) {
		if (parent[i] < 0)
			money += fee[i];
	}
	if (money > K)
		cout << "Oh no";
	else cout << money;
}
