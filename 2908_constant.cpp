#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int a = 0, b = 0;
	cin >> a >> b;
	int a_r = 0, b_r = 0;
	a_r = (a / 100) + (a % 100 / 10) * 10 + (a % 10) * 100;
	b_r = (b / 100) + (b % 100 / 10) * 10 + (b % 10) * 100;
	if (a_r >= b_r) {
		cout << a_r << '\n';
	}
	else cout << b_r << '\n';

}
