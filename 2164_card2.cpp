#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	queue<int> q;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		q.push(i + 1);
	}
	int t;
	while (q.size() != 1) {
		q.pop();
		t = q.front();
		q.pop();
		q.push(t);
	}

	cout << q.front() << '\n';
}
