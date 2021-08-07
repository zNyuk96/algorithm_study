#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
/* 
N 개의 벡터의 M개의 매핑 정보 담고,
depth 에 도달하면 1 아니면 0
*/
vector<vector<int>> map;
int N, M;
int used_in_dfs[2001];
int dfs(int from, int depth ) {
	if (depth == 4) return 1;

	for (int i = 0; i < map[from].size(); i++) {
		int next = map[from][i];
		if (used_in_dfs[next]) continue;
		else {
			used_in_dfs[next] = 1;
			if (dfs(next, depth + 1)) return 1;
			used_in_dfs[next] = 0;
		}
		
	}
	return 0;
}

int main() {
	cin >> N >> M;
	map.assign(N, vector<int>());

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[b].push_back(a);
		map[a].push_back(b);
	}
	int res = 0;
	for (int i = 0; i < N; i++) {
		used_in_dfs[i] = 1;
		res += dfs(i,0);
		used_in_dfs[i] = 0;
		if (res > 0) break;
	}
	cout << res;
}