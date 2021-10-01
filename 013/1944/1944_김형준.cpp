#include <iostream>
#include <queue>
using namespace std;

#define S 0

struct Node {
	int start;
	pair<int, int> pos;
	int distance;
};

char map[50][50];
int visited[251][50][50];
int key[50][50];
int group[251];
int groupCnt[251];

struct comp {

	int operator()(pair<pair<int, int>, int> I, pair<pair<int, int>, int> C)
	{
		if (I.second != C.second) return I.second > C.second;
		if (I.first.first != C.first.first) return I.first.first > C.first.first;
		return I.first.second > C.first.second;
	}
};

int findBoss(int x)
{
	return (x == group[x]) ? x : findBoss(group[x]);
}

int setUnion(int x, int y)
{
	int xBoss = findBoss(x);
	int yBoss = findBoss(y);
	if (xBoss == yBoss) return 0;
	group[yBoss] = xBoss;
	groupCnt[xBoss] += groupCnt[yBoss];
	groupCnt[yBoss] = 0;
	return 1;
}

int main() {
	int N, M, K = 1;
	int flag = 0;
	int result = 0;

	queue<Node> q;
	priority_queue< pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, comp> pq;

	cin >> N >> M;
	for (int y = 0; y < N; y++)
	{
		cin >> map[y];

		for (int x = 0; x < N; x++)
		{
			if (map[y][x] == 'S')
			{
				group[S] = S;
				groupCnt[S] = 1;

				q.push({ S, {y,x}, 0 });
				visited[S][y][x] = true;
			}
			else if (map[y][x] == 'K')
			{
				group[K] = K;
				groupCnt[K] = 1;
				key[y][x] = K++;
			}
		}
	}

	while (!q.empty())
	{
		int y = q.front().pos.first;
		int x = q.front().pos.second;
		int d = q.front().distance;
		int s = q.front().start;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			const int dy[] = { 1, -1, 0, 0 };
			const int dx[] = { 0, 0, -1, 1 };
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny > N - 1 || nx > N - 1) continue;
			if (map[ny][nx] == '1') continue;
			if (visited[s][ny][nx]) continue;
			visited[s][ny][nx] = 1;
			q.push({ s, {ny, nx}, d + 1 });

			if (map[ny][nx] == 'K')
			{
				visited[key[ny][nx]][ny][nx] = 1;
				q.push({ key[ny][nx], {ny, nx}, 0 });
				pq.push({ { s, key[ny][nx] }, d + 1 });
			}
		}
	}

	while (!pq.empty())
	{
		int s = pq.top().first.first;
		int e = pq.top().first.second;
		int d = pq.top().second;
		pq.pop();

		if (setUnion(s, e))
		{
			result += d;
			if (flag |= (groupCnt[findBoss(s)] == K)) break;
		}
	}

	cout << (flag ? result : -1);

	return 0;
}