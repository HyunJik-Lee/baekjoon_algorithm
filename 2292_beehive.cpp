#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	//#ifdef LOCAL
	//	freopen("input.txt", "r", stdin);
	//#endif
	int N;

	int i;
	cin >> N;
	if (N == 1) {
		cout << 1 << '\n';
		//return 0;
	}
	else {
		for (i = 1; i < 166666666; i++) {
			int n = 3 * i * i - 3 * i + 2;
			int n_n = 3 * (i + 1) * (i + 1) - 3 * (i + 1) + 2;
			if (n <= N && N < n_n)
				break;
		}
		cout << i + 1 << '\n';
	}

}
