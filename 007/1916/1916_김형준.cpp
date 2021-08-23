#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, M;
int S, E;
vector<vector<pair<int,int>>> graph;
int d[1000];

int main() {
	fill(d, d + 1000, INF);

	cin >> N;
	cin >> M;

	graph = vector<vector<pair<int, int>>>(1000);

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		graph[a].push_back({ b, c });

	}

	cin >> S >> E;
	S--;
	E--;

	priority_queue<pair<int, int>> q;

	q.push({ S, 0 });
	d[S] = 0;

	while (!q.empty())
	{
		int now = q.top().first;
		int distance = q.top().second;
		q.pop();

		if (d[now] < distance) continue;

		for (int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i].first;
			int nextDistance = distance + graph[now][i].second;

			if (nextDistance < d[next])
			{
				d[next] = nextDistance;
				q.push({ next, nextDistance });
			}
		}
	}

	cout << d[E];

	return 0;
}