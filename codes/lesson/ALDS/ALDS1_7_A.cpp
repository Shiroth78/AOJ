//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_7_A&lang=jp
#include <iostream>
using namespace std;
static const int MAX = 100000;
static const int NIL = -1; //節点が存在しないことを示す

//左子右兄弟表現
struct Node {
	int parent; //親（無ければ根）
	int left;   //左子（無ければ葉）
	int right;  //右兄弟（無ければ最も右の子）
};
struct Node T[MAX];
int n, D[MAX];

//int getDepth(int);
void setDepth(int, int);
void printType(int);
void printChildren(int);
void printInfo(int);

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		T[i].parent = NIL;
		T[i].left = NIL;
		T[i].right = NIL;
	}

	int id, k, child;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> id >> k;
		for (int j = 0; j < k; j++) {
			//kの先頭を左子にし、それ以外を左子の右兄弟とする
			cin >> child;
			if (j == 0) T[id].left = child;
			else T[tmp].right = child;
			tmp = child;
			T[child].parent = id;
		}
	}
	for (int i = 0; i < n; i++) {
		if (T[i].parent == NIL) {
			setDepth(i, 0);
		}
	}

	for (int u = 0; u < n; u++) printInfo(u);

}

/*
//uの深さを返す
int getDepth(int u) {
	int d = 0;
	while (T[u].parent != NIL) {
		u = T[u].parent;
		d++;
	}
	return d;
}
*/

//u以下の深さを再帰的に設定
void setDepth(int u, int p) {
	D[u] = p;
	if (T[u].right != NIL) {
		//右兄弟は深さが同じ
		setDepth(T[u].right, p);
	}
	if (T[u].left != NIL) {
		//左子は深さが１深い
		setDepth(T[u].left, p + 1);
	}
}

void printType(int u) {
	if (T[u].parent == NIL) {
		cout << "root";
		return;
	}
	if (T[u].left == NIL) {
		cout << "leaf";
		return;
	}
	cout << "internal node";
}

void printChildren(int u) {
	int c = T[u].left;
	while (c != NIL) {
		if (c != T[u].left) cout << ", ";
		cout << c;
		c = T[c].right;
	}
}

void printInfo(int u) {
	//node id : parent = p, depth = d, type, [c1...ck]の形で出力
	cout << "node " << u << ": ";
	cout << "parent = " << T[u].parent << ", ";
	cout << "depth = " << D[u] << ", ";
	printType(u);  cout << ", ";
	cout << "["; printChildren(u); cout << "]";
	cout << endl;
}