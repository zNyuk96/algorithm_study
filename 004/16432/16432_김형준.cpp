#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int rice_cake_count[1000];
vector<vector<int>> rice_cake(1000);
int N;
int path[1000][10] = { -1 };
int success = 0;

int run(int level, int prev)
{
	if (success) return 1;

	if (level == N) {
		success = 1;
		return 1;
	}

	if (level == 0)
	{
		for (int i = 0; i < rice_cake_count[level]; i++)
		{
			int x = rice_cake[level][i];
			path[0][0] = x;
			if (run(level + 1, x)) return 1;
		}
	} else if (path[level][prev] == -1) {
		for (int i = 0; i < rice_cake_count[level]; i++)
		{
			int x = rice_cake[level][i];
			if (x == prev) continue;
			path[level][prev] = x;
			if (run(level + 1, x)) return 1;
		}
	}
	else
	{
		run(level + 1, path[level][prev]); 
	}

	return 0;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int M;
		cin >> M;
		rice_cake_count[i] = M;

		for (int j = 0; j < M; j++)
		{
			int a;
			cin >> a;
			rice_cake[i].push_back(a);
		}
	}
	
	memset(path, -1, sizeof(int) * 1000 * 10);
	
	run(0, -1);

	if (success)
	{
		int prev = 0;

		for (int i = 0; i < N; i++)
		{
			cout << path[i][prev] << "\n";
			prev = path[i][prev];
		}
	}
	else
		cout << -1 << "\n";

	return 0;
}