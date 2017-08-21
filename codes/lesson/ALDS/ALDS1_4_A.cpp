//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_A&lang=jp
#include <iostream>
using namespace std;
static const int MAX = 10000;
int S[MAX], T[MAX];
int n, m;

bool linearSearch(int j);

int main(void) {
	int ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> S[i];
	}
	cin >> m;
	for (int j = 0; j < m; j++) {
		cin >> T[j];
	}

	for (int j = 0; j < m; j++) {
		if (linearSearch(j)) ans++;
	}
	cout << ans << endl;
}

bool linearSearch(int j) {
	int i = 0;
	S[n] = T[j];
	while (S[i] != T[j]) {
		i++;
		if (i == n) return false;
	}
	return true;
}
