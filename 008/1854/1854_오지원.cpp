#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <queue>

int N, M, K;
std::vector< std::vector< std::pair<int, int> > > connected;
std::vector< std::priority_queue<int> > weight;

void calculate() {
	//cost, node
	std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > > pq;
	pq.emplace(std::make_pair(0, 1));
	weight[1].emplace(0);

	while (!pq.empty()) {
		auto front = pq.top();
		pq.pop();
		int cost = front.first;
		int node = front.second;

		for (int k = 0; k < connected[node].size(); k++) {
			int ncost = cost + connected[node][k].second;
			int nnode = connected[node][k].first;

			if (weight[nnode].size() == K && weight[nnode].top() > ncost) {
				weight[nnode].pop();
				weight[nnode].emplace(ncost);
				pq.emplace(std::make_pair(ncost, nnode));
			}
			else if (weight[nnode].size() < K) {
				weight[nnode].emplace(ncost);
				pq.emplace(std::make_pair(ncost, nnode));
			}

		}
	}

	for (int k = 1; k <= N; k++) {
		if (weight[k].size() == K) printf("%d\n", weight[k].top());
		else printf("-1\n");
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	connected.assign(N + 1, std::vector< std::pair<int, int> >());
	weight.assign(N + 1, std::priority_queue<int>());

	for (int k = 0; k < M; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		connected[a].emplace_back(std::make_pair(b, c));
	}
	calculate();
}