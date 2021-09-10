#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <limits.h>
#include <numeric>
#include <math.h>

int N, K;
std::vector<int> dp;
//����, ��ġ
std::vector< std::pair<int, int> > bag;
//k�� dp���� n�� ��ǰ���� ����ߴ�.
std::vector< std::vector<bool> > use;

int calculate() {
	for (int k = 1; k <= K; k++) {
		int use_item = -1;
		int when_use = -1;
		for (int kind = 0; kind < bag.size(); kind++) {
			if (k - bag[kind].first >= 0) {
				if (dp[k] < dp[k - bag[kind].first] + bag[kind].second && !use[k - bag[kind].first][kind]) {
					use_item = kind;
					when_use = k - bag[kind].first;
					dp[k] = dp[k - bag[kind].first] + bag[kind].second;
				}
			}
		}
		if (use_item != -1) {
			use[k] = use[when_use];
			use[k][use_item] = true;
		}
	}
	return *std::max_element(dp.begin(), dp.end());
}

int main() {
	scanf("%d %d", &N, &K);
	bag.assign(N, std::pair<int, int>());
	dp.assign(K + 1, 0);
	use.assign(K + 1, std::vector<bool>(N, false));
	for (int k = 0; k < N; k++) {
		int weight, value;
		scanf("%d %d", &weight, &value);
		bag[k] = std::make_pair(weight, value);
	}
	printf("%d", calculate());
}