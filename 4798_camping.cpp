#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int L, P, V;
	cin >> L >> P >> V;
	int num = 1;
	int day = 0;
	while (L != 0 && P != 0 && V != 0) {
		int t = V % P;
		if (t > L)
			day = V / P * L + L;
		else
			day = V / P * L + t;

		cout << "Case " << num++ << ": " << day << '\n';
		cin >> L >> P >> V;
	}
}
