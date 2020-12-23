#include <iostream>

using namespace std;
long long arr[10000];
long long fibo(long long n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (arr[n] != 0) return arr[n];

	arr[n] = fibo(n - 1) + fibo(n - 2);
	return arr[n];
}
int main() {
	int n;
	cin >> n;
	cout << fibo(n);

}
