#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MIN(a,b) (a < b ? a : b)
#define MAX(a,b) (a > b ? a : b)
#define MAX_N 50000

int N, M;
int max_level;
vector<vector<int>> graph, ac;
vector<int> depth, visited;

void run(int now, int level) {
	visited[now] = true;
	depth[now] = level;

	for (int next : graph[now])
	{
		if (visited[next]) continue;
		ac[next][0] = now;
		run(next, level + 1);
	}

	if (level) return;

	for (int j = 1; j <= max_level; j++)
		for (int i = 1; i <= N; i++)
			ac[i][j] = ac[ac[i][j - 1]][j - 1];
}

int findLCA(int a, int b)
{
	for (int i = max_level; i >= 0; i--)
		if (depth[b] - depth[a] >= (1 << i))
			b = ac[b][i];

	if (a == b) return a;

	for (int i = max_level; i >= 0; i--)
		if (ac[a][i] != ac[b][i])
		{
			a = ac[a][i];
			b = ac[b][i];
		}

	return ac[a][0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	max_level = (int)floor(log2(MAX_N));

	graph = vector<vector<int>>(N + 1);
	ac = vector<vector<int>>(N + 1);
	depth = vector<int>(N + 1);
	visited = vector<int>(N + 1);

	for (int i = 0; i <= N; i++)
		ac[i] = vector<int>(max_level + 1);

	for (int i = 0, a, b; i < N - 1; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	run(1, 0);

	cin >> M;

	for (int i = 0, a, b; i < M; i++)
	{
		cin >> a >> b;
		cout << findLCA(MIN(a, b), MAX(a, b)) << "\n";
	}

	return 0;
}