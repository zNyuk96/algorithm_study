#include <iostream>
#include <vector>
#include <cmath>
#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)
using namespace std;

long long arr[100000];
long long treeH, treeS;
vector<long long> tree;
long long max_val;

// 틀렸습니다... 왜????

long long init(long long i, long long s, long long e)
{
	if (s == e)
		tree[i] = arr[s];
	else
	{
		long long m = (s + e) / 2;
		tree[i] = MIN(init(i * 2, s, m), init(i * 2 + 1, m + 1, e));
	}

	return tree[i];
}

long long run(long long i, long long s, long long e)
{
	if (s == e) return max_val = MAX(max_val, tree[i]);

	long long m = (s + e) / 2;
	run(i * 2, s, m);
	run(i * 2 + 1, m + 1, e);

	return max_val = MAX(max_val, tree[i] * (e - s + 1));
}

int main() {
	long long N;
	cin >> N;

	for (long long i = 0; i < N; i++) cin >> arr[i];

	treeH = (long long)ceil(log2(N));
	treeS = 1 << (treeH + 1);
	tree.resize(treeS);

	init(1, 0, N - 1);
	cout << run(1, 0, N - 1);

	return 0;
}