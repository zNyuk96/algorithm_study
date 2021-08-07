#include <iostream>
#include <vector>
#include <queue>


using namespace std;

queue<int> todo;
int used[1000];
vector<vector<int>> DDUCK;
int N;
vector<int> res;
int dfs(int depth, int prev) {
	if (depth == N) return 1;
	for (int j = 0; j < DDUCK[depth].size(); j++) {
		if (DDUCK[depth][j] != prev) {
			res.push_back(DDUCK[depth][j]);
			if (dfs(depth + 1, DDUCK[depth][j])) {
				return 1;
			}
			else res.pop_back();
		}
	}
	return 0;
}
int arr[1000];
void find_erase(int idx) {
	int target = DDUCK[idx][0];
	if (idx > 0) {
		for (int i = 0; i < DDUCK[idx-1].size(); i++) {
			if (DDUCK[idx-1][i] == target) {
				DDUCK[idx-1].erase(DDUCK[idx-1].begin() + i);
				if (used[idx - 1] == 0) {
					used[idx - 1] = 1;
					todo.push(idx - 1);
				}
				arr[idx - 1]--;
				break;
			}
		}
	}
	else if (idx > 0) {
		for (int i = 0; i < DDUCK[idx+1].size(); i++) {
			if (DDUCK[idx+1][i] == target) {
				DDUCK[idx+1].erase(DDUCK[idx+1].begin() + i);
				if (used[idx + 1] == 0) {
					used[idx + 1] = 1;
					todo.push(idx + 1);
				}
				arr[idx + 1]--;
				break;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	DDUCK.assign(N+1, vector<int>());
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr[i] = num;
		for (int j = 0; j < num; j++) {
			int temp;
			cin >> temp;
			DDUCK[i].push_back(temp);
		}
	}
	for (int i = 0; i < N; i++) {
		if (arr[i] <= 1) {
			todo.push(i);
		}
	}
	while (!todo.empty()) {
		int idx = todo.front();
		used[idx] = 0;
		todo.pop();
		if (arr[idx] < 1) {
			cout << -1;
			return 0;
		}
		find_erase(idx);

	}
	if (dfs(0, 0)) {
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << endl;
		}
	}
	else cout << -1;
}