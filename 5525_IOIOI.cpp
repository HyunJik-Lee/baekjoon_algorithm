#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, M;
string S;
int cnt, ans;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N >> M >> S;
	for (int i = 0; i < M - 2; i++) {
		if (S[i] == 'I' && S[i + 1] == 'O' && S[i + 2] == 'I') {
			cnt++;
			if (cnt == N) {
				ans++;
				cnt--;
			}
			i++;
		}
		else cnt = 0;
	}
	cout << ans;
}
