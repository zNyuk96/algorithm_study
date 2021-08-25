#include<iostream>
#include<queue>
#include<map>
#include<vector>

using namespace std;

int main() {
	int n_computer, n_edge;
	vector<map<int, int>> edge;
	vector<pair<int, int>> costs;	//# [���, �������]
	priority_queue<pair<int, int>> pq;	//# [���, ������]
	pair<int, int> current;

	cin >> n_computer >> n_edge;
	edge = vector<map<int, int>>(n_computer, map<int, int>());
	costs = vector<pair<int, int>>(n_computer, { 10001, -1});

	for (int i = 0, computer1, computer2, cost; i < n_edge; i++) {
		cin >> computer1 >> computer2 >> cost;

		if (edge[computer1 - 1].find(computer2 - 1) == edge[computer1 - 1].end())
			edge[computer1 - 1][computer2 - 1] = 11;

		if (edge[computer2 - 1].find(computer1 - 1) == edge[computer2 - 1].end())
			edge[computer2 - 1][computer1 - 1] = 11;

		edge[computer1 - 1][computer2 - 1] = min(edge[computer1 - 1][computer2 - 1], cost);
		edge[computer2 - 1][computer1 - 1] = min(edge[computer2 - 1][computer1 - 1], cost);
	}

	// ���ͽ�Ʈ��
	costs[0].first = 0;    //# 1�� ��� -> 1�� ��� : ��� 0
	pq.push({costs[0].first, 0});

	while (!pq.empty()){
		current = pq.top();
		pq.pop();

		for (auto iter : edge[current.second]){
			if (current.first + iter.second < costs[iter.first].first) {
				costs[iter.first].first = current.first + iter.second;
				costs[iter.first].second = current.second;
				pq.push({ costs[iter.first].first, iter.first });
			}
		}
	}

	// ����ϱ�
	cout << n_computer - 1 << "\n";

	for (int i = 1; i < n_computer; i++)
		printf("%d %d\n", i + 1, costs[i].second + 1);

	return 0;
}