#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

int N;
std::vector< std::vector<int> > list;
bool ans;
std::vector<int> rst;
std::vector<int> ans_road;

std::vector< std::vector<bool> > visited;

void calculate(int level, int p_kind) {


	if (level == N) {
		ans = true;
		ans_road = rst;
		return;
	}


	for (int k = 0; k < list[level].size(); k++) {
		if (list[level][k] != p_kind && !ans && !visited[level][k]) {
			rst[level] = list[level][k];
			visited[level][k] = true;
			calculate(level + 1, list[level][k]);
		}
	}

	return;
}

int main() {
	scanf("%d", &N);
	list.assign(N, std::vector<int>(0, 0));
	rst.assign(N, 0);
	visited.assign(N + 1, std::vector<bool>(0, 0));
	for (int each = 0; each < N; each++) {
		int size;
		scanf("%d", &size);
		visited[each].assign(size, false);
		for (int k = 0; k < size; k++) {
			int kind;
			scanf("%d", &kind);
			list[each].emplace_back(kind);
		}
	}
	calculate(0, 0);
	if (ans) {
		for (int k = 0; k < ans_road.size(); k++) {
			printf("%d\n", rst[k]);
		}
	}
	else printf("-1");
}
