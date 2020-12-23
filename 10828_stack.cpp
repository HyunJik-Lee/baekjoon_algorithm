#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long ll;
enum op {
	push,
	pop,
	size,
	empty,
	top
};
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int N;
	cin >> N;

	stack<int> st;

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
		else if (opcode == "top") {
			oper = op::top;
		}

		switch (oper) {
		case op::push:
			st.push(operand);
			break;
		case op::pop:
			if (st.empty()) {
				cout << -1 << '\n';
			}
			else {
				res = st.top();
				st.pop();
				cout << res << '\n';
			}
			break;
		case op::size:
			cout << st.size() << '\n';;
			break;
		case op::empty:
			cout << st.empty() << '\n';;
			break;
		case op::top:
			if (st.empty()) {
				cout << -1 << '\n';
			}
			else {
				res = st.top();
				cout << res << '\n';
			}
			break;
		}
	}

}
