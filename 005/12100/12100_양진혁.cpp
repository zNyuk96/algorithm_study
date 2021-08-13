#include<iostream>
#include<vector>

using namespace std;

// 상하좌우 4^5 => 1024번 움직이는거 + N*N연산 최대연산 N*N*1024 ~ 4*e5
int N;
vector<vector<int>>map;
int find_max(vector<vector<int>> board) {
	int max = 0x80000000;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			max = max > board[i][j] ? max : board[i][j];
		}
	}
	return max;
}
int push_map(vector<vector<int>> board, int step) {
	if (step == 5) {
		return find_max(board);
	}
	int max = 0x80000000;
	vector<vector<int>> temp = board;
	for (int i = 0; i < N; i++) { //left;
		int thres = 0;
		for (int j = 1; j < N; j++) {
			int tempidx = j;
			while (tempidx - 1 >= thres && temp[i][tempidx - 1] == 0) tempidx--;
			if (tempidx - 1 >= thres && temp[i][tempidx - 1] == temp[i][j]) {
				temp[i][tempidx - 1] = temp[i][tempidx - 1] * 2;
				temp[i][j] = 0;							// 줄었을떄
				thres = tempidx;
			}
			else if (temp[i][tempidx] == 0) {
				temp[i][tempidx] = temp[i][j];
				temp[i][j] = 0;							// 빈칸없애면서 이동
			}
		}
	}
	int candidate = push_map(temp, step + 1);
	max = max > candidate ? max : candidate;
	temp = board;
	for (int i = 0; i < N; i++) {	//right
		int thres = N;
		for (int j = N - 2; j >= 0; j--) {
			int tempidx = j;
			while (tempidx + 1 < thres && temp[i][tempidx + 1] == 0) tempidx++;
			if (tempidx + 1 < thres && temp[i][tempidx + 1] == temp[i][j]) {
				temp[i][tempidx + 1] = temp[i][tempidx + 1] * 2;
				temp[i][j] = 0;
				thres = tempidx+1;// 줄었을떄
			}
			else if (temp[i][tempidx] == 0) {
				temp[i][tempidx] = temp[i][j];
				temp[i][j] = 0;							// 빈칸없애면서 이동
			}
		}
	}
	candidate = push_map(temp, step + 1);
	max = max > candidate ? max : candidate;
	temp = board;
	for (int j = 0; j < N; j++) {	//up
		int thres = 0;
		for (int i = 1; i < N; i++) {
			int tempidx = i;
			while (tempidx - 1 >= thres && temp[tempidx - 1][j] == 0) tempidx--;
			if (tempidx - 1 >= thres && temp[tempidx - 1][j] == temp[i][j]) {
				temp[tempidx - 1][j] = temp[tempidx - 1][j] * 2;
				temp[i][j] = 0;							// 줄었을떄
				thres = tempidx;
			}
			else if (temp[tempidx][j] == 0) {
				temp[tempidx][j] = temp[i][j];
				temp[i][j] = 0;							// 빈칸없애면서 이동
			}
		}
	}
	candidate = push_map(temp, step + 1);
	max = max > candidate ? max : candidate;
	temp = board;
	for (int j = 0; j < N; j++) {	//down
		int thres = N;
		for (int i = N - 2; i >= 0; i--) {
			int tempidx = i;
			while (tempidx + 1 < thres && temp[tempidx + 1][j] == 0) tempidx++;
			if (tempidx + 1 < thres && temp[tempidx + 1][j] == temp[i][j]) {
				temp[tempidx + 1][j] = temp[tempidx + 1][j] * 2;
				temp[i][j] = 0;							// 줄었을떄
				thres = tempidx+1;
			}
			else if (temp[tempidx][j] == 0) {
				temp[tempidx][j] = temp[i][j];
				temp[i][j] = 0;							// 빈칸없애면서 이동
			}
		}
	}
	candidate = push_map(temp, step + 1);
	max = max > candidate ? max : candidate;
	return max;
}
int main() {
	cin >> N;
	map.assign(N, vector<int>());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			map[i].push_back(temp);
		}
	}
	int x = push_map(map, 0);
	cout << x;
}
