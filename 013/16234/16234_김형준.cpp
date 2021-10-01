#include <iostream>
#include <queue>
using namespace std;

#define HORIZONTAL 0
#define VERTICAL 1
#define ABS(a,b) (a - b > 0 ? a - b : b - a)

int map[50][50];
int group[50][50];
int groupCnt[50][50];

int N, L, R;
int T = 0;

int isHorizontalOpen(int y, int lx, int rx)
{
	int l = map[y][lx];
	int r = map[y][rx];
	int d = ABS(l, r);

	return d >= L && d <= R;
}

int isVerticalOpen(int x, int ty, int by)
{
	int t = map[ty][x];
	int b = map[by][x];
	int d = ABS(t, b);

	return d >= L && d <= R;
}

int findBoss(int y, int x)
{
	return group[y][x] == N * y + x ? N * y + x : findBoss(group[y][x] / N, group[y][x] % N);
}

int setUnion(int y1, int x1, int y2, int x2)
{
	int aBoss = findBoss(y1, x1);
	int bBoss = findBoss(y2, x2);
	if (aBoss == bBoss) return 0;

	group[bBoss / N][bBoss % N] = aBoss;

	groupCnt[aBoss / N][aBoss % N] += groupCnt[bBoss / N][bBoss % N];
	groupCnt[bBoss / N][bBoss % N] = 0;

	map[aBoss / N][aBoss % N] += map[bBoss / N][bBoss % N];
	map[bBoss / N][bBoss % N] = 0;
	return 1;
}

int main() {
	cin >> N >> L >> R;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> map[y][x];

	while (T <= 2000)
	{
		queue<pair<pair<int, int>, pair<int, int>>> unions;

		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
			{
				group[y][x] = N * y + x;
				groupCnt[y][x] = 1;
			}	

		for (int type = 0; type < 2; type++)
			for (int y = 0; y < (type == HORIZONTAL ? N : N - 1); y++)
				for (int x = 0; x < (type == VERTICAL ? N : N - 1); x++)
				{
					if (type == HORIZONTAL)
					{
						if (isHorizontalOpen(y, x, x + 1)) unions.push({ {y, x}, {y, x + 1} });
					}
					else if (type == VERTICAL) 
					{
						if (isVerticalOpen(x, y, y + 1)) unions.push({ {y, x}, {y + 1, x} });
					}
				}

		if (unions.empty()) break;
		while (!unions.empty())
		{
			int y1 = unions.front().first.first;
			int x1 = unions.front().first.second;
			int y2 = unions.front().second.first;
			int x2 = unions.front().second.second;
			unions.pop();
			setUnion(y1, x1, y2, x2);
		}

		queue<pair<int, int>> bosses;

		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				if (map[y][x]) bosses.push({ y,x });

		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
			{
				if (map[y][x]) continue;
				int boss = findBoss(y, x);
				int yBoss = boss / N;
				int xBoss = boss % N;
				map[y][x] = map[yBoss][xBoss] / groupCnt[yBoss][xBoss];
			}

		while (!bosses.empty())
		{
			int y = bosses.front().first;
			int x = bosses.front().second;
			bosses.pop();
			map[y][x] /= groupCnt[y][x];
		}

		T++;
	}

	cout << T;

	return 0;
}