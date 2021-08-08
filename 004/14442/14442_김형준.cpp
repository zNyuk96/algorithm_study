#include <iostream>
using namespace std;

int N, M, K;
int map[1000][1000];
int visited[1000][1000][11];
int success;
int minimum = 1000000;
int cnt = 0;

// DFS 버전
// 최대한 열심히 실행 횟수를 줄여봤으나 시간 초과
// BOTTOM UP으로 했으면 가능했을것 같기도 하고..?

void run(int x, int y, int k)
{
	cnt++; // 실행 횟수 카운터

	if (x == M - 1 && y == N - 1) {
		success = 1; // 성공 flag
		minimum = min(visited[y][x][k], minimum);

		return;
	}

	int dx[] = { 0, 0, -1, 1 };
	int dy[] = { 1, -1, 0, 0 };

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx > M - 1 || ny > N - 1) continue;

		if (!map[ny][nx] && !visited[ny][nx][k]) // 벽이 아니고 방문한 적이 없다면
		{
			//map[ny][nx] = 2; // 방문한 칸, 사용시 실행횟수 감소
			visited[ny][nx][k] = visited[y][x][k] + 1;
			run(nx, ny, k);
			visited[ny][nx][k] = 0; // 제거시 최적해를 못 찾음
			//map[ny][nx] = 0; // 갔다왔으면 땅으로 되돌림
		}
		else if (map[ny][nx] == 1 && k < K && !visited[ny][nx][k + 1]) // 벽인데 부숴본 적이 없다면
		{
			//map[ny][nx] = 3; // 뿌순 칸
			visited[ny][nx][k + 1] = visited[y][x][k] + 1;
			run(nx, ny, k + 1);
			visited[ny][nx][k] = 0; // 제거시 최적해를 못 찾음
			//map[ny][nx] = 1; // 갔다왔으면 벽으로 되돌림
		}
	}
}

int main()
{
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		string buf;
		cin >> buf;
		for (int j = 0; j < M; j++)
			map[i][j] = buf[j] - '0';
	}

	visited[0][0][0] = 1;
	run(0, 0, 0);

	cout << (success ? minimum : -1);

	return 0;
}