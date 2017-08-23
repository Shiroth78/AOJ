//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=jp

#include <iostream>
using namespace std;
static const int MAX = 20;

bool solve(int i, int m);

int n, q;
int A[MAX];

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	cin >> q;
	int m;
	for (int i = 0; i < q; i++) {
		cin >> m;
		if (solve(0, m)) {
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}
	}
}


bool solve(int i, int m) {
	//i番目以降の数字でmが作れるかどうか
	if (m == 0) {
		//m=0ならすべて使わないことで可能
		return true;
	}
	if (i >= n) {
		//n番目以降の数字は無いので不可能(iは0始まり)
		return false;
	}
	//i+1番目以降でmもしくはm-A[i]が作れるかどうか(どちらかが真なら真を返す)
	bool res = solve(i + 1, m) || solve(i + 1, m - A[i]);
	return res;
}