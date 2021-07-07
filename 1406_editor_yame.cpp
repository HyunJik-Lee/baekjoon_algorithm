#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MX = 1000005;
char dat[MX];
int pre[MX];
int nxt[MX];
int unused = 1;

void insert(int addr, char num) {
	dat[unused] = num;
	pre[unused] = addr;
	nxt[unused] = nxt[addr];
	if (nxt[addr] != -1) pre[nxt[addr]] = unused;
	nxt[addr] = unused;
	unused++;
}
void erase(int addr) {
	if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
	nxt[pre[addr]] = nxt[addr];
}

void traverse() {
	int cur = nxt[0];
	while (cur != -1) {
		cout << dat[cur];
		cur = nxt[cur];
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	fill(pre, pre + MX, -1);
	fill(nxt, nxt + MX, -1);
	string input;
	cin >> input;
	int cursor = 0;
	for (char c : input) {
		insert(cursor, c);
		cursor++;
	}
	int M;
	cin >> M;
	while (M--) {
		char op;
		cin >> op;
		if (op == 'L') {
			if (pre[cursor] != -1) cursor = pre[cursor];
		}
		else if (op == 'D') {
			if (nxt[cursor] != -1) cursor = nxt[cursor];
		}
		else if (op == 'B') {
			if (pre[cursor] != -1) {
				erase(cursor);
				cursor = pre[cursor];
			}
		}
		else if (op == 'P') {
			char opend;
			cin >> opend;
			insert(cursor, opend);
			cursor = nxt[cursor];
		}
	}
	traverse();
}
