#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, K;
pair<int, int> bag[101]; //  무게, 가치
int dp[101][100001];

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> bag[i].first >> bag[i].second;

	for (int i = 1; i <= N; i++)
	{
		for (int w = 1; w <= K; w++)
		{
			dp[i][w] = dp[i - 1][w];

			int weight = bag[i].first;
			int value = bag[i].second;

			if (w < weight) continue;
			if (dp[i][w] < dp[i - 1][w - weight] + value) dp[i][w] = dp[i - 1][w - weight] + value;
		}
	}

	cout << dp[N][K];

	return 0;
}