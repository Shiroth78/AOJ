//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_A&lang=jp

#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
//#include <algorithm>
using namespace std;
static const int MAX = 200; //‹L†‚Æ”š‚ ‚í‚¹‚Ä199
int top, S[MAX];

void push(int x);
int pop(void);

int main(void) {
	top = 0;
	int a, b;

	vector<string> s;
	string line;
	if (getline(cin, line)) {
		istringstream ss(line);
		copy(istream_iterator<string>(ss), istream_iterator<string>(), back_inserter(s));
	}
	// “ü—Í‚³‚ê‚½“à—e‚ğ•\¦
	//copy(s.begin(), s.end(), ostream_iterator<string>(cout, ", "));

	size_t size = s.size();
	for (size_t i = 0; i < size; i++){
		if (s[i] == "+") {
			b = pop(); //æ‚Épop‚·‚é‚Ì‚Íb‚È‚Ì‚É’ˆÓ
			a = pop();
			push(a + b);
		}
		else if (s[i] == "-") {
			b = pop();
			a = pop();
			push(a - b);
		}
		else if (s[i] == "*") {
			b = pop();
			a = pop();
			push(a*b);
		}
		else {
			push(stoi(s[i])); //C++11ˆÈ~‚Ì‚İ
		}
		//cout << s[i] << endl;
	}
	cout << S[1] << endl;
}

void push(int x) {
	S[++top] = x;
}

int pop(void) {
	top--;
	return S[top + 1];
}