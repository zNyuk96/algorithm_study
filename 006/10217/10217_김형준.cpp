#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
#define NUM_AIRPORT 100
using namespace std;

vector<vector<int>> graph_data;
int cost_data[NUM_AIRPORT + 1][NUM_AIRPORT + 1];
int time_data[NUM_AIRPORT + 1][NUM_AIRPORT + 1];
int min_cost[NUM_AIRPORT + 1];
int min_time[NUM_AIRPORT + 1];

int N, M, K;
int start, goal;

void run()
{
	priority_queue<pair<int, pair<int, int>>> q;

	q.push({ start, { 0, 0 } });
	min_cost[start] = 0;
	min_time[start] = 0;

	while (!q.empty())
	{
		int now = q.top().first;
		int cost_now = q.top().second.first;
		int time_now = q.top().second.second;
		q.pop();

		if (M < cost_now) continue;
		if (min_time[now] < time_now) continue;

		for (int i = 0; i < graph_data[now].size(); i++)
		{
			int next = graph_data[now][i];
			int cost_next = cost_now + cost_data[now][next];
			int time_next = time_now + time_data[now][next];

			if (time_next < min_time[next])
			{
				min_cost[next] = cost_next;
				min_time[next] = time_next;
				q.push({ next, { cost_next, time_next } });
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N >> M >> K;

		start = 1;
		goal = N;

		graph_data = vector<vector<int>>(N + 1);

		fill(min_cost, min_cost + NUM_AIRPORT + 1, INF);
		fill(min_time, min_time + NUM_AIRPORT + 1, INF);

		for (int j = 0; j < K; j++)
		{
			int u, v, c, d;
			cin >> u >> v >> c >> d;

			graph_data[u].push_back(v);
			cost_data[u][v] = c;
			time_data[u][v] = d;
		}

		run();

		if (min_cost[goal] <= M && min_time[goal] != INF)
			cout << min_time[goal] << endl;
		else
			cout << "Poor KCM" << endl;
	}

	return 0;
}