#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int graph[1000][1000];
int d[1000];
int p[1000];

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cin >> graph[--a][--b];
		graph[b][a] = graph[a][b];
	}

	fill(d, d + 1000, 1e9);

	priority_queue<pair<int,int>> q;
	q.push({ 0, 0 });
	d[0] = 0;

	while (!q.empty())
	{
		int now = q.top().first;
		int distance = q.top().second;
		q.pop();

		if (d[now] < distance) continue;

		for (int next = 0; next < N; next++)
		{
			if (!graph[now][next]) continue;
			int cost = graph[now][next] + distance;

			if (cost < d[next])
			{
				d[next] = cost;
				p[next] = now;
				q.push({ next, cost });
			}
		}
	}

	cout << N - 1 << endl;
	for (int i = 1; i < N; i++)
		cout << p[i]+1 << " " << i+1 << endl;

	return 0;
}