//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_A&lang=jp

#include <iostream>
using namespace std;

void countingSort(int *A, int *B, int k);
void printList(int A[], int n);

int n = 0;

int main(void) {
	int *A, *B;
	int k = 0;
	cin >> n;
	A = new int[n];
	B = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		//B[i] = 0;
		if (k < A[i]) k = A[i];
	}
	//cout << k << endl;
	countingSort(A, B, k);
	printList(B, n);
	delete[] A;
	delete[] B;
}


void countingSort(int *A, int *B, int k) {
	int *C;
	C = new int[k+1];

	//������
	for (int i = 0; i < k+1; i++) {
		C[i] = 0;
	}

	//C[i] �� i �̏o�������L�^����
	for (int j = 0; j < n; j++) {
		C[A[j]]++;
	}
	//printList(C, k + 1);

	//C[i] �� i �ȉ��̐��̏o�������L�^����(�݌v�a)
	for (int i = 1; i < k+1; i++) {
		C[i] = C[i] + C[i - 1];
	}
	//printList(C, k + 1);

	//���X�g�̌�납����ׂ�
	for (int j = n-1; j >= 0; j--) {
		B[C[A[j]]-1] = A[j]; //B��0�n�܂�ł��邱�Ƃɒ���
		C[A[j]]--;
	}
	//printList(B, n);

	delete[] C;
}

void printList(int A[], int n) {
	for (int i = 0; i < n; i++) {
		if (i != 0) cout << " ";
		cout << A[i];
	}
	cout << endl;
}