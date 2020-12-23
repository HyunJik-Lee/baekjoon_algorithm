#include <iostream>
#include <algorithm>
using namespace std;
int arr[100];


int main() {
	int N = 0, M = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				int t = arr[i] + arr[j] + arr[k];
				if(t <= M && M-result >= M-t)
					result = t;
			}
		}
	}
	cout << result;
}