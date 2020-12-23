#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
int input[16];
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n = 0, W = 0;
	cin >> n >> W;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	ll cash = W;
	ll coin = 0;

	for (int i = 1; i < n + 1; i++) {

		if (input[i] > input[i - 1]) {
			coin += cash / input[i - 1];
			cash = cash % input[i - 1];
		}
		else if (input[i] < input[i - 1]) {
			cash += coin * input[i - 1];
			coin = 0;
		}

	}
	cout << cash;

}
//
//coin += cash / input[i - 1];
//cash = cash / input[i - 1];


///*for (int j = i; j < n; j++) {
		//	if (input[j -1] < input[j] && ) {
		//		coin += cash / input[i];
		//		cash = cash % input[i];
		//		cash += coin * input[j - 1];
		//		i = j - 1;
		//		break;
		//	}
		//	if(input[i] < input[j])
		//}*/
		//if (input[i - 1] > input[i]) {
		//	cash += coin * input[i - 1]; //팔기
		//	coin = 0;
		//}
		//else if (input[i - 1] < input[i]) {
		//	coin += cash / input[i - 1]; //사기
		//	cash = cash % input[i - 1];
		//}
