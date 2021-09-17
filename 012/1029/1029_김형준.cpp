#include <iostream>
#define MAX(a,b) (a > b ? a : b)
using namespace std;

int N;
int arr[15][15];
int DP[15][1 << 16][10];

// 미완성
int run(int now, int visited, int prev)
{
    int ret = DP[now][visited][prev];

    for (int next = 0; next < N; next++)
    {
        if (visited & (1 << next)) continue;
        if (now == next) continue;

        if (arr[now][next] >= prev) ret = MAX(ret, run(next, (visited | 1 << next), arr[now][next]) + 1);
    }
}

int main() {
    for (int i = 0, char buf[16]; i < N; i++) {
        cin >> buf;
        for (int j = 0; j < N; j++) arr[i][j] = buf[j] - '0';
    }

    DP[0][1][0] = 1;
    cout << run(0, 1, 0);

    return 0;
}