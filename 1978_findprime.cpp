#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool prime[1002] = { 0,0,1,1 };
int cnt;
int tmp;
int N;

void findprime(bool prime[]) {
	for (int i = 2; i * i < 1002; i++) {
		if (prime[i] == 0)
			continue;
		for (int j = i + i; j < 1002; j += i)
			prime[j] = false;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	fill(prime, prime + 1002, 1);
	findprime(prime);
	prime[0] = prime[1] = false;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (prime[tmp])
			cnt++;
	}
	cout << cnt;
}
