#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {

	int x = 0, y = 0;
	cin >> x >> y;
	if (x > 0 && y > 0)
		cout << 1 << '\n';
	else if (x < 0 && y > 0)
		cout << 2 << '\n';
	else if (x < 0 && y < 0)
		cout << 3 << '\n';
	else if (x > 0 && y < 0)
		cout << 4 << '\n';
	return 0;
}
