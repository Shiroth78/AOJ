//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_D

#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 200000;

int main(void) {
	int R[MAX], n;
	cin >> n;
		for (int i = 0; i<n; i++) {
			cin >> R[i];
		}

	int maxv = -1000000000; //最小は1-10^9なのでそれ以下の値
	int minv = R[0];

	for (int i = 1; i<n; i++) {
		maxv = max(maxv, R[i] - minv);
		minv = min(minv, R[i]);
	}

	cout << maxv << endl;

}
