#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[9];
int a, b, c, d, e, f, g;
int main() {
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	vector<int> s;
	
	for (a = 0; a < 9; a++) {
		for (b = a + 1; b < 9; b++) {
			for (c = b + 1; c < 9; c++) {
				for (d = c + 1; d < 9; d++) {
					for (e = d + 1; e < 9; e++) {
						for (f = e + 1; f < 9; f++) {
							for (g = e + 1; g < 9; g++) {
								if (arr[a] + arr[b] + arr[c] + arr[d] + arr[e] + arr[f] + arr[g] == 100) {
									s.push_back(arr[a]);
									s.push_back(arr[b]);
									s.push_back(arr[c]);
									s.push_back(arr[d]);
									s.push_back(arr[e]);
									s.push_back(arr[f]);
									s.push_back(arr[g]);
									goto here;
								}
									
							}
						}
					}
				}
			}
		}
	}
	here:
	sort(s.begin(), s.end());
	for (int a : s) {
		cout << a << endl;
	}

}