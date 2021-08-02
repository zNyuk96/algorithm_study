#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

int N;
int minimum = INT32_MAX;
int maximum = INT32_MIN;
int pic[501][500];
vector<pair<int, int>> result;

bool find_ball(int p, int v) {
    int ret = 0;
    int i, j;

    for (i = 0; i < N + 1; i++) {
        for (j = 0; j < N; j++)
        {
            if ((pic[i][j] - p) % v == 0) {
                ret++;
                break;
            }
        }
        if (ret != i + 1) break;
    }

    return (ret == N + 1);
}

// 답지 참고하였으나 틀렸음

int main() {
    cin >> N;

    for (int i = 0; i < N + 1; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> pic[i][j];
            if (minimum > pic[i][j]) minimum = pic[i][j];
            if (maximum < pic[i][j]) maximum = pic[i][j];
        }

    for (int i = 0; i < N; i++)
    {
        int p = pic[0][i]; // 처음 위치
        for (int j = 0; j < N; j++)
        {
            int v = (pic[N][j] - p) / N; // 사진이 N + 1개이므로 경계선은 N개, N으로 나누면 단위 속도(?)가 나옴
            if (v == 0) continue;
            if (find_ball(p, v)) {
                result.push_back(pair<int, int>(p, v));
                break;
            }
        }
    }

    sort(result.begin(), result.end());

    for (pair<int, int> i : result)
        cout << i.first << " " << i.second << "\n";

    return 0;
}