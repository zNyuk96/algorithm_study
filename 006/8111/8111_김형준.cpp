#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// 아이디어는 대충 생각이 났으나 구현력이 부족.. 이대로 가면 호출 스택 오버플로우

int arr[1000];
string result[20000];

void run(int unit, int value, int level)
{
	for (int i = 1; i < 10; i++)
	{
		int nVal = unit * i;
		if (nVal % 10 != 0 && nVal % 10 != 1) continue;
		run(unit, nVal / 10, level + 1);
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
		cin >> arr[i];

	for (int i = 0; i < T; i++)
	{
		int unit = arr[i];
		run(unit, 0, 0);
	}
}