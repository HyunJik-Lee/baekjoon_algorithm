#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

enum op {
	push,
	pop,
	size,
	empty,
	front,
	back
};
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int N;
	cin >> N;

	queue<int> q;

	string opcode;
	int oper = 0;
	int operand = 0;
	int res = 0;

	for (int i = 0; i < N; i++) {
		cin >> opcode;
		if (opcode == "push") {
			oper = op::push;
			cin >> operand;
		}
		else if (opcode == "pop") {
			oper = op::pop;
		}
		else if (opcode == "size") {
			oper = op::size;
		}
		else if (opcode == "empty") {
			oper = op::empty;
		}
		else if (opcode == "front") {
			oper = op::front;
		}
		else if (opcode == "back") {
			oper = op::back;
		}

		switch (oper) {
		case op::push:
			q.push(operand);
			break;
		case op::pop:
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				res = q.front();
				q.pop();
				cout << res << '\n';
			}
			break;
		case op::size:
			cout << q.size() << '\n';;
			break;
		case op::empty:
			cout << q.empty() << '\n';;
			break;
		case op::front:
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				res = q.front();
				cout << res << '\n';
			}
			break;
		case op::back:
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				res = q.back();
				cout << res << '\n';
			}
			break;
		}

	}

}
