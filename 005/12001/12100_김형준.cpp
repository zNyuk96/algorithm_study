#include <iostream>
#include <vector>
#include <algorithm>
#define MOVE_LEFT 0
#define MOVE_RIGHT 1
#define MOVE_UP 2
#define MOVE_DOWN 3
#define IS_HORIZONTAL i < 2
#define IS_VERTICAL i >= 2
using namespace std;
int N;
int map[20][20];
int maximum = 0;

void run(int level) {
	if (level == 5) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				maximum = max(maximum, map[i][j]);

		return;
	}

	for (int i = 0; i < 4; i++) {
		int prev_map[20][20];

		// 맵 백업
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				prev_map[y][x] = map[y][x];

		// 2048
		for (int y = 0; y < N; y++) {
			vector<int> temp;
			vector<int> perm;

			for (int x = 0; x < N; x++)
				if ((IS_HORIZONTAL ? map[y][x] : map[x][y]) != 0)
					temp.push_back(IS_HORIZONTAL ? map[y][x] : map[x][y]);
			
			if (i == MOVE_RIGHT || i == MOVE_DOWN)
				reverse(temp.begin(), temp.end());

			for (int x = 0; x < temp.size(); x++)
				if (x + 1 < temp.size() && temp[x] == temp[x + 1]) {
					// 둘이 합치고 다다음 셀
					perm.push_back(temp[x] * 2);
					x++;
				}
				else
				{
					// 안 합쳐지면 다음 셀
					perm.push_back(temp[x]);
				}
			
			for (int x = perm.size(); x < N; x++)
				perm.push_back(0);

			if (i == MOVE_RIGHT || i == MOVE_DOWN)
				reverse(perm.begin(), perm.end());

			for (int x = 0; x < N; x++)
				(IS_HORIZONTAL ? map[y][x] : map[x][y]) = perm[x];
		}

		run(level + 1);

		// 맵 복구
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				map[j][k] = prev_map[j][k];
	}
}
int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	run(0);
	cout << maximum;

	return 0;
}