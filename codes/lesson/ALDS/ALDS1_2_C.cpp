//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_C&lang=jp
#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 36;

struct Card {
	char suit;
	int value;
};

void BubbleSort(struct Card C[], int N);
void SelectionSort(struct Card C[], int N);
void PrintCard(struct Card C[], int N);
bool isStable(struct Card C1[], struct Card C2[], int N);


int main(void) {
	struct Card C1[MAX], C2[MAX];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> C1[i].suit >> C1[i].value;
	}
	for (int i = 0; i < N; i++) C2[i] = C1[i];

	BubbleSort(C1, N);
	cout << "Stable" << endl; //バブルソートは常に安定ソート
	SelectionSort(C2, N);
	//バブルソートと比較することで安定かどうか判定
	if (isStable(C1, C2, N) == true) {
		cout << "Stable" << endl;
	} else {
		cout << "Not stable" << endl;
	}
}

void BubbleSort(struct Card C[], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j > i; j--) {
			if (C[j].value < C[j - 1].value) {
				struct Card tmp;
				tmp = C[j];
				C[j] = C[j - 1];
				C[j - 1] = tmp;
				}
		}
	}
	PrintCard(C,N);
}

void SelectionSort(struct Card C[], int N) {
	for (int i = 0; i < N; i++) {
		int minj = i;
		for (int j = i; j < N; j++) {
			if (C[j].value < C[minj].value) {
				minj = j;
			}
		}
		struct Card tmp;
		tmp = C[i];
		C[i] = C[minj];
		C[minj] = tmp;
	}
	PrintCard(C,N);
}

void PrintCard(struct Card C[], int N) {
	//int N = (sizeof C) / (sizeof(struct Card));
	for (int i = 0; i < N; i++) {
		if (i > 0) cout << " ";
		cout << C[i].suit<<C[i].value;
	}
	cout << endl;
}

bool isStable(struct Card C1[], struct Card C2[], int N) {
	//int N = (sizeof C1) / (sizeof(struct Card));
	for (int i = 0; i < N; i++) {
		if (C1[i].suit != C2[i].suit) return false;
	}
	return true;
}