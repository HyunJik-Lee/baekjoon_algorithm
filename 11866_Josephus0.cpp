#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
int N, K;
int check[1001];
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int i, j, t;
	vector<int> v;
	queue<int> q;
	deque<int> d;
	cin >> N >> K;
	for (i = 1; i <= N; i++)
		q.push(i);

	while (!q.empty()) {
		for (j = 0; j < K; j++) {
			if (j == K - 1) {
				t = q.front();
				q.pop();
				v.push_back(t);

			}
			else {
				t = q.front();
				q.pop();
				q.push(t);
			}
		}
	}

	cout << '<';
	for (i = 0; i < N; i++) {
		cout << v[i];
		if (i != N - 1)
			cout << ',' << ' ';
	}
	cout << '>' << '\n';
}
