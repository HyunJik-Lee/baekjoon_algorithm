#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	queue<int> line;
	stack<int> temp;
	int N;
	int stu;
	int last = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> stu;
		line.push(stu);
	}

	while (!line.empty()) {
		if (line.front() == last) {
			line.pop();
			last++;
		}
		else {
			stu = line.front();
			line.pop();
			temp.push(stu);
		}
		while (!temp.empty()) {
			if (temp.top() == last) {
				temp.pop();
				last++;
			}
			else {
				break;
			}
		}
	}

	while (!temp.empty()) {
		if (temp.top() == last) {
			temp.pop();
			last++;
		}
		else {
			break;
		}
	}

	if (line.empty() && temp.empty())
		cout << "Nice" << '\n';
	else cout << "Sad" << '\n';

	return 0;
}
