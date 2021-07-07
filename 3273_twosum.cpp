#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;
int x;
int v[100001];
bool vaild[1000001];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	cin >> x;
	for (int i = 0; i < N; i++) {
		if (x - v[i] > 0)
			if (vaild[x - v[i]]) cnt++;
			else vaild[v[i]] = true;
		else continue;
	}
	cout << cnt << '\n';
}
