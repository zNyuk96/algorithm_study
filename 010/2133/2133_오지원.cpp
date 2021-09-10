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

int N;
std::vector<int> dp;
std::vector<int> prefix;

int sum(int a) {
	int rst = 0;
	for (int k = 0; k <= a; k++) {
		rst += dp[k];
	}
	return rst;
}

int calculate() {
	dp.assign(N + 1, 0);
	prefix.assign(N + 1, 0);
	dp[0] = 1;
	for (int k = 1; k <= N; k++) {
		if (k % 2 == 1) continue;
		if (k >= 4) dp[k] = sum(k - 4) * 2;
		dp[k] += dp[k - 2] * 3;
	}
	return dp[N];
}

int main() {
	scanf("%d", &N);
	printf("%d", calculate());
}