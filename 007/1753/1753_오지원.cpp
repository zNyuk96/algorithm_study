#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>

int V, E, K;
std::vector< std::vector<std::pair<int, int> > > connected;
std::vector<int> weight;

void calculate() {
	std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater<std::pair<int, int> > > pq;
	pq.emplace(std::make_pair(0, K));
	weight[K] = 0;

	while (!pq.empty()) {
		auto front = pq.top();
		pq.pop();

		int cost = front.first;
		int node = front.second;

		if (weight[node] < cost) continue;

		for (int k = 0; k < connected[node].size(); k++) {
			int n_cost = cost + connected[node][k].second;
			int n_node = connected[node][k].first;

			if (weight[n_node] > n_cost) {
				weight[n_node] = n_cost;
				pq.emplace(std::make_pair(n_cost, n_node));
			}
		}
	}

	for (int k = 1; k <= V; k++)
	{
		if (weight[k] != INT_MAX) printf("%d\n", weight[k]);
		else printf("INF\n");
	}
}

int main() {
	scanf("%d %d", &V, &E);
	connected.assign(V + 1, std::vector< std::pair<int, int> >());
	weight.assign(V + 1, INT_MAX);
	scanf("%d", &K);
	for (int k = 0; k < E; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		connected[a].emplace_back(std::make_pair(b, c));
	}
	calculate();
}