#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct Trie {
	Trie* children[10] = {};
	bool terminal = 0;
	bool hasChild = 0;

	~Trie() {
		for (auto i : children) delete i;
	}

	bool insert(string& s) {
		Trie* cur = this;
		for (char x : s) {
			if (!cur->children[x - '0']) {
				cur->children[x - '0'] = new Trie;
				cur->hasChild = true;
			}
			cur = cur->children[x - '0'];
			if (cur->terminal) return false;
		}
		if (cur->hasChild) return false;
		cur->terminal = true;
		return true;
	}

	//bool find(string& s) {
	//	Trie* cur = this;
	//	for (char x : s) {
	//		if (!cur->children[x - '0'])
	//			return 0;
	//		cur = cur->children[x - '0'];
	//	}
	//	return cur->terminal;
	//}
};

int T, N;
string in;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	bool possible = true;
	cin >> T;
	while (T--) {
		Trie root;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> in;
			possible &= root.insert(in);
		}
		if (possible)
			cout << "YES\n";
		else cout << "NO\n";
		possible = true;
	}
}
