#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef struct _stu {
	string name;
	int kor;
	int eng;
	int math;
} Student;
Student arr[100001];

bool comp(Student a, Student b) {
	if (a.kor == b.kor && a.eng == b.eng && a.math == b.math)
		return less<string>()(a.name, b.name);
	else if (a.kor == b.kor && a.eng == b.eng)
		return greater<int>()(a.math, b.math);
	else if (a.kor == b.kor)
		return less<int>()(a.eng, b.eng);
	else return greater<int>()(a.kor, b.kor);

}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int N;
	cin >> N;
	Student t;
	for (int i = 0; i < N; i++) {
		cin >> t.name >> t.kor >> t.eng >> t.math;
		arr[i] = t;
	}
	sort(arr, arr + N, comp);
	for (int i = 0; i < N; i++) {
		cout << arr[i].name << '\n';
	}
	return 0;
}
