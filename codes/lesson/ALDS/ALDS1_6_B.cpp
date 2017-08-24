//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_B&lang=jp
#include <iostream>
using namespace std;

int partition(int *A, int p, int r);

int main(void) {
	int n;
	int *A;

	cin >> n;
	A = new int[n];
	for (int i = 0; i<n; i++) {
		cin >> A[i];
	}
	int index;
	index = partition(A, 0, n - 1);

	for (int i = 0; i < n; i++) {
		if (i != 0) cout << " ";
		if (i == index) cout << "[";
		cout << A[i];
		if (i == index) cout << "]";
	}
	cout << endl;
	delete[] A;
}


int partition(int *A, int p, int r) {
	int x = A[r];
	int i = p - 1; //小さい値の最後のインデックス
	int tmp;
	for (int j = p; j<r; j++) {
		if (A[j] <= x) {
			i = i + 1;
			tmp = A[i]; A[i] = A[j]; A[j] = tmp;
		}
	}
	tmp = A[i + 1]; A[i + 1] = A[r]; A[r] = tmp;
	return i + 1;
}