#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <limits.h>
#include <algorithm>

int N, M;
std::vector< std::vector<int> > connected;

void calculate() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (connected[j][i] != INT_MAX && connected[i][k] != INT_MAX) {
					connected[j][k] = std::min(connected[j][k], connected[j][i] + connected[i][k]);
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	connected.assign(N + 1, std::vector<int>(N + 1, INT_MAX));
	for (int k = 1; k <= N; k++) {
		connected[k][k] = 0;
	}
	for (int k = 0; k < M; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		connected[a][b] = std::min(connected[a][b], c);
	}
	calculate();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", connected[i][j] == INT_MAX ? 0 : connected[i][j]);
		}
		printf("\n");
	}
}