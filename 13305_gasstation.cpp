#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
ll dist[100001];
ll gas[100002];
ll cost;
ll money;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> dist[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> gas[i];
	}
	money = gas[0];
	for (int i = 0; i < N - 1; i++) {
		if (money > gas[i])
			money = gas[i];
		cost += money * dist[i];
	}
	cout << cost;
}
