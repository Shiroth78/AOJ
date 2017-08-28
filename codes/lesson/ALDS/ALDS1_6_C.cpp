//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_C&lang=jp
#include <iostream>
#include <algorithm>
using namespace std;
#define INFTY 10000000000; //�\�[�g�̗v�f��<=10^9�Ȃ̂ł���ȏ�Őݒ�

struct Card {
	char suit;
	int value;

	//�I�[�o�[���[�h���Z�q�ō\���̔�r
	bool operator != (const Card obj)const{
		if (suit != obj.suit || value != obj.value) return true;
		else return false;
	}
};

int partition(struct Card *A, int p, int r);
void quickSort(struct Card *A, int p, int r);
void merge(struct Card *A, int left, int mid, int right);
void mergeSort(struct Card *A, int left, int right);
bool isStable(struct Card *C1, struct Card *C2, int N);
void PrintCard(struct Card *C, int N);

int main(void) {
	int n;
	Card *A, *B;

	cin >> n;
	A = new Card[n];
	B = new Card[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i].suit >> A[i].value;
		B[i] = A[i];
	}

	/*�o�u���\�[�g������ȃ\�[�g�����A�v�Z�ʂ�O(N^2)�Ȃ̂ŁA
	��荂���ȃ}�[�W�\�[�g�i�v�Z��O(nlogn)�j�Ɣ�r����*/
	quickSort(A, 0, n - 1);
	mergeSort(B, 0, n);

	if (isStable(A, B, n)) {
		cout << "Stable" << endl;
	} else{
		cout << "Not stable" << endl;
	}
	PrintCard(A, n);
	delete[] A;
	delete[] B;
}

int partition(struct Card *A, int p, int r) {
	int x = A[r].value;
	int i = p - 1; //�������l�̍Ō�̃C���f�b�N�X
	struct Card tmp;
	for (int j = p; j<r; j++) {
		if (A[j].value <= x) {
			i = i + 1;
			tmp = A[i]; A[i] = A[j]; A[j] = tmp;
		}
	}
	tmp = A[i + 1]; A[i + 1] = A[r]; A[r] = tmp;
	return i + 1;
}

void quickSort(struct Card *A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

void merge(struct Card *A, int left, int mid, int right) {
	//���Ƀ\�[�g���ꂽ2�̃��X�g������
	int n1 = mid - left;
	int n2 = right - mid;
	Card *L, *R;
	L = new Card[n1 + 1]; //�z��̓��I�m��
	R = new Card[n2 + 1];
	for (int i = 0; i < n1; i++) {
		L[i] = A[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = A[mid + i];
	}
	L[n1].value = INFTY;//�ԕ��ݒ�
	R[n2].value = INFTY;
	//printList(L, 0, n1+1);
	int i = 0;
	int j = 0;
	int num = 0;
	for (int k = left; k < right; k++) {
		if (L[i].value > R[j].value) {
			A[k] = R[j];
			j++;
		}
		else {
			A[k] = L[i];
			i++;
		}
		num++;
	}
	delete[] L; //�������J������
	delete[] R;
	//printList(A,left, right);
}

void mergeSort(struct Card *A, int left, int right) {
	//���E�ɕ������čċA(�v�f��1�ɂȂ�܂ŕ������Ă������猋������)
	int mid;
	if (left + 1 < right) {
		mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

bool isStable(struct Card *C1, struct Card *C2, int N) {
	for (int i = 0; i < N; i++) {
		if (C1[i] != C2[i]) return false;
	}
	return true;
}

void PrintCard(struct Card *C, int N) {
	for (int i = 0; i < N; i++) {
		cout << C[i].suit << " " << C[i].value << endl;
	}
}