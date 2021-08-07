#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int rice_cake_count[1000];
vector<vector<int>> rice_cake(1000);
int N;
int path[1000];
int success = 0;
int success_path[1000];

void run(int level)
{
	if (success) return;

	if (level == N) {
		success = 1;
		memcpy(success_path, path, sizeof(int) * 1000);
		return;
	}

	for (int i = 0; i < rice_cake_count[level]; i++)
	{
		int x = rice_cake[level][i];
		if (level != 0 && x == path[level - 1]) continue;
		path[level] = x;
		run(level + 1);
		path[level] = 0;
	}
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
	
	run(0);

	if (success)
		for (int i = 0; i < 1000; i++)
		{
			if (!success_path[i]) break;
			cout << success_path[i] << "\n";
		}
	else
		cout << -1 << "\n";

	return 0;
}