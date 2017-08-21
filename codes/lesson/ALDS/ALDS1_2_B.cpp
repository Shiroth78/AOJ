//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_B&lang=jp
#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 100;

int selectionSort(int A[], int N);

int main(void) {
	int A[MAX], N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int steps = selectionSort(A, N);

	for (int i = 0; i < N; i++) {
		if (i > 0) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << steps << endl;
}

int selectionSort(int A[], int N) {
	int steps = 0;
	for (int i = 0; i < N; i++) {
		int minj = i;
		for (int j = i; j < N; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		int tmp = A[i];
		A[i] = A[minj];
		A[minj] = tmp;
		if (i != minj)steps++;
	}	
	return steps;
}