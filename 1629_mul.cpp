#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll mul(ll a, ll b, ll c) {
	if (b == 1) return a % c;
	ll p = mul(a, b / 2, c);
	ll t = (p * p) % c;
	if ((b % 2)) t *= a % c;
	return t % c;
}

int main() {
	ll A, B, C;
	cin >> A >> B >> C;
	cout << mul(A, B, C) << endl;
}
