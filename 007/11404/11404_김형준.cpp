#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, M;
int d[100][100];

int main() {
	fill(d[0], d[0] + 100 * 100, INF);
	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++)
		d[i][i] = 0;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		d[a-1][b-1] = min(d[a-1][b-1], c);
	}

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << (d[i][j] != INF ? d[i][j] : 0) << " ";
		cout << endl;
	}
	
    return 0;
}