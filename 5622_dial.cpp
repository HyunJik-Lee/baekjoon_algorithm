#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

// ABC 2, DEF 3, GHI 4, JKL 5, MNO 6, PQRS 7, TUV 8, WXYZ 9
// 656667 686970 717273 747576 777879 80818283 848586 87888990
//0 1 2, 3 4 5, 6 7 8, 9 10 11, 12 13 14, 15 16 17 18, 19 20 21, 22 23 24 25
/// 3
//123 456 789 1011
map<char, int> m;
int sum;
vector<int> num;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	m.insert({ 'A',2 });
	m.insert({ 'B',2 });
	m.insert({ 'C',2 });
	m.insert({ 'D',3 });
	m.insert({ 'E',3 });
	m.insert({ 'F',3 });
	m.insert({ 'G',4 });
	m.insert({ 'H',4 });
	m.insert({ 'I',4 });
	m.insert({ 'J',5 });
	m.insert({ 'K',5 });
	m.insert({ 'L',5 });
	m.insert({ 'M',6 });
	m.insert({ 'N',6 });
	m.insert({ 'O',6 });
	m.insert({ 'P',7 });
	m.insert({ 'Q',7 });
	m.insert({ 'R',7 });
	m.insert({ 'S',7 });
	m.insert({ 'T',8 });
	m.insert({ 'U',8 });
	m.insert({ 'V',8 });
	m.insert({ 'W',9 });
	m.insert({ 'X',9 });
	m.insert({ 'Y',9 });
	m.insert({ 'Z',9 });

	string t;
	cin >> t;
	for (int i = 0; i < t.size(); i++) {
		num.push_back(m[t[i]]);
	}
	for (int x : num) {
		sum += x + 1;
	}
	cout << sum;

}
