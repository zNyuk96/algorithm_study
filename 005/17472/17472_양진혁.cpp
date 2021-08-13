#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 어차피 중간에 못꺾는다면, 그냥 좌상단 끝 좌표랑 우하단 끝 좌표를 기점으로, x 와 y 의 max 와 min 을 얻고, 이 값을 기준으로 다른 섬과의 차이 중 가장 짧은 것이 
// 그러면 근데 ㅜ ㅗ ㅓ ㅏ 형의 섬이 예외로 잡히네
// 각 섬에서 근처의 섬 하나 연결 하고 대신 이미 연결되어있지 않은 섬으로 .. 예외 케이스 생길 수 있는지 확인해보자.. 는 3개짜리 루프 돌면 가능해서 안되네
// 그냥 섬이 최대 6개니까..(가로+세로)^5*100 가면 3억정도 되네.. 1초짜리라 흠.. 근데 또 0이면 search 할 필요가 없응께 ㄱㅊ은가
// A B C D E F  가 있다고하면,
// A 먼저 연결

/*
	1 0 1 0 0 1 0 1
	0 0 1 0 0 1 0 0
	1 0 1 0 0 1 0 1
	이 경우에 안될 것 같다.
*/
int N, M;
vector<vector<int>> map;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int find_road(int x, int y) {
	return 0;
}
int island_num;
vector<vector<pair<int, int>>> group;

void build_island() {
	int next = 2;
	queue<pair<int, int>> todo;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				todo.push({ i,j });
				while (!todo.empty()) {
					int x = todo.front().second;
					int y = todo.front().first;
					map[y][x] = next;
					group[map[y][x]].push_back({ x,y });
					todo.pop();
					for (int d = 0; d < 4; d++) {
						int xx = x + dx[d];
						int yy = y + dy[d];
						if (yy >= 0 && yy < N && xx >= 0 && xx < M && map[yy][xx] == 1) {
							todo.push({ yy,xx });
						}
					}
				}
				next++;
			}
		}
	}
	island_num = next - 2;
}
int bridge[9][9];
bool is_connected() {
	queue<int> q;
	q.push(2);
	int tempv[10] = { 0, };
	tempv[2] = 1;
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 2; i < 9; i++) {
			if (bridge[current][i] && tempv[i] == 0) {
				tempv[i] = 1;
				q.push(i);
			}
		}
	}
	for (int i = 2; i <= island_num; i++) {
		if (tempv[i] == 0) {
			return false;
		}
	}
	return true;
}
int v[9][9];
int search_br(int group_num, int acc) {
	int min = 0x7FFFFFFF;
	int sum = 0;
	for (int i = 2; i <= island_num + 1; i++) {
		for (int j = 2; j <= island_num + 1; j++) {
			sum += v[i][j];
		}
	}
	if (sum == island_num - 1) {
		if (is_connected()) return acc;
		else return min;
	}
	for (int i = 0; i < group[group_num].size(); i++) {
		int x = group[group_num][i].first;
		int y = group[group_num][i].second;
		for (int d = 0; d < 4; d++) {
			int xx = x;
			int yy = y;
			int br_len = 0, to = 0;
			while (1) {
				xx += dx[d];
				yy += dy[d];
				if (xx < 0 || xx >= M || yy < 0 || yy >= N) break;
				else if (map[yy][xx] == 0) br_len++;
				else if (map[yy][xx] != map[y][x] && v[group_num][map[yy][xx]]!= 1) {
					to = map[yy][xx];
					break;
				}
				else if (map[yy][xx] == map[y][x]) {
					br_len = 0;
					break;
				}
			}
			if (br_len > 1 && to) {
				bridge[group_num][to] = 1;
				bridge[to][group_num] = 1;
				v[group_num][to] = 1;
				int temp = search_br(to, acc+br_len);
				min = min < temp ? min : temp;
				bridge[group_num][to] = 0;
				bridge[to][group_num] = 0;
				v[group_num][to] = 0;
			}
		}
	}
	return min;
}
int main() {
	cin >> N >> M;
	group.assign(9, vector<pair<int, int>>());
	map.assign(N, vector<int>());
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			map[i].push_back(temp);
		}
	}
	build_island();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout<<map[i][j] << " ";
		}
		cout << endl;
	}
	int res = search_br(2,0);
	if (res == 0x7FFFFFFF) cout << -1;
	else cout << res;
}