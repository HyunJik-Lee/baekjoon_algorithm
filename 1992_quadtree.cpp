#include <iostream>
#include <algorithm>

using namespace std;

int N;
char input[65][65];
string quad(int n, int i, int j) {
	string s;
	if (n == 1) return s = input[i][j];
	char p = input[i][j];
	int f = 0;

	for (int a = i; a < n + i; a++) {
		for (int b = j; b < n + j; b++) {
			if (p != input[a][b]) {
				f = 1;
				break;
			}
		}
		if (f == 1) break;
	}

	if (f == 1) {
		return s = "(" + quad(n / 2, 0 + i, 0 + j) + quad(n / 2, 0 + i, n / 2 + j) + quad(n / 2, n / 2 + i, 0 + j) + quad(n / 2, n / 2 + i, n / 2 + j) + ")";

	}
	else return s = p;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // !LOCAL

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	cout << quad(N, 0, 0) << endl;

}
