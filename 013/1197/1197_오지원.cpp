#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <tuple>

int V, E;
std::priority_queue< std::tuple<int, int, int>, std::vector<std::tuple<int,int,int> >, std::greater< std::tuple<int, int, int> > > pq;
std::vector<int> parent;

int get_parent(int node) {
	if (node == parent[node]) return node;
	else return parent[node] = get_parent(parent[node]);
}

void union_n(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool find(int a, int b) {
	if (get_parent(a) == get_parent(b)) return true;
	else return false;
}

int calculate() {
	int ans = 0;
	int make_V = 0;
	while (!pq.empty()) {
		int a, b, c;
		std::tie(c, a, b) = pq.top();
		pq.pop();

		if (!find(a, b)) {
			union_n(a, b);
			ans += c;
			make_V++;
		}

		if (make_V == E - 1) break;
	}
	return ans;
}

int main() {
	scanf("%d %d", &V, &E);
	parent.assign(V, 0);
	std::iota(parent.begin(), parent.end(), 0);

	for (int k = 0; k < E; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		pq.emplace(std::make_tuple(c, a - 1, b - 1));
	}

	printf("%d", calculate());
}