#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	string t;
	vector<string> v;
	while (!cin.eof()) {
		cin >> t;
		if (!t.empty())
			v.push_back(t);
		t = "";
	}
	cout << v.size() << '\n';
}
