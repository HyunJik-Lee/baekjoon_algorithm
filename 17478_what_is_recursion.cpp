﻿#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;
const string dash = "____";
void func(int n) {
	if (n > N) {
		for (int i = n - 1; i > 0; i--) cout << dash;
		cout << "\"재귀함수가 뭔가요?\"\n";
		for (int i = n - 1; i > 0; i--) cout << dash;
		cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
		for (int i = n - 1; i > 0; i--) cout << dash;
		cout << "라고 답변하였지.\n";
		return;
	}
	for (int i = n - 1; i > 0; i--) cout << dash;
	cout << "\"재귀함수가 뭔가요?\"\n";
	for (int i = n - 1; i > 0; i--) cout << dash;
	cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
	for (int i = n - 1; i > 0; i--) cout << dash;
	cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
	for (int i = n - 1; i > 0; i--) cout << dash;
	cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
	func(n + 1);
	for (int i = n - 1; i > 0; i--) cout << dash;
	cout << "라고 답변하였지.\n";
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	func(1);
}
