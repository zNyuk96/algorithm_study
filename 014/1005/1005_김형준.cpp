#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int graph[1000][1000];
int indegree[1000];
long long etime[1000];

int main() {
	int T;
	cin >> T;
	
	while (T--)
	{
		memset(graph, 0, sizeof(int) * 1000 * 1000);
		memset(indegree, 0, sizeof(int) * 1000);
		memset(etime, 0, sizeof(int) * 1000);

		int N, K;
		cin >> N >> K;

		long long D[1000];
		for (int i = 0; i < N; i++) cin >> D[i];

		for (long long i = 0, X, Y; i < K; i++)
		{
			cin >> X >> Y; 
			graph[X - 1][Y - 1] = 1;
			indegree[Y - 1]++;
		}

		int W;
		cin >> W;

		queue<int> q;
		for (int i = 0; i < N; i++)
			if (!indegree[i])
			{
				q.push(i);
				etime[i] = D[i];
			}

		while (!q.empty())
		{
			int now = q.front();
			q.pop();

			for (int next = 0; next < N; next++)
			{
				if (!graph[now][next]) continue;
				if (!--indegree[next]) q.push(next);
				etime[next] = max(etime[next], etime[now] + D[next]);
			}
		}

		cout << etime[W - 1] << "\n";
	}

	return 0;
}