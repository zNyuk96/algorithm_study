#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>

int N, M;
std::vector<int> data;
std::vector<long long> tree;

long long make_tree(int node, int start, int end) {
	if (start == end) return tree[node] = (long long)data[start];
	int mid = (start + end) / 2;
	return tree[node] = std::min(make_tree(node * 2, start, mid), make_tree(node * 2 + 1, mid + 1, end));
}

long long calculate(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return LLONG_MAX;
	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return std::min(calculate(node * 2, start, mid, left, right), calculate(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
	scanf("%d %d", &N, &M);
	data.assign(N, 0);
	int size = ceil(log2(N)) + 1;
	tree.assign(1 << size, 0);
	for (int k = 0; k < N; k++) {
		scanf("%d", &data[k]);
	}
	
	make_tree(1, 0, N - 1);

	for (int k = 0; k < M; k++) {
		int from, to;
		scanf("%d %d", &from, &to);
		printf("%lld\n", calculate(1, 0, N - 1, from - 1, to - 1));
	}
}