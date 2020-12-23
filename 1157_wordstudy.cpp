#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;
int alpha[26];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	string a;
	cin >> a;
	transform(a.begin(), a.end(), a.begin(), ::tolower);
	for (int i = 0; i < a.size(); i++) {
		alpha[a[i] - 'a']++;
	}
	int max = 0;
	char res = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] > max) {
			max = alpha[i];
			res = i + 'A';
		}
		else if (alpha[i] == max)
			res = '?';
	}
	cout << res;
}
