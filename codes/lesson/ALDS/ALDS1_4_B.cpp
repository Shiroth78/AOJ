//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B&lang=jp
#include <iostream>
using namespace std;
static const int MAX = 100000;
int S[MAX], T[MAX];
int n, m;

bool binarySearch(int key);

int main(void) {
	int ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> S[i];
	}
	cin >> m;
	for (int j = 0; j < m; j++) {
		cin >> T[j];
	}

	for (int j = 0; j < m; j++) {
		if (binarySearch(T[j])) ans++;
	}
	cout << ans << endl;
}

bool binarySearch(int key) {
	int left = 0;
	int right = n;
	while (left < right) {
		int mid = (left + right) / 2;
		if (S[mid] == key) {
			return true;
		}
		else if (key < S[mid]) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return false;
}
