#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	multiset<int> ms;
	priority_queue<pii, vector<pii>, less<>> pq;
	int N, K;
	int a, b;
	ll sum = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		pq.push(make_pair(b, a));
	}
	for (int i = 0; i < K; i++) {
		cin >> a;
		ms.insert(a);
	}
	while (!ms.empty() && !pq.empty()) {
		ll weight = pq.top().second;
		ll value = pq.top().first;
		auto start = ms.lower_bound(weight);
		if (start == ms.end())
			pq.pop();
		for (start; start != ms.end();) {
			if (*start >= weight) {
				ms.erase(start++);
				pq.pop();
				sum += value;
				break;
			}
		}
	}
	cout << sum << '\n';
}
