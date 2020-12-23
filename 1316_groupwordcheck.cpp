#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
bool alpha[26];
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int N;
	cin >> N;
	int cnt = 0;
	int j;
	for (int i = 0; i < N; i++) {
		string t;
		cin >> t;
		alpha[t[0] - 'a'] = true;
		for (j = 1; j < t.size(); j++) {

			if (t[j] == t[j - 1])
				continue;
			else if (alpha[t[j] - 'a'])
				break;
			else
				alpha[t[j] - 'a'] = true;
		}
		memset(alpha, 0, sizeof(alpha));
		if (j == t.size())
			cnt++;
	}
	cout << cnt << '\n';
}
