#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
bool prime[1000001];

int tmp = 1;
void findprime(bool prime[]) {
	for (int i = 2; i * i < 1000001; i++) {
		if (prime[i] == 0)
			continue;
		for (int j = i + i; j < 1000001; j += i)
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
	int a = 0, b = 0;
	fill(prime, prime + 1000001, 1);
	prime[0] = prime[1] = 0;
	findprime(prime);
	while (tmp) {
		cin >> tmp;
		for (int i = 3; i <= tmp; i++) {
			if (prime[i]) {
				a = i;
			}
			if (!prime[tmp - a])
				continue;
			else {
				cout << tmp << " = " << a << " + " << tmp - a << '\n';
				break;
			}
		}
	}

}
