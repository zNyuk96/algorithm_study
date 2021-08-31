#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, long long>> roads[1000];
long long d[1000];
vector<long long> taxes = { 0 };

int main() {
	int N, M, K;
	int S, D;
	cin >> N >> M >> K;
	cin >> S >> D;

	for (int a, b, w, i = 0; i < M; i++) { 
		cin >> a >> b >> w; 
		roads[a - 1].push_back({ b - 1, w }); 
		roads[b - 1].push_back({ a - 1, w }); 
	}

	for (int p, i = 1; i <= K; i++) { 
		cin >> p;
		taxes.push_back(p + taxes[i - 1]);
	}

	for (int i = 0; i <= K; i++)
	{
		fill(d, d + N, 1e9);

		priority_queue<pair<int, long long>> q;
		q.push({ S - 1, 0 });
		d[S - 1] = 0;

		while (!q.empty())
		{
			int cur_node = q.top().first;
			long long cur_dist = q.top().second;
			q.pop();

			if (d[cur_node] < cur_dist) continue;

			for (pair<int, long long> next : roads[cur_node])
			{
				int next_node = next.first;
				long long next_dist = next.second + taxes[i];
				long long cost = cur_dist + next_dist;
				if (d[next_node] > cost)
				{
					d[next_node] = cost;
					q.push({ next_node, cost });
				}
			}
		}

		cout << d[D - 1] << endl;
	}
	
	return 0;
}