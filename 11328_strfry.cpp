#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
string a, b;
vector<int> v1, v2;
vector<int> numnum(string& a) {
	vector<int> abc(26);
	for (auto c : a)
		abc[c - 'a']++;
	return abc;
}
bool cmp(string& a, string& b) {
	if (numnum(a) == numnum(b)) return true;
	else return false;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	while (N--) {
		cin >> a >> b;
		if (cmp(a, b))
			cout << "Possible\n";
		else cout << "Impossible\n";
	}
}
