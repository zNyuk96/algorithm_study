#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <limits.h>

int N, M, K;
std::vector< std::vector<int> > map;
std::vector < std::vector< std::vector<bool> > > visited;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int ans = INT_MAX;

void calculate() {
	std::queue< std::tuple<int, int, int, int> > q;
	q.emplace(std::make_tuple(0, 0, 0, 1));
	visited[0][0][0] = true;

	while (!q.empty()) {
		int x, y, z, count;
		std::tie(x, y, z, count) = q.front();
		q.pop();

		if (x == N - 1 && y == M - 1) {
			ans = std::min(ans, count);
			return;
		}

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (z + 1 <= K) {
					if (map[nx][ny] == 1 && !visited[nx][ny][z + 1]) {
						q.emplace(std::make_tuple(nx, ny, z + 1, count + 1));
						visited[nx][ny][z + 1] = true;
					}
				}
				if (map[nx][ny] == 0 && !visited[nx][ny][z]) {
					q.emplace(std::make_tuple(nx, ny, z, count + 1));
					visited[nx][ny][z] = true;
				}
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	map.assign(N, std::vector<int>(M, 0));
	visited.assign(N, std::vector< std::vector<bool> >(M, std::vector<bool>(K + 1, false)));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	calculate();
	printf("%d", ans == INT_MAX ? -1 : ans);
}