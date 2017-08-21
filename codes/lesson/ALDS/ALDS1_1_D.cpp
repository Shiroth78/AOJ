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

	int maxv = -1000000000; //ç≈è¨ÇÕ1-10^9Ç»ÇÃÇ≈ÇªÇÍà»â∫ÇÃíl
	int minv = R[0];

	for (int i = 1; i<n; i++) {
		maxv = max(maxv, R[i] - minv);
		minv = min(minv, R[i]);
	}

	cout << maxv << endl;

}
