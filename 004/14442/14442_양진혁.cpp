#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

int width, height;
int K;
char map[1001][1001];
int v[10][1001][1001] = { 0, };
int count[10][1001][1001] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int flag = 0;
/*
	tuple로 x,y,crash를 줘서 crash가 1인 경우는 걍 경로진행만,
	crash가 0 인 경우에는 경로진행 + crash 까지 해서 큐에 넣어주자.
*/
void BFS() {
	std::queue<std::tuple<int, int, int>> q;
	q.push({ 0,0,0 });
	v[0][0][0] = 1;
	count[0][0][0] = 1;
	while (!q.empty()) {
		int xx = std::get<0>(q.front());
		int yy = std::get<1>(q.front());
 		int crash = std::get<2>(q.front());
		q.pop();
		if (crash < K) {
			for (int i = 0; i < 4; i++) {
				int sx = xx + dx[i];
				int sy = yy + dy[i];
				if (sx >= 0 && sy >= 0 && sx < width && sy < height&&map[sy][sx]=='1' && (v[crash+1][sy][sx] == 0 || count[crash+1][sy][sx] > count[crash][yy][xx] + 1)) {
					count[crash+1][sy][sx] = count[crash][yy][xx] + 1;
					v[crash+1][sy][sx] = 1;
					q.push({ sx,sy,crash+1 });
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int sx = xx + dx[i];
			int sy = yy + dy[i];
			if (sx >= 0 && sy >= 0 && sx < width && sy < height && map[sy][sx] != '1' && (v[crash][sy][sx] == 0 || count[crash][sy][sx] > count[crash][yy][xx]+ 1)) {
				count[crash][sy][sx] = count[crash][yy][xx] + 1;
				v[crash][sy][sx] = 1;
				q.push({ sx,sy,crash });
			}
		}
	}
}
int main() {
	std::cin >> height >> width >> K;
	for (int i = 0; i < height; i++) {
		std::cin >> map[i];
	}
	BFS();
	int MIN = 123456789;
	for (int i = 0; i <= K; i++) {
		int a = count[i][height - 1][width - 1];
		if(a!=0) MIN = (MIN < a) ? MIN : a;
		
	}
	if (MIN == 1234567890) std::cout << -1;
	else std::cout << MIN ;

}