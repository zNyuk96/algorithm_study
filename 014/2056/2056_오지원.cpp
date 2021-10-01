#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N;
std::vector<int> time_v;
//n번에서 나가는 outdegree node
std::vector< std::vector<int> > outdegree_node;
//indegree의 개수
std::vector<int> indegree;
std::vector<int> dp;

int calculate() {
	int ans = 0;
	std::queue<int> q;
	for (int k = 1; k <= N; k++) {
		if (!indegree[k]) {
			q.emplace(k);
			dp[k] = time_v[k];
		}
	}

	while (!q.empty()) {
		auto node = q.front();
		q.pop();

		for (int k = 0; k < outdegree_node[node].size(); k++) {
			indegree[outdegree_node[node][k]]--;

			dp[outdegree_node[node][k]] = std::max(dp[outdegree_node[node][k]], dp[node] + time_v[outdegree_node[node][k]]);

			if (!indegree[outdegree_node[node][k]]) {
				q.emplace(outdegree_node[node][k]);
			}
		}
	}

	return *std::max_element(dp.begin(), dp.end());
}

int main() {
	scanf("%d", &N);
	time_v.assign(N + 1, 0);
	outdegree_node.assign(N + 1, std::vector<int>());
	indegree.assign(N + 1, 0);
	dp.assign(N + 1, 0);
	for (int k = 1; k <= N; k++) {
		int time_val, size;
		scanf("%d %d", &time_val, &size);
		time_v[k] = time_val;
		for (int index = 0; index < size; index++) {
			int node;
			scanf("%d", &node);
			outdegree_node[node].emplace_back(k);
			indegree[k]++;
		}
	}
	printf("%d", calculate());
}