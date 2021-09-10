#include <iostream>
using namespace std;
int DP[11];

int run(int n)
{
    if (n <= 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;
    if (DP[n]) return DP[n];

    // 점화식: A[n] = A[n-1] + A[n-2] + A[n-3]
    DP[n] = run(n - 1) + run(n - 2) + run(n - 3);

    return DP[n];
}

int main() {
    int T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        cout << run(N) << endl;
    }

    return 0;
}