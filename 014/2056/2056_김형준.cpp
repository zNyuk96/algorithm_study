#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> indegree;
vector<int> weight;
vector<int> etime;

int main() {
	int N;
	cin >> N;

	graph = vector<vector<int>>(N);
	weight = vector<int>(N);
	etime = vector<int>(N);
	indegree = vector<int>(N);

	for (int i = 0; i < N; i++)
	{
		int W, M;
		cin >> W >> M;

		weight[i] = W;
		indegree[i] = M;

		graph[i] = vector<int>();
		for (int j = 0, x; j < M; j++)
		{
			cin >> x;
			graph[x - 1].push_back(i);
		}
	}

	queue<int> q;

	for (int i = 0; i < N; i++)
		if (!indegree[i]) { q.push(i); etime[i] = weight[i]; }

	int T = 0;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int next : graph[now])
		{
			if (!--indegree[next]) q.push(next);
			etime[next] = max(etime[next], etime[now] + weight[next]);
		}	
	}

	for (int i = 0; i < N; i++)
		T = max(T, etime[i]);

	cout << T;

	return 0;
}