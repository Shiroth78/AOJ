//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_B&lang=jp

#include <iostream>
using namespace std;
static const int MAX = 100000;

struct Process {
	char name[10];
	int time;
};

int head, tail; //リングバッファ想定
int q; //クォンタム
struct Process Q[MAX];
int ptime = 0; //処理時間

void initialize(void);
bool isEmpty(void);
bool isFull(void);
void enqueue(struct Process x);
struct Process dequeue(void);
void Rrs(void); //ラウンドロビンスケジューリング


int main(void) {
	int n;
	cin >> n >> q;
	initialize(); //バッファ初期化
	//データ取得
	for (int i = 0; i < n; i++) {
		cin >> Q[tail].name >> Q[tail].time;
		tail++;
	}

	while (!isEmpty()) {
		Rrs();
		//cout << head << " " << tail << endl;
	}
}


void initialize() {
	head = tail = 0;
}

bool isEmpty() {
	//head==tailなら空
	return head == tail; 
}

bool isFull() {
	//headの1つ前がtailなら満杯
	return head == (tail + 1) % MAX;
}

void enqueue(struct Process x) {
	if (isFull()) {
		cout << "error(overflow)" << endl;
	}

	Q[tail] = x;
	if (tail + 1 == MAX) tail = 0;
	else tail++;
}

struct Process dequeue() {
	if (isEmpty()) {
		cout << "error(overflow)" << endl;
	}
	struct Process x = Q[head];
	if (head + 1 == MAX) head = 0;
	else head++;
	return x;
}

void Rrs() {
	struct Process x = dequeue();
	if (x.time <= q) {
		ptime += x.time;
		cout << x.name << " " <<  ptime << endl;
	}
	else {
		x.time -= q;
		ptime += q;
		enqueue(x);
	}
}