#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

//지원 테케랑 임의 예시 모두 통과
//런타임 에러 생성

long long N;
std::vector< std::vector<long long> > capture;
std::priority_queue< std::pair<int, int> > pq;

bool is_ok(long long ball_speed, long long ball_loc) {
	long long level = 1;
	long long n_ball_loc = ball_loc;
	while (level <= N) {
		n_ball_loc += ball_speed;
		if (n_ball_loc != *std::lower_bound(capture[level].begin(), capture[level].end(), n_ball_loc)) return false;
		level++;
	}
	return true;
}


int main() {
	scanf("%lld", &N);
	capture.assign(N + 1, std::vector<long long>(N, 0));
	visited.assign(N + 2, std::vector<bool>(N, 0));

	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%lld", &capture[i][j]);
		}
		std::sort(capture[i].begin(), capture[i].end());
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			long long ball_loc = capture[0][i];
			long long ball_speed = capture[1][j] - capture[0][i];
			if (is_ok(ball_speed, ball_loc)) {
				pq.emplace(std::make_pair(-1 * ball_loc, ball_speed));
			}
		}
	}

	for (int k = 0; k < N; k++) {
		auto front = pq.front();
		pq.pop();
		printf("%lld %lld\n", front.first * -1, front.second);
	}
}