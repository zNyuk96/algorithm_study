#include<iostream>

using namespace std;

int M, N;
int T[100000];

int BSearch(int low, int high)
{
    if (low >= high) return low;

    int mid = (low + high) / 2;
    int people = 0;

    for (int i = 0; i < N; i++)
    {
        people += mid / T[i];
        if (people >= M) break;
    }

    if (people >= M)
        return BSearch(low, mid-1);
    else
        return BSearch(mid+1, high);
}

int main()
{
    // int max = 0;
    int min = 1000000001;
    
    // cin cout 속도 저하 해결용
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> T[i];
        // if (max < T[i]) max = T[i];
        if (min > T[i]) min = T[i];
    }

    cout << BSearch(1, min * M) << "\n";

    return 0;
}