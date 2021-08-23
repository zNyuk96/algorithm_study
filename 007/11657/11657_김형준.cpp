#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, M;
vector<vector<int>> graph(500);
int w[500][500];
long long d[500];

int main()
{
	int flag = 0;

	cin >> N >> M;

	int m = M;
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		if (!w[a][b])
		{
			graph[a].push_back(b);
			w[a][b] = c;
		}	
		else
		{
			w[a][b] = min(w[a][b], c);
		}	
	}

	fill(d, d + 500, INF);
	d[0] = 0;

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < graph[i].size(); j++)
			{
				int now = i;
				int next = graph[i][j];
				int cost = w[now][next];

				if (d[now] == INF) continue;

				if (d[next] > d[now] + cost) 
				{
					if (k == N - 1)
						flag = 1;
					else
						d[next] = d[now] + cost;
				}
			}
		}
	}
	
	if (flag)
		cout << -1 << endl;
	else
		for (int i = 1; i < N; i++)
			cout << (d[i] != INF ? d[i] : -1) << endl;

	return 0;
}