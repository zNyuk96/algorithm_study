#include <iostream>
using namespace std;

int DP[30];

int run(int n) {
    if (n % 2) return 0; // 홀수 제외
    
	if (n == 0) return 1;
	if (n == 2) return 3;
	if (DP[n]) return DP[n];
    
    // 점화식: A[n] = 3 * A[n-2] + 2 * A[n-4] + ... + 2
    DP[n] = run(n - 2);
    
    for (int i = 2; i <= n; i += 2) DP[n] += 2 * run(n - i);
    
    return DP[n];
}

int main() {
	int N;
    cin >> N;
	cout << run(N);
    
    return 0;
}