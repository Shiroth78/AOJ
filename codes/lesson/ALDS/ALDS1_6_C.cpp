//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_C&lang=jp
#include <iostream>
#include <algorithm>
using namespace std;
#define INFTY 10000000000; //ソートの要素が<=10^9なのでそれ以上で設定

struct Card {
	char suit;
	int value;

	//オーバーロード演算子で構造体比較
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

	/*バブルソートも安定なソートだが、計算量がO(N^2)なので、
	より高速なマージソート（計算量O(nlogn)）と比較する*/
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
	int i = p - 1; //小さい値の最後のインデックス
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
	//既にソートされた2つのリストを結合
	int n1 = mid - left;
	int n2 = right - mid;
	Card *L, *R;
	L = new Card[n1 + 1]; //配列の動的確保
	R = new Card[n2 + 1];
	for (int i = 0; i < n1; i++) {
		L[i] = A[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = A[mid + i];
	}
	L[n1].value = INFTY;//番兵設定
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
	delete[] L; //メモリ開放する
	delete[] R;
	//printList(A,left, right);
}

void mergeSort(struct Card *A, int left, int right) {
	//左右に分割して再帰(要素が1つになるまで分割してそこから結合する)
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