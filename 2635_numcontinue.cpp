#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;

vector<int> calc(int first, int second) {
	vector<int> res;
	int prev = first;
	int cur = second;
	res.push_back(prev);
	res.push_back(cur);
	while (cur >= 0) {
		int next_num = prev - cur;
		res.push_back(next_num);
		prev = cur;
		cur = next_num;
	}
	res.pop_back();
	return res;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	vector<int> temp;
	vector<int> ans;
	int vsize = 0;
	for (int i = 1; i <= N; i++) {
		temp = calc(N, i);
		if (temp.size() > vsize) {
			ans = temp;
			vsize = temp.size();
		}
	}

	cout << ans.size() << '\n';
	for (int x : ans)
	{
		cout << x << ' ';
	}
}
