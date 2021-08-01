#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, k, sum;

int BSearch(int low, int high)
{
    if (low >= high) return low;
    int mid = (low + high) / 2;
    int cnt = 0;

    for (int i = 1; i <= N; i++) cnt += min(N, mid / i);
    // N=5, target=12
    // 1  2  3  4  5 ... 12/1 = 12 => N
    // 2  4  6  8 10 ... 12/2 = 6 => N
    // 3  6  9 12 15 ... 12/3 = 4 => 4
    // 4  8 12 16 20 ... 12/4 = 3 => 3
    // 5 10 15 20 25 ... 12/5 = 2 => 2

    if (cnt >= k) return BSearch(low, mid);
    else return BSearch(mid+1, high);
}

int main() {
    cin >> N >> k;

    cout << BSearch(1, k);

    return 0;
}