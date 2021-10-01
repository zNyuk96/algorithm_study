#pragma warning (disable : 4996)
#include<iostream>
#include <string.h>
#include<string>
#include<queue>
#include <vector>

long long dp[5001];
int tc;

void calculate(int N)
{
	dp[0] = 1;

	for (int i = 1; i <= N / 2; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] += ((dp[i - j - 1] % 1000000007) * (dp[j] % 1000000007)) % 1000000007;
		}
	}
}

int main(void)
{
	scanf("%d", &tc);


	for (int k = 0; k < tc; k++)
	{
		int n;
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		if (n % 2 == 1) printf("%lld\n", 0);
		else {
			calculate(n);
			printf("%lld\n", dp[n / 2] % 1000000007);
		}
	}
}