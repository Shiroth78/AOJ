//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_B&lang=jp

#include <iostream>
using namespace std;
static const int MAX = 5000; //���ł�500000�܂ł��邪�A�茳�̊��ŃN���b�V�������̂ŏ���������
#define INFTY 10000000000; //�\�[�g�̗v�f��<=10^9�Ȃ̂ł���ȏ�Őݒ�

void merge(int A[], int left, int mid, int right);
void mergeSort(int A[], int left, int right);
void printList(int A[], int s,int f);

int num = 0;

int main(void) {
	int n;
	int A[MAX];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	mergeSort(A, 0, n);

	printList(A, 0, n);
}


void merge(int A[],int left,int mid,int right){
	//���Ƀ\�[�g���ꂽ2�̃��X�g������
	int n1 = mid - left;
	int n2 = right - mid;
	int *L, *R;
	L = new int[n1+1]; //�z��̓��I�m��
	R = new int[n2+1];
	for (int i = 0; i < n1; i++) {
		L[i] = A[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = A[mid + i];
	}
	L[n1] = INFTY;//�ԕ��ݒ�
	R[n2] = INFTY;
	//printList(L, 0, n1+1);
	int i = 0;
	int j = 0;
	for (int k = left; k < right; k++) {
		if (L[i] > R[j]) {
			A[k] = R[j];
			j++;
		}else{
			A[k] = L[i];
			i++;
		}
		num++;
	}
	delete[] L; //�������J������
	delete[] R;
	//printList(A,left, right);
}

void mergeSort(int A[], int left, int right) {
	//���E�ɕ������čċA(�v�f��1�ɂȂ�܂ŕ������Ă������猋������)
	int mid;
	if (left + 1 < right) {
		mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

void printList(int A[], int s, int f) {
	for (int i = s; i < f; i++) {
		if (i != s) cout << " ";
		cout << A[i];
	}
	cout << endl;

	cout << num << endl;
}