#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef struct _room {
	int t;
	int a;
	int h;
}Dungeon;
Dungeon input[123457];

int N, Hatk;

ll check(ll x, ll atk) {
	ll curH = x;
	ll curAtk = atk;
	for (int i = 0; i < N; i++) {
		if (curH <= 0)
			return true;
		if (input[i].t == 1) {
			ll num = 0;
			if (input[i].h % curAtk == 0)
				num = input[i].h / curAtk;
			else num = input[i].h / curAtk + 1;
			curH -= (num - 1) * input[i].a;;
		}
		else {
			curAtk += input[i].a;
			curH += input[i].h;
			if (curH > x)
				curH = x;
		}
	}
	return curH <= 0;
}

ll bc(ll l, ll r) {
	while (l + 1 < r) {
		ll c = l + r >> 1;
		if (check(c, Hatk))
			l = c;
		else r = c;
	}
	return r;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N >> Hatk;
	for (int i = 0; i < N; i++) {
		cin >> input[i].t >> input[i].a >> input[i].h;
	}
	cout << bc(0, 3e18);
}
