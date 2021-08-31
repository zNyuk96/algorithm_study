#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int graph[1000][1000];
vector<int> adj[1000];
priority_queue<int> path[1000];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL); 

	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[--a][--b] = c;
		adj[a].push_back(b);
	}

	priority_queue<pair<int,int>> q;
	q.push(make_pair(0, 0));
	path[0].push(0);

	while (!q.empty())
	{
		int now = q.top().first;
		int distance = q.top().second;
		q.pop();

		for (int next : adj[now])
		{
			int cost = graph[now][next] + distance;

			// 정답 참고
			if (path[next].size() < K)
			{
				path[next].push(cost);
				q.push(make_pair(next, cost));
			}
			else if (path[next].top() > cost)
			{
				path[next].pop();
				path[next].push(cost);
				q.push(make_pair(next, cost));
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (path[i].size() < K) cout << "-1\n";
		else cout << path[i].top() << "\n";
	}

	return 0;
}