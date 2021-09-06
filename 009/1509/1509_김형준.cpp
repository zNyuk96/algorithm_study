#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

string str;
int pal[2500][2500];
int DP[2500];

int isPal(int s, int e) {
	const int len = e - s + 1;
	if (len <= 1) return 1;
	if (len == 2) return str[s] == str[e];
	return str[s] == str[e] && isPal(s + 1, e - 1);
}

void run() {
    // 시간초과
	for (int i = 0; i < str.length(); i++)
		for (int j = i; j < str.length(); j++)
			pal[i][j] = isPal(i, j); // i~j까지의 문자열이 회문인지 확인

	for (int End = 0; End < str.length(); End++)
	{
		DP[End] = 1e9;
		for (int Start = 0; Start <= End; Start++)
			if (pal[Start][End])
				if (DP[End] > (Start ? DP[Start - 1] + 1 : 1))
					DP[End] = (Start ? DP[Start - 1] + 1 : 1);
	}
}

int main() {
	cin >> str;
	run();
	cout << DP[str.length() - 1] << endl;

	return 0;
}