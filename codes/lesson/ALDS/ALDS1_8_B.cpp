//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_B

#include <iostream>
#include <stdlib.h>
using namespace std;
static const int MAX = 500000;
static const int NIL = -1;

struct Node {
	int key;
	Node* parent;
	Node* left;
	Node* right;
};

Node* makeNode(int);
Node* insert(Node*, Node*);
void find(Node*, int);
void inorderTreeWalk(Node*);
void preorderTreeWalk(Node*);
void print(Node*);


int main(void) {
	int n;
	char order[8];
	int num;
	Node *T = (Node*)malloc(sizeof(Node));
	T = makeNode(NIL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> order;
		if (order[0] == 'i') {
			cin >> num;
			Node *z = (Node*)malloc(sizeof(Node));
			z = makeNode(num);
			T = insert(T, z);
		}
		else if (order[0] == 'f') {
			cin >> num;
			find(T, num);
		}
		else if (order[0] == 'p') {
			print(T);
		}
	}
}

//�߂̐���
Node* makeNode(int v) {
	Node *n = (Node*)malloc(sizeof(Node));
	if (n != NULL) {
		n->key = v;
		n->parent = NULL;
		n->left = NULL;
		n->right = NULL;
	}
	return n;
}


//�񕪒T����T�ɐV���ɒlv��}��
Node* insert(Node* T, Node* z) {
	Node* y = NULL; //x�̐e;
	Node* x = T;
	while (x != NULL) {
		y = x; //�e��ݒ�
		if (z->key < x->key) {
			x = x->left; //���̎q�ֈړ�
		}
		else {
			x = x->right; //�E�̎q�ֈړ�
		}
	}
	z->parent = y;

	if (y->key == NIL) { //T����̏ꍇ
		T = z;
	}
	else if (z->key < y->key) {
		y->left = z; //z��y�̍��̎q�ɂ���
	}
	else {
		y->right = z; //z��y�̉E�̎q�ɂ���
	}
	return T;
}

void find(Node* T, int key) {
	Node* x = T;
	while (x != NULL) {
		if (x->key == key) {
			cout << "yes" << endl;
			return;
		}
		else if (key < x->key) {
			x = x->left; //���̎q�ֈړ�
		}
		else {
			x = x->right; //�E�̎q�ֈړ�
		}
	}
	cout << "no" << endl;
}


void inorderTreeWalk(Node* n) {
	if (n != NULL) {
		inorderTreeWalk(n->left);
		cout << " " << n->key;
		inorderTreeWalk(n->right);
	}
}

void preorderTreeWalk(Node* n) {
	if (n != NULL) {
		cout << " " << n->key;
		preorderTreeWalk(n->left);
		preorderTreeWalk(n->right);
	}
}

void print(Node* n) {
	inorderTreeWalk(n);
	cout << endl;
	preorderTreeWalk(n);
	cout << endl;
}