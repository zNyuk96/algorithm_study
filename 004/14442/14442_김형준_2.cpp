#include <iostream>
#include <queue>
using namespace std;

typedef struct Node {
	int x;
	int y;
	int k;
}Node;

int N, M, K;
int map[1000][1000];
int visited[1000][1000][11];
int success;
int minimum = 1000000;
int cnt = 0;
queue<Node> q;

// BFS 버전
// 통과

void run(Node n)
{
	cnt++; // 실행 횟수 카운터

	if (n.x == M - 1 && n.y == N - 1) {
		success = 1; // 성공 flag
		minimum = min(visited[n.y][n.x][n.k], minimum);

		return;
	}

	int dx[] = { 0, 0, -1, 1 };
	int dy[] = { 1, -1, 0, 0 };

	for (int i = 0; i < 4; i++)
	{
		int nx = n.x + dx[i];
		int ny = n.y + dy[i];
		if (nx < 0 || ny < 0 || nx > M - 1 || ny > N - 1) continue;

		if (!map[ny][nx] && !visited[ny][nx][n.k]) // 벽이 아니고 방문한 적이 없다면
		{
			visited[ny][nx][n.k] = visited[n.y][n.x][n.k] + 1;
			q.push(Node{ nx, ny, n.k });
		}
		else if (map[ny][nx] == 1 && n.k < K && !visited[ny][nx][n.k + 1]) // 벽인데 부숴본 적이 없다면
		{
			visited[ny][nx][n.k + 1] = visited[n.y][n.x][n.k] + 1;
			q.push(Node{ nx, ny, n.k + 1 });
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
	q.push(Node{ 0, 0, 0 });
	
	while (!q.empty())
	{
		run(q.front());
		q.pop();
	}

	cout << (success ? minimum : -1);

	return 0;
}