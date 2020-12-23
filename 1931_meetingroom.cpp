#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
pair<int, int> meeting[100001];

bool comp1(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second)
		return p1.first < p2.first;
	else return p1.second < p2.second;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> meeting[i].first >> meeting[i].second;
	}
	sort(meeting, meeting + N, comp1);
	int cnt = 1;
	int t = 0;

	for (int i = 1; i < N; i++) {
		if (meeting[t].second <= meeting[i].first) {
			cnt++;
			t = i;
		}
	}

	cout << cnt << "\n";

}
