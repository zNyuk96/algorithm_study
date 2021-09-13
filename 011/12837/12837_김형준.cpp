#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long arr[1000000];
vector<long long> tree;

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

int main() {
	long long N, T;
	cin >> N >> T;

	long long treeH = (long long)ceil(log2(N));
	long long treeS = 1 << (treeH + 1);
	tree.resize(treeS);

	while (T--)
	{
		long long op, p, q;
		cin >> op >> p >> q;
		if (op == 1) update(1, 0, N - 1, p - 1, q);
		else if (op == 2) cout << sum(1, 0, N - 1, 0, q - 1) - sum(1, 0, N - 1, 0, p - 1) << "\n";
	}

	return 0;
}