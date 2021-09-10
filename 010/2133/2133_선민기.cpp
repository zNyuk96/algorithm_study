#include<iostream>

using namespace std;

int main() {
	int acc = 1, past = 1, n, calc;

	cin >> n;

	if (n % 2 == 0) {
		for (int i = 0; i < n; i += 2) {
			past = calc = acc * 2 + past;
			acc += calc;
		}
	}
	else
		past = 0;

	cout << past << endl;
}