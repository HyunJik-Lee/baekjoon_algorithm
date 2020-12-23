#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	string t;
	cin >> t;
	queue<int> q;
	int flag = t.size() % 3;
	if (flag == 1) {
		t = "00" + t;
	}
	else if (flag == 2) {
		t = "0" + t;
	}
	for (int i = 0; i < t.size(); i += 3) {
		int a = 0;
		a += (t[i] - '0') * 4;
		a += (t[i + 1] - '0') * 2;
		a += t[i + 2] - '0';
		q.push(a);
	}

	while (!q.empty()) {
		cout << q.front();
		q.pop();
	}
	cout << '\n';
}
