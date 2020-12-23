#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

string num[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	string t;
	cin >> t;
	string res;
	if (t[0] == '0')
		res += "0";
	else if (t[0] == '1')
		res += "1";
	else if (t[0] == '2')
		res += "10";
	else if (t[0] == '3')
		res += "11";
	else
		res += num[t[0] - '0'];

	for (int i = 1; i < t.size(); i++) {
		res += num[t[i] - '0'];
	}
	cout << res << '\n';
}
