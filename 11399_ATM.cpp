#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;


int input[1001];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	sort(input, input + N);
	int pre = input[0];
	int ret = pre;
	for (int i = 1; i < N; i++) {
		pre += input[i];
		ret += pre;
	}
	cout << ret << endl;
}
