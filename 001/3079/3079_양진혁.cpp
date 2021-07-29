#include <iostream>

long long arr[100000] = { 0, };
int N, M;

long long bs(long long s, long long e) {
    if (s == e) return s;
    long long m = s + e >> 1;
    long long count = 0;
    for (int i = 0; i < N; i++) {
        count += m / arr[i];
    }
    if (count >= M) {
        return bs(s, m);
    }
    else {
        return bs(m + 1, e);
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> N >> M;
    long long TMAX = 0, temp;
    for (int i = 0; i < N; i++) {
        std::cin >> temp;
        TMAX = (temp > TMAX) ? temp : TMAX;
        arr[i] = temp;
    }
    long long MMAX = TMAX * M;
    long long res = bs(0, MMAX);
    std::cout << res;
}