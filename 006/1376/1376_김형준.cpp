#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int N, M;
vector<vector<int>> arr;
int visited[100001];
int path[100000];
int T;

// 민식이의 사악함에 패배

int getNext(int x)
{
    vector<int> canGo;

    for (int i : arr[x])
        if (!visited[i]) canGo.push_back(i);

    const int size = canGo.size();

    return (!size) ? -1 : (size % 2) ? canGo[(size - 1) / 2] : canGo[0];
}

void run(int level)
{
    if (T == N - 1)
    {
        for (int i = 0; i < N; i++)
            cout << path[i] << " ";

        cout << endl;
        return;
    }

    int next;
    while ((next = getNext(path[level - 1])) != -1) // 이부근이 틀린거같은데...
    {
        path[++T] = next;
        visited[next] = true;
        run(level + 1);
    }
}

int main() {
    cin >> N >> M;
    arr = vector<vector<int>>(N + 1);

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;

        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(arr[i].begin(), arr[i].end());
        arr[i].erase(unique(arr[i].begin(), arr[i].end()), arr[i].end());
    }

    visited[1] = true;
    path[0] = 1;
    run(1);

    return 0;
}