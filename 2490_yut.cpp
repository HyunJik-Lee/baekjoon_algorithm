#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	for (int j = 0; j < 3; j++) {
		int o = 0, a = 0;
		for (int i = 0; i < 4; i++) {
			cin >> a;
			if (a) o++;
		}
		switch (o) {
		case 0:
			cout << "D" << '\n';
			break;
		case 1:
			cout << "C" << '\n';
			break;
		case 2:
			cout << "B" << '\n';
			break;
		case 3:
			cout << "A" << '\n';
			break;
		case 4:
			cout << "E" << '\n';
			break;
		}
	}

}
