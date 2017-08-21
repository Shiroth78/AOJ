//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
#include <iostream>
#include <cmath>
using namespace std;
//static const int MAX = 10000;


bool isPrime(int num);

int main(void) {
	int x, num;
	int ans = 0;
	cin >> x;
	for (int i = 0; i < x; i++) {
		cin >> num;
		if (isPrime(num) == true) {
			ans++;
		}
	}
	cout << ans << endl;
}


bool isPrime(int num) {
	if (num == 2) return true;
	else if (num < 2 || num%2==0) return false;
	else {
		int i = 3;
		while (i <= sqrt(num)) {
			if (num%i == 0) return false;
			i += 2;
		}
	}
	return true;
}
