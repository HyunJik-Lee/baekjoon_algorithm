#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int input[200001];
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	int op = 0;
	int a = 0;
	int b = 0;
	int N = 0, Q = 0;
	int s = 0;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	for (int i = 0; i < Q; i++) {
		cin >> op;
		switch (op) {
		case 1:
			cin >> a;
			cin >> b;
			input[((a - 1) + s) % N] += b;
			break;
		case 2:
			cin >> a;
			s = (s + N - a) % N;
			break;
		case 3:
			cin >> a;
			s = (s + a) % N;
			break;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << input[(i + s) % N] << ' ';
	}
}
