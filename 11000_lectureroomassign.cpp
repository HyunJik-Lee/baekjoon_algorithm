#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

pair<int, int> lecture[200001];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> lecture[i].first >> lecture[i].second;
	}
	sort(lecture, lecture + N);
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(lecture[0].second);
	int s, e;
	for (int i = 1; i < N; i++) {
		s = lecture[i].first;
		e = lecture[i].second;
		if (pq.top() > s) {
			pq.push(e);
		}
		else {
			pq.pop();
			pq.push(e);
		}
	}
	cout << pq.size() << '\n';
	return 0;
}
