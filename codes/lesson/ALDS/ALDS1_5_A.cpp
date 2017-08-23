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
	//i�Ԗڈȍ~�̐�����m�����邩�ǂ���
	if (m == 0) {
		//m=0�Ȃ炷�ׂĎg��Ȃ����Ƃŉ\
		return true;
	}
	if (i >= n) {
		//n�Ԗڈȍ~�̐����͖����̂ŕs�\(i��0�n�܂�)
		return false;
	}
	//i+1�Ԗڈȍ~��m��������m-A[i]�����邩�ǂ���(�ǂ��炩���^�Ȃ�^��Ԃ�)
	bool res = solve(i + 1, m) || solve(i + 1, m - A[i]);
	return res;
}