#include <iostream>
#define N 5000
#define MOD 1000000007
using namespace std;

long long DP[N+1];

int main() {
	//
	// 카탈란 수
	// https://suhak.tistory.com/77
	// n쌍의 올바른 괄호를 짝짓는 경우의 수 C[n]
	// 괄호 한쌍이 생기면 남은 괄호쌍은 N-1이고, 이 때 괄호 안은 k쌍 괄호 밖은 (N-1) - k쌍
	// C[1] = C[0]C[0]
	// C[2] = C[0]C[1] + C[1]C[0]
	// C[3] = C[0]C[2] + C[1]C[1] + C[2]C[0]
	// ...
	// C[n] = C[k]C[(n-1)-(k)] + C[k+1]C[(n-1)-(k+1)] + ... + C[n-1]C[(n-1)-(n-1)]
	// 
	// 괄호문자열 5000 => 괄호 2500쌍
	// C[n] = Sigma{k=0 to n-1}{C[k]C[n-1-k]} (1 <= n <= 2500)
	//

	DP[0] = 1;
	for (int n = 1; n <= N; n++)
		for (int k = 0; k < n; k++)
		{
			// MOD 해서 더했더니 틀림(심지어 overflow) => 더하고 MOD
			DP[n] += (long long)(DP[k] * DP[n - 1 - k]);
			DP[n] %= MOD;
		}			

	int T, L;
	cin >> T;
	while (T--)
	{
		cin >> L;
		cout << (L % 2 ? 0 : DP[L / 2]) << endl;
	}

	return 0;
}