//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_A&lang=jp

#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 100;

int bubbleSort(int A[], int N);
void output(int A[],int N, int steps);

int main(void) {
	int A[MAX], N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int steps = bubbleSort(A, N);
	output(A, N, steps);
}

int bubbleSort(int A[], int N) {
	int steps = 0; //ƒ\[ƒg‰ñ”
	int flag = 1; // ‹t‚Ì—×Ú—v‘f‚ª‘¶Ý‚·‚é
	while (flag) {
		flag = 0;
		for (int j = N - 1; j > 0; j--) {
			if (A[j] < A[j - 1]) {
				int tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
				flag = 1;
				steps++;
			}
		}
	}
	return steps;
}

void output(int A[], int N, int steps) {
	for (int i = 0; i < N; i++) {
		if (i > 0) cout << " ";
		cout << A[i];
	}
	cout << endl;

	cout << steps << endl;

}