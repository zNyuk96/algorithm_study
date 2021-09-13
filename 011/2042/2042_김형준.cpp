#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long arr[1000000];
vector<long long> tree;

long long init(long long i, long long s, long long e)
{
	if (s == e) return tree[i] = arr[s];

	long long m = (s + e) / 2;
	return tree[i] = init(i * 2, s, m) + init(i * 2 + 1, m + 1, e);
}

long long sum(long long i, long long s, long long e, long long l, long long r)
{
	if (l > e || r < s) return 0; // 범위 밖이면 안더함
	if (l <= s && e <= r) return tree[i];

	long long m = (s + e) / 2;
	return sum(i * 2, s, m, l, r) + sum(i * 2 + 1, m + 1, e, l, r);
}

void update(long long i, long long s, long long e, long long t, long long d)
{

	if (s > t || e < t) return; // 범위 밖이면 리턴

	tree[i] += d;

	if (s == e) return;

	long long m = (s + e) / 2;
	update(i * 2, s, m, t, d);
	update(i * 2 + 1, m + 1, e, t, d);
}

long long get(long long i, long long s, long long e, long long t)
{
	if (s > t || e < t) return 0; // 범위 밖이면 리턴

	if (s == e) return tree[i];

	long long m = (s + e) / 2;
	return get(i * 2, s, m, t) + get(i * 2 + 1, m + 1, e, t);
}

int main() {
	long long N, M, K;
	cin >> N >> M >> K;

	for (long long i = 0; i < N; i++) cin >> arr[i];

	long long treeH = (long long)ceil(log2(N));
	long long treeS = 1 << (treeH + 1);
	tree.resize(treeS);

	init(1, 0, N - 1);

	for (long long i = 0; i < M + K; i++)
	{
		long long op, p, q;
		cin >> op >> p >> q;
		if (op == 1) update(1, 0, N - 1, p - 1, q - get(1, 0, N - 1, p - 1));
		else if (op == 2) cout << sum(1, 0, N - 1, p - 1, q - 1) << "\n";
	}

	return 0;
}