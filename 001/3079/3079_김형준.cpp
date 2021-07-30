#include<iostream>

using namespace std;

long long M, N; 
long long T[100000];

long long BSearch(long long low, long long high)
{
    if (low >= high) return low;

    long long mid = (low + high) / 2;
    long long people = 0;

    for (int i = 0; i < N; i++)
    {
        people += mid / T[i];
        if (people >= M) break;
    }

    if (people >= M)
        return BSearch(low, mid); // >=조건에서 재귀 high가 mid-1이었던 부분 수정
    else
        return BSearch(mid+1, high);
}

int main()
{
    // int max = 0;
    long long min = 1000000001;
    
    // cin cout 속도 저하 해결용
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (long long i = 0; i < N; i++)
    {
        cin >> T[i];
        // if (max < T[i]) max = T[i];
        if (min > T[i]) min = T[i];
    }

    cout << BSearch(1, min * M) << "\n";

    return 0;
}