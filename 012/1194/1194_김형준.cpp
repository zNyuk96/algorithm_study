#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef struct Node
{
	int y;
	int x;
	int k;
	int d;
} Node;

char a[51][51];
int v[51][51][64];
int min_dist = 1e9;

int main() {
	queue<Node*> q;
	int N, M;
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		cin >> a[y];
		for (int x = 0; x < M; x++)
			if (a[y][x] == '0')
			{
				memset(v, 0, sizeof(v));
				v[y][x][0] = 1;

				Node* newNode = new Node();
				newNode->y = y;
				newNode->x = x;
				newNode->k = 0;
				newNode->d = 0;
				q.push(newNode);
			}
	}

	int flag = 0;
	while (!q.empty())
	{
		int y = q.front()->y;
		int x = q.front()->x;
		int k = q.front()->k;
		int d = q.front()->d;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			const int dx[] = { 0,0,-1,1 };
			const int dy[] = { 1,-1,0,0 };

			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx > M - 1 || ny > N - 1) continue;
			if (a[ny][nx] == '#') continue;
			if (v[ny][nx][k]) continue;

			if (a[ny][nx] == '.' || a[ny][nx] == '0')
			{
				v[ny][nx][k] = 1;

				Node* newNode = new Node();
				newNode->y = ny;
				newNode->x = nx;
				newNode->k = k;
				newNode->d = d + 1;
				q.push(newNode);
			}
			else if (a[ny][nx] >= 'a' && a[ny][nx] <= 'f')
			{
				v[ny][nx][k | 1 << (a[ny][nx] - 'a')] = 1;
                
				Node* newNode = new Node();
				newNode->y = ny;
				newNode->x = nx;
				newNode->k = k | 1 << (a[ny][nx] - 'a');
				newNode->d = d + 1;
				q.push(newNode);
			}
			else if (a[ny][nx] >= 'A' && a[ny][nx] <= 'F')
			{
				if (k & (1 << (a[ny][nx] - 'A')))
				{
					v[ny][nx][k] = 1;

					Node* newNode = new Node();
					newNode->y = ny;
					newNode->x = nx;
					newNode->k = k;
					newNode->d = d + 1;
					q.push(newNode);
				}	
			}
			else if (a[ny][nx] == '1')
			{
				flag = 1;
				if (min_dist > d + 1) min_dist = d + 1;
			}
		}
	}

	cout << (flag ? min_dist : -1) << endl;

	return 0;
}