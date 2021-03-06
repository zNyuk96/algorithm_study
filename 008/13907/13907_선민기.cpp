<<<<<<< HEAD
#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include <tuple>
#include<algorithm>

using namespace std;

int main() {
	long n_city, n_edge, times, src, dst;
	long cur_cost, edge_cnt, cur_node;
	vector<map<long, long>> edge;
	vector<vector<long>> costs;
	vector<pair<long, long>> costs_min;
	priority_queue<tuple<long, long, long>> djik_queue;

	cin >> n_city >> n_edge >> times;
	cin >> src >> dst;
	edge = vector<map<long, long>>(n_city, map<long, long>());
	costs = vector<vector<long>>(n_city, vector<long>(n_city, 1300001));	// # costs[i][j], i번째 도시까지 j의 간선으로 오는 최소비용
	costs_min = vector<pair<long, long>>(n_city, { n_city, 1300001 });	// # [최소비용의 간선 개수, 최소 비용]

	for (long i = 0, _src, _dst, _cost; i < n_edge; i++) {
		scanf("%ld %ld %ld", &_src, &_dst, &_cost);

		if (edge[_src - 1].find(_dst - 1) == edge[_src - 1].end())
			edge[_src - 1][_dst - 1] = 1000;

		edge[_src - 1][_dst - 1] = min(edge[_src - 1][_dst - 1], _cost);

		if (edge[_dst - 1].find(_src - 1) == edge[_dst - 1].end())
			edge[_dst - 1][_src - 1] = 1000;

		edge[_dst - 1][_src - 1] = min(edge[_dst - 1][_src - 1], _cost);
	}

	// 다익스트라
	costs[src - 1][0] = 0;
	costs_min[src - 1] = { 0, 0 };
	djik_queue.push({ 0, 0, src - 1 });	// # 비용, 간선 개수, 현재 노드

	while (!djik_queue.empty()) {
		cur_cost = get<0>(djik_queue.top());
		edge_cnt = get<1>(djik_queue.top());
		cur_node = get<2>(djik_queue.top());

		djik_queue.pop();

		// # 도시가 n개 일 때 거칠 수 있는 간선의 최대 개수는 n - 1개
		if (edge_cnt + 1 < n_city) {
			for (map<long, long>::iterator it = edge[cur_node].begin(); it != edge[cur_node].end(); it++) {
				// # 최소비용의 간선보다 많은 간선 쓰면서 비용도 높으면 cut
				// # 최소 비용의 간선보다 적은 간선 쓰는 경우(나중에 세금 오르면 최소 비용이 될 수 있음)
				if (costs_min[it->first].first > edge_cnt + 1) {
					// # 최소 비용 갱신이 가능한 경우 갱신
					if (costs_min[it->first].second > cur_cost + it->second) {
						costs_min[it->first].first = edge_cnt + 1;
						costs_min[it->first].second = cur_cost + it->second;
					}
					if (cur_cost + it->second < costs[it->first][edge_cnt + 1]) {
						costs[it->first][edge_cnt + 1] = cur_cost + it->second;
						djik_queue.push({ costs[it->first][edge_cnt + 1], edge_cnt + 1, it->first });
					}
				}
				// # 최소 비용인 경우 갱신
				else if (costs_min[it->first].second > cur_cost + it->second) {
					costs_min[it->first].first = edge_cnt + 1;
					costs_min[it->first].second = cur_cost + it->second;

					if (cur_cost + it->second < costs[it->first][edge_cnt + 1]) {
						costs[it->first][edge_cnt + 1] = cur_cost + it->second;
						djik_queue.push({ costs[it->first][edge_cnt + 1], edge_cnt + 1, it->first });
					}
				}
			}
		}
	}

	// # 출력
	cout << *min_element(costs[dst - 1].begin(), costs[dst - 1].end()) << endl;

	for (long i = 0, time; i < times; i++) {
		scanf("%ld", &time);

		for (long j = 0; j < n_city; j++) {
			if (costs[dst - 1][j] != 1300001)
				costs[dst - 1][j] += j * time;
		}

		cout << *min_element(costs[dst - 1].begin(), costs[dst - 1].end()) << endl;
	}

	return 0;
=======
#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include <tuple>
#include<algorithm>

using namespace std;

int main() {
	long n_city, n_edge, times, src, dst;
	long cur_cost, edge_cnt, cur_node;
	vector<map<long, long>> edge;
	vector<vector<long>> costs;
	vector<pair<long, long>> costs_min;
	priority_queue<tuple<long, long, long>> djik_queue;

	cin >> n_city >> n_edge >> times;
	cin >> src >> dst;
	edge = vector<map<long, long>>(n_city, map<long, long>());
	costs = vector<vector<long>>(n_city, vector<long>(n_city, 1300001));	// # costs[i][j], i踰덉㎏ ?룄?떆源뚯?? j?쓽 媛꾩꽑?쑝濡? ?삤?뒗 理쒖냼鍮꾩슜
	costs_min = vector<pair<long, long>>(n_city, {n_city, 1300001 });	// # [理쒖냼鍮꾩슜?쓽 媛꾩꽑 媛쒖닔, 理쒖냼 鍮꾩슜]

	for (long i = 0, _src, _dst, _cost; i < n_edge; i++) {
		scanf("%ld %ld %ld", &_src, &_dst, &_cost);

		if (edge[_src - 1].find(_dst - 1) == edge[_src - 1].end())
			edge[_src - 1][_dst - 1] = 1000;

		edge[_src - 1][_dst - 1] = min(edge[_src - 1][_dst - 1], _cost);

		if (edge[_dst - 1].find(_src - 1) == edge[_dst - 1].end())
			edge[_dst - 1][_src - 1] = 1000;

		edge[_dst - 1][_src - 1] = min(edge[_dst - 1][_src - 1], _cost);
	}

	// ?떎?씡?뒪?듃?씪
	costs[src - 1][0] = 0;
	costs_min[src - 1] = {0, 0};
	djik_queue.push({0, 0, src - 1});	// # 鍮꾩슜, 媛꾩꽑 媛쒖닔, ?쁽?옱 ?끂?뱶

	while (!djik_queue.empty()){
		cur_cost = get<0>(djik_queue.top());
		edge_cnt = get<1>(djik_queue.top());
		cur_node = get<2>(djik_queue.top());

		djik_queue.pop();

		// # ?룄?떆媛? n媛? ?씪 ?븣 嫄곗튌 ?닔 ?엳?뒗 媛꾩꽑?쓽 理쒕?? 媛쒖닔?뒗 n - 1媛?
		if (edge_cnt + 1 < n_city) {
			for (map<long, long>::iterator it = edge[cur_node].begin(); it != edge[cur_node].end(); it++) {
				// # 理쒖냼鍮꾩슜?쓽 媛꾩꽑蹂대떎 留롮?? 媛꾩꽑 ?벐硫댁꽌 鍮꾩슜?룄 ?넂?쑝硫? cut
				// # 理쒖냼 鍮꾩슜?쓽 媛꾩꽑蹂대떎 ?쟻??? 媛꾩꽑 ?벐?뒗 寃쎌슦(?굹以묒뿉 ?꽭湲? ?삤瑜대㈃ 理쒖냼 鍮꾩슜?씠 ?맆 ?닔 ?엳?쓬)
				if (costs_min[it->first].first > edge_cnt + 1) {
					// # 理쒖냼 鍮꾩슜 媛깆떊?씠 媛??뒫?븳 寃쎌슦 媛깆떊
					if (costs_min[it->first].second > cur_cost + it->second) {
						costs_min[it->first].first = edge_cnt + 1;
						costs_min[it->first].second = cur_cost + it->second;
					}
					if (cur_cost + it->second < costs[it->first][edge_cnt + 1]) {
						costs[it->first][edge_cnt + 1] = cur_cost + it->second;
						djik_queue.push({ costs[it->first][edge_cnt + 1], edge_cnt + 1, it->first});
					}
				}
				// # 理쒖냼 鍮꾩슜?씤 寃쎌슦 媛깆떊
				else if(costs_min[it->first].second > cur_cost + it->second){
					costs_min[it->first].first = edge_cnt + 1;
					costs_min[it->first].second = cur_cost + it->second;

					if (cur_cost + it->second < costs[it->first][edge_cnt + 1]) {
						costs[it->first][edge_cnt + 1] = cur_cost + it->second;
						djik_queue.push({ costs[it->first][edge_cnt + 1], edge_cnt + 1, it->first });
					}
				}
			}
		}
	}

	// # 異쒕젰
	cout << *min_element(costs[dst - 1].begin(), costs[dst - 1].end()) << endl;

	for (long i = 0, time; i < times; i++) {
		scanf("%ld", &time);

		for (long j = 0; j < n_city; j++) {
			if (costs[dst - 1][j] != 1300001)
				costs[dst - 1][j] += j * time;
		}

		cout << *min_element(costs[dst - 1].begin(), costs[dst - 1].end()) << endl;
	}

	return 0;
>>>>>>> 6cfaaac18112fab8175d73b058b6b88d476808ea
}