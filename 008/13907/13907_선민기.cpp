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
	costs = vector<vector<long>>(n_city, vector<long>(n_city, 1300001));	// # costs[i][j], i¹øÂ° µµ½Ã±îÁö jÀÇ °£¼±À¸·Î ¿À´Â ÃÖ¼Òºñ¿ë
	costs_min = vector<pair<long, long>>(n_city, { n_city, 1300001 });	// # [ÃÖ¼Òºñ¿ëÀÇ °£¼± °³¼ö, ÃÖ¼Ò ºñ¿ë]

	for (long i = 0, _src, _dst, _cost; i < n_edge; i++) {
		scanf("%ld %ld %ld", &_src, &_dst, &_cost);

		if (edge[_src - 1].find(_dst - 1) == edge[_src - 1].end())
			edge[_src - 1][_dst - 1] = 1000;

		edge[_src - 1][_dst - 1] = min(edge[_src - 1][_dst - 1], _cost);

		if (edge[_dst - 1].find(_src - 1) == edge[_dst - 1].end())
			edge[_dst - 1][_src - 1] = 1000;

		edge[_dst - 1][_src - 1] = min(edge[_dst - 1][_src - 1], _cost);
	}

	// ´ÙÀÍ½ºÆ®¶ó
	costs[src - 1][0] = 0;
	costs_min[src - 1] = { 0, 0 };
	djik_queue.push({ 0, 0, src - 1 });	// # ºñ¿ë, °£¼± °³¼ö, ÇöÀç ³ëµå

	while (!djik_queue.empty()) {
		cur_cost = get<0>(djik_queue.top());
		edge_cnt = get<1>(djik_queue.top());
		cur_node = get<2>(djik_queue.top());

		djik_queue.pop();

		// # µµ½Ã°¡ n°³ ÀÏ ¶§ °ÅÄ¥ ¼ö ÀÖ´Â °£¼±ÀÇ ÃÖ´ë °³¼ö´Â n - 1°³
		if (edge_cnt + 1 < n_city) {
			for (map<long, long>::iterator it = edge[cur_node].begin(); it != edge[cur_node].end(); it++) {
				// # ÃÖ¼Òºñ¿ëÀÇ °£¼±º¸´Ù ¸¹Àº °£¼± ¾²¸é¼­ ºñ¿ëµµ ³ôÀ¸¸é cut
				// # ÃÖ¼Ò ºñ¿ëÀÇ °£¼±º¸´Ù ÀûÀº °£¼± ¾²´Â °æ¿ì(³ªÁß¿¡ ¼¼±İ ¿À¸£¸é ÃÖ¼Ò ºñ¿ëÀÌ µÉ ¼ö ÀÖÀ½)
				if (costs_min[it->first].first > edge_cnt + 1) {
					// # ÃÖ¼Ò ºñ¿ë °»½ÅÀÌ °¡´ÉÇÑ °æ¿ì °»½Å
					if (costs_min[it->first].second > cur_cost + it->second) {
						costs_min[it->first].first = edge_cnt + 1;
						costs_min[it->first].second = cur_cost + it->second;
					}
					if (cur_cost + it->second < costs[it->first][edge_cnt + 1]) {
						costs[it->first][edge_cnt + 1] = cur_cost + it->second;
						djik_queue.push({ costs[it->first][edge_cnt + 1], edge_cnt + 1, it->first });
					}
				}
				// # ÃÖ¼Ò ºñ¿ëÀÎ °æ¿ì °»½Å
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

	// # Ãâ·Â
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
	costs = vector<vector<long>>(n_city, vector<long>(n_city, 1300001));	// # costs[i][j], ië²ˆì§¸ ë„ì‹œê¹Œì§€ jì˜ ê°„ì„ ìœ¼ë¡œ ì˜¤ëŠ” ìµœì†Œë¹„ìš©
	costs_min = vector<pair<long, long>>(n_city, {n_city, 1300001 });	// # [ìµœì†Œë¹„ìš©ì˜ ê°„ì„  ê°œìˆ˜, ìµœì†Œ ë¹„ìš©]

	for (long i = 0, _src, _dst, _cost; i < n_edge; i++) {
		scanf("%ld %ld %ld", &_src, &_dst, &_cost);

		if (edge[_src - 1].find(_dst - 1) == edge[_src - 1].end())
			edge[_src - 1][_dst - 1] = 1000;

		edge[_src - 1][_dst - 1] = min(edge[_src - 1][_dst - 1], _cost);

		if (edge[_dst - 1].find(_src - 1) == edge[_dst - 1].end())
			edge[_dst - 1][_src - 1] = 1000;

		edge[_dst - 1][_src - 1] = min(edge[_dst - 1][_src - 1], _cost);
	}

	// ë‹¤ìµìŠ¤íŠ¸ë¼
	costs[src - 1][0] = 0;
	costs_min[src - 1] = {0, 0};
	djik_queue.push({0, 0, src - 1});	// # ë¹„ìš©, ê°„ì„  ê°œìˆ˜, í˜„ì¬ ë…¸ë“œ

	while (!djik_queue.empty()){
		cur_cost = get<0>(djik_queue.top());
		edge_cnt = get<1>(djik_queue.top());
		cur_node = get<2>(djik_queue.top());

		djik_queue.pop();

		// # ë„ì‹œê°€ nê°œ ì¼ ë•Œ ê±°ì¹  ìˆ˜ ìˆëŠ” ê°„ì„ ì˜ ìµœëŒ€ ê°œìˆ˜ëŠ” n - 1ê°œ
		if (edge_cnt + 1 < n_city) {
			for (map<long, long>::iterator it = edge[cur_node].begin(); it != edge[cur_node].end(); it++) {
				// # ìµœì†Œë¹„ìš©ì˜ ê°„ì„ ë³´ë‹¤ ë§ì€ ê°„ì„  ì“°ë©´ì„œ ë¹„ìš©ë„ ë†’ìœ¼ë©´ cut
				// # ìµœì†Œ ë¹„ìš©ì˜ ê°„ì„ ë³´ë‹¤ ì ì€ ê°„ì„  ì“°ëŠ” ê²½ìš°(ë‚˜ì¤‘ì— ì„¸ê¸ˆ ì˜¤ë¥´ë©´ ìµœì†Œ ë¹„ìš©ì´ ë  ìˆ˜ ìˆìŒ)
				if (costs_min[it->first].first > edge_cnt + 1) {
					// # ìµœì†Œ ë¹„ìš© ê°±ì‹ ì´ ê°€ëŠ¥í•œ ê²½ìš° ê°±ì‹ 
					if (costs_min[it->first].second > cur_cost + it->second) {
						costs_min[it->first].first = edge_cnt + 1;
						costs_min[it->first].second = cur_cost + it->second;
					}
					if (cur_cost + it->second < costs[it->first][edge_cnt + 1]) {
						costs[it->first][edge_cnt + 1] = cur_cost + it->second;
						djik_queue.push({ costs[it->first][edge_cnt + 1], edge_cnt + 1, it->first});
					}
				}
				// # ìµœì†Œ ë¹„ìš©ì¸ ê²½ìš° ê°±ì‹ 
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

	// # ì¶œë ¥
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