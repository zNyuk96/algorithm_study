#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> aList(2000); // 인접리스트
int N, M;
int visited[2000];
int success;

void run(int now, int level)
{
	if (success) return;

	if (level == 4) {
		success = 1; 
		return;
	}

	for (int i : aList[now])
	{
		if (visited[i]) continue;
		visited[now] = 1;
		run(i, level + 1);
		visited[now] = 0;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		aList[a].push_back(b);
		aList[b].push_back(a);
	}

	for (int i = 0; i < N; i++) // 시작점 변경
		run(i, 0);

	cout << success;

	return 0;
}