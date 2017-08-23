//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_C&lang=jp

#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

struct Pos {
	double x;
	double y;
};

void kock(int n, Pos p1, Pos p2);

int main(void) {
	int n;
	cin >> n;
	struct Pos p1 = { 0.0,0.0 };
	struct Pos p2 = { 100.0,0.0 };

	cout << p1.x << " " << p1.y << endl;
	kock(n, p1, p2);
	cout << p2.x << " " << p2.y << endl;

}


void kock(int n, Pos p1, Pos p2) {
	if (n == 0) return;
	//コッホ曲線の新たな3点を計算
	struct Pos s, u, t;
	s.x = (2 * p1.x + p2.x) / 3;
	s.y = (2 * p1.y + p2.y) / 3;
	t.x = (p1.x + 2 * p2.x) / 3;
	t.y = (p1.y + 2 * p2.y) / 3;
	u.x = s.x + (t.x - s.x)*cos(M_PI / 3) - (t.y - s.y)*sin(M_PI / 3);
	u.y = s.y + (t.x - s.x)*sin(M_PI / 3) + (t.y - s.y)*cos(M_PI / 3);

	kock(n - 1, p1, s);
	cout << s.x << " " << s.y << endl;
	kock(n - 1, s, u);
	cout << u.x << " " << u.y << endl;
	kock(n - 1, u, t);
	cout << t.x << " " << t.y << endl;
	kock(n - 1, t, p2);
}
