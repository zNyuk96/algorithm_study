#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <limits.h>

std::vector< std::vector< std::pair<int, long long> > > connected;
//cost, 몇개 node 방문했는지
//N번 노드를 X번을 거쳐 방문했을때 최단거리
std::vector< std::vector<long long> > weight;
std::vector<long long> inc;

int N, M, K;
int S, D;

void calculate() {
	//cost, node, 몇개node를 방문했는지
	std::priority_queue< std::tuple<long long, int, int>, std::vector< std::tuple<long long, int, int> >, std::greater< std::tuple<long long, int, int> > > pq;
	pq.emplace(std::make_tuple(0, S, 0));
	weight[S][0] = 0;

	while (!pq.empty()) {
		long long cost, num_visited;
		int node;
		std::tie(cost, node, num_visited) = pq.top();
		pq.pop();

		if (weight[node][num_visited] < cost) continue;
		if (num_visited >= N) continue;

		for (int k = 0; k < connected[node].size(); k++) {
			long long ncost = cost + connected[node][k].second;
			int nnode = connected[node][k].first;

			if (ncost < weight[nnode][num_visited + 1]) {
				pq.emplace(std::make_tuple(ncost, nnode, num_visited + 1));
				weight[nnode][num_visited + 1] = ncost;
			}
		}
	}

	for (int tax = 0; tax < inc.size(); tax++) {
		long long ans = LLONG_MAX;
		for (int k = 0; k < weight[D].size(); k++) {
			ans = std::min(ans, weight[D][k] + inc[tax] * k);
		}
		printf("%lld\n", ans);
	}

}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	scanf("%d %d", &S, &D);
	connected.assign(N + 1, std::vector< std::pair<int, long long> >());
	weight.assign(N + 1, std::vector<long long>(N + 1, LLONG_MAX));
	inc.assign(K + 1, 0);
	for (int k = 0; k < M; k++) {
		int a, b;
		long long c;
		scanf("%d %d %lld", &a, &b, &c);
		connected[a].emplace_back(std::make_pair(b, c));
		connected[b].emplace_back(std::make_pair(a, c));
	}
	for (int k = 1; k <= K; k++) {
		long long inc_v;
		scanf("%lld", &inc_v);
		if (k == 1) inc[k] = inc_v;
		else inc[k] = inc[k - 1] + inc_v;
	}
	calculate();
}