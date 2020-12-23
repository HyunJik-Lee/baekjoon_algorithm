#include <iostream>
using namespace std;
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int R;
		string input;
		cin >> R >> input;
		for (int j = 0; j < input.size(); j++) {
			for (int k = 0; k < R; k++)
				cout << input[j];

		}
		cout << '\n';

	}
}
