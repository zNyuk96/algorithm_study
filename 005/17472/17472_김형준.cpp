#include <iostream>
#include <vector>
#include <tuple>
#define INF 1e9
using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> graph;
int country_idx = 'A';
int country_count = 0;

int path[6];
int used[6];
int minimum = 1000;

void run(int level, int distance)
{	
	if (level == country_count)
	{
		minimum = min(minimum, distance);
		for (int i = 0; i < level; i++)
			cout << (char)('A' + path[i]) << " ";
		cout << distance << endl;
		return;
	}

	for (int i = 0; i < country_count; i++)
	{
		if (used[i]) continue;
		if (level > 0 && !graph[path[level - 1]][i]) continue;
		used[i] = 1;
		path[level] = i;
		run(level + 1, distance + (level > 0 ? graph[path[level - 1]][i] : 0));
		path[level] = 0;
		used[i] = 0;
	}
}


int main() {
	cin >> N >> M;
	map = vector<vector<int>>(N, vector<int>(M));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	const int dx[] = { 0, -1, 0, 1 };
	const int dy[] = { 1, 0, -1, 0 };

	// 국가 탐색
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			for (int i = 0; i < 4; i++)
			{
				if (!map[y][x]) continue;
				if (map[y][x] >= 'A') break;

				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx > M - 1 || ny > N - 1) continue;

				if (map[ny][nx] >= 'A') map[y][x] = map[ny][nx];
			}

			if (map[y][x] == 1)
			{
				int nx = x + 1;
				int ny = y - 1;
				if (!(nx < 0 || ny < 0 || nx > M - 1 || ny > N - 1) && map[ny][nx] >= 'A' && map[y][nx] == 1)
				{
					map[y][x] = map[ny][nx];
				}
				else
				{
					map[y][x] = country_idx++;
				}
			}
		}
	}

	country_count = country_idx - 'A';

	graph = vector<vector<int>>(country_count, vector<int>(country_count));

	cout << endl;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << (map[i][j] ? (char)map[i][j] : ' ') << " ";
		cout << endl;
	}

	// 다리 탐색
	for (int i = 0; i < 2; i++)
	{
		for (int y = 0; y < (i ? M : N); y++)
		{
			int x = 0;

			while (i ? x < N - 1 && !map[x][y] : x < M - 1 && !map[y][x]) x++;
			if (x > M - 4) continue; // 다리 존재 요건 미충족

			while (x < M - 3)
			{
				//1번땅 왼쪽끝에서 2번땅 왼쪽끝까지 탐색 반복
				while (i ? x < N - 1 && map[x][y] : x < M - 1 && map[y][x]) x++; // 1번땅 오른쪽 끝 탐색
				int end_l = x - 1;
				if ((i ? map[end_l][y] : map[y][end_l]) == 0) break;

				//1번땅 오른쪽끝에서 2번땅 왼쪽끝까지 탐색 반복
				while (i ? x < N - 1 && !map[x][y] : x < M - 1 && !map[y][x]) x++; // 2번땅 왼쪽 끝 탐색
				int start_r = x;
				if ((i ? map[start_r][y] : map[y][start_r]) == 0) break;

				if (start_r - end_l > 2)
				{
					if (i)
					{
						int tmp = graph[map[end_l][y] - 'A'][map[start_r][y] - 'A'];
						graph[map[end_l][y] - 'A'][map[start_r][y] - 'A'] = (tmp ? min(tmp, start_r - end_l - 1) : start_r - end_l - 1);
						graph[map[start_r][y] - 'A'][map[end_l][y] - 'A'] = (tmp ? min(tmp, start_r - end_l - 1) : start_r - end_l - 1);
					}
					else
					{
						int tmp = graph[map[y][end_l] - 'A'][map[y][start_r] - 'A'];
						graph[map[y][end_l] - 'A'][map[y][start_r] - 'A'] = (tmp ? min(tmp, start_r - end_l - 1) : start_r - end_l - 1);
						graph[map[y][start_r] - 'A'][map[y][end_l] - 'A'] = (tmp ? min(tmp, start_r - end_l - 1) : start_r - end_l - 1);
					}
				}
			}
		}
	}

	// 다리 최소 길이 탐색
	run(0, 0);

	cout << minimum;
	
	return 0;
}