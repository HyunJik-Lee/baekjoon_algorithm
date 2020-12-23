#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

bool comp(string a, string b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	else {
		return less<string>() (a, b);
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	vector<string> v;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string c;
		cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end(), comp);

	cout << v[0] << '\n';
	for (int i = 1; i < N; i++) {
		if (v[i - 1] == v[i]);
		else cout << v[i] << '\n';
	}

}
