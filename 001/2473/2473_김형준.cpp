#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    // cin cout 속도 저하 해결용
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // 용액의 수, 3 <= N <= 5000
    int answer[3];
    vector<long long> data;
    long long min_sum = 3 * 10e9 - 3;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        data.push_back(0);
        cin >> data[i];
    }
        
    sort(data.begin(), data.end());

    // 3-SUM 풀이 참고
    for (int i = 0; i < N - 2; i++)
    {
        int j = i + 1;
        int k = N - 1;

        while (true)
        {
            if (j >= k) break;

            long long sum = data[i] + data[j] + data[k];
            long long abs_sum = llabs(sum);

            if (abs_sum < min_sum)
            {
                min_sum = abs_sum;
                answer[0] = data[i];
                answer[1] = data[j];
                answer[2] = data[k];
            }

            if (sum >= 0)
                k--;
            else
                j++;
        }
    }

    cout << answer[0] << " " << answer[1] << " " << answer[2] << endl;

    return 0;
}