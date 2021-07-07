#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int nums[10];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	string a;
	cin >> a;
	for (auto i : a) {
		nums[i - '0']++;
	}
	nums[6] += nums[9] + 1;
	nums[6] /= 2;

	int res = *max_element(nums, nums + 9);
	cout << res;

}
