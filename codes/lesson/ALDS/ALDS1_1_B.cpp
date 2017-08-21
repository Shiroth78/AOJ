//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B&lang=jp
#include <iostream>
using namespace std;

int gcd(int x, int y);

int main(void) {
	int x, y;
	cin >> x >> y;
	cout << gcd(x, y) << endl;
}

int gcd(int x, int y) {
	if (x < y) swap(x, y);
	while (y != 0) {
		int tmp = x%y;
		x = y;
		y = tmp;
	}
	return x;
}

