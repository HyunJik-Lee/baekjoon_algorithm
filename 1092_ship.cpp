#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int crane[51];
vector<int> boxes;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int N = 0, M = 0;
	int t = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> crane[i];
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> t;
		boxes.push_back(t);
	}
	sort(crane, crane + N, greater<>());
	sort(boxes.begin(), boxes.end(), greater<>());
	int time = 0;
	int limit = crane[0];
	for (int i = 0; i < M; i++) {
		if (boxes[i] > limit) {
			cout << -1 << endl;
			return 0;
		}
	}

	while (boxes.size() != 0) {
		time++;
		boxes.erase(boxes.begin());

		if (boxes.size() != 0) {
			for (int c = 1; c < N; c++) {
				for (auto i = boxes.begin(); i != boxes.end(); ++i) {
					if (*i <= crane[c]) {
						boxes.erase(i);
						break;
					}
				}
			}
		}
	}
	cout << time << endl;
}
