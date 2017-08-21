//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_A&lang=jp

#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 100;

void insertionSort(int A[], int N);

int main(void) {
	int A[MAX], N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (i > 0) cout << " ";
		cout << A[i];
	}
	cout << endl;

	insertionSort(A, N);
}

void insertionSort(int A[], int N) {

	for (int i = 1; i < N; i++) {
		int v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j -= 1;
		}
		A[j + 1] = v;
		
		for (int i = 0; i < N; i++) {
			if (i > 0) cout << " ";
			cout << A[i];
		}
		cout << endl;
	}
}