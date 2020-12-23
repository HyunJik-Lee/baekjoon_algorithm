#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
int alpha[26];
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	memset(alpha, -1, sizeof(alpha));
	string a;
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (alpha[a[i] - 'a'] == -1)
			alpha[a[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		cout << alpha[i] << ' ';
	}
}
