//#include <bits/stdc++.h>
//
//using namespace std;
//typedef long long ll;
//typedef pair<int, int> pii;
//
//int T, K;
//int main() {
//	cin.tie(0);
//	cout.tie(0);
//	ios::sync_with_stdio(false);
//#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//#endif
//	cin >> T;
//	while (T--) {
//		multiset<int> ms;
//		cin >> K;
//		for (int i = 0; i < K; i++) {
//			char a; int b;
//			cin >> a >> b;
//			if (a == 'I') {
//				ms.emplace(b);
//			}
//			else {
//				if (ms.empty()) continue;
//				if (b == -1) {
//					ms.erase(ms.begin());
//				}
//				else {
//					ms.erase(--ms.end());
//				}
//			}
//		}
//		if (ms.empty()) cout << "EMPTY\n";
//		else cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
//	}
//
//
//}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool visited[1000001];
int T, K;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> T;
	while (T--) {
		cin >> K;
		priority_queue<pii> maxheap;
		priority_queue<pii, vector<pii>, greater<pii>> minheap;
		for (int i = 0; i < K; i++) {
			char a; int b;
			cin >> a >> b;
			if (a == 'I') {
				maxheap.push({ b, i });
				minheap.push({ b, i });
				visited[i] = true;
			}
			else {
				if (b == 1) {
					while (!maxheap.empty() && !visited[maxheap.top().second]) {
						maxheap.pop();
					}
					if (!maxheap.empty()) {
						visited[maxheap.top().second] = false;
						maxheap.pop();
					}
				}
				else {
					while (!minheap.empty() && !visited[minheap.top().second]) {
						minheap.pop();
					}
					if (!minheap.empty()) {
						visited[minheap.top().second] = false;
						minheap.pop();
					}
				}
			}
		}
		while (!maxheap.empty() && !visited[maxheap.top().second])
			maxheap.pop();
		while (!minheap.empty() && !visited[minheap.top().second])
			minheap.pop();
		if (maxheap.empty() && minheap.empty()) cout << "EMPTY\n";
		else cout << maxheap.top().first << ' ' << minheap.top().first << '\n';
	}
}
