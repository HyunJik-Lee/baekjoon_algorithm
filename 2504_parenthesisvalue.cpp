#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	stack<int> st;
	string input;
	int temp = 0;
	cin >> input;
	if (input[0] == ')' || input[0] == ']') {
		cout << 0 << '\n';
		return 0;
	}
	else st.push(-input[0]);
	for (int i = 1; i < input.size(); i++) {
		if (input[i] == '(' || input[i] == '[')
			st.push(-input[i]);
		else if (input[i] == ')') {
			if (-st.top() == '(') {
				st.pop();
				st.push(2);
			}
			else if (-st.top() == '[') {
				cout << 0 << '\n';
				return 0;
			}
			else {
				while (!st.empty() && st.top() >= 0) {
					int a = st.top();
					if (-a == '[') {
						cout << 0 << '\n';
						return 0;
					}
					st.pop();
					temp += a;
				}
				if (st.empty() || -st.top() == '[')
					break;
				else st.pop();
				st.push(temp * 2);
			}
		}
		else if (input[i] == ']') {
			if (-st.top() == '[') {
				st.pop();
				st.push(3);
			}
			else if (-st.top() == '(') {
				cout << 0 << '\n';
				return 0;
			}
			else {
				while (!st.empty() && st.top() >= 0) {
					int a = st.top();
					if (-a == '(') {
						cout << 0 << '\n';
						return 0;
					}
					st.pop();
					temp += a;
				}
				if (st.empty() || -st.top() == '(')
					break;
				else st.pop();
				st.push(temp * 3);
			}
		}
		temp = 0;
	}

	int sum = 0;
	while (!st.empty()) {
		if (st.top() < 0) {
			cout << 0 << '\n';
			return 0;
		}
		else {
			sum += st.top();
			st.pop();
		}
	}

	cout << sum << '\n';
}
