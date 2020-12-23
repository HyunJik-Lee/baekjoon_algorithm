#include <iostream>
using namespace std;

int main() {
	int N = 0;
	cin >> N;
	int i = 0;
	int j = 0;
	for (i = 1; i < N; i++) {
		for (j = N - i; j > 0; j--) {
			cout << ' ';
		}
		for (j = 2 * i - 1; j > 0; j--) {
			cout << '*';
		}
		cout << '\n';
	}
	for (; i > 0; i--) {
		for (j = N - i; j > 0; j--) {
			cout << ' ';
		}
		for (j = 2 * i - 1; j > 0; j--) {
			cout << '*';
		}
		cout << '\n';
	}

}
