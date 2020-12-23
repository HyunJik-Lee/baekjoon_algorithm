#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int res = 0;
	while (!cin.eof()) {
		int t = 0;
		cin >> t;
		res += (t * t) % 10;
	}
	cout << res % 10 << '\n';
}
