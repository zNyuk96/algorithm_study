#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

//지원 테케랑 임의 예시 모두 통과
//런타임 에러 생성

long long N;
std::vector< std::vector<long long> > capture;
std::vector< std::vector<bool> > visited;
bool flag = false;
std::queue< std::pair<long long, long long> > pq;

//p_ball_speed 예상되는 속력, p_ball_loc 현재 있을 loc, p_ball_loc_index : p_ball_loc가 몇번 인덱스에 있는지
void calculate(long long p_ball_loc, long long p_ball_speed, long long level, long long p_ball_loc_index) {

	if (visited[level][p_ball_loc_index]) return;
	visited[level][p_ball_loc_index] = true;

	if (level == N) {
		flag = true;
		return;
	}

	long long n_ball_loc = p_ball_loc + p_ball_speed;
	//same_index에는 예상되는 p_ball_loc에 공이 찍힌 적이 있는지를 확인한다.
	long long same_index = std::distance(capture[level + 1].begin(), std::lower_bound(capture[level + 1].begin(), capture[level + 1].end(), n_ball_loc));
	if (same_index == N || capture[level + 1][same_index] != n_ball_loc) {
		visited[level][p_ball_loc_index] = false;
		return;
	}
	//visited_index에는 same_index부터 visited가 맨 처음 false인 값의 인덱스를 확인한다.
	auto equal = std::equal_range(capture[level + 1].begin() + same_index, capture[level + 1].end(), capture[level + 1][same_index]);
	for (long long k = same_index; k < same_index + (equal.second - equal.first); k++) {
		if (!visited[level + 1][k]) {
			calculate(n_ball_loc, p_ball_speed, level + 1, k);
			if (!flag) visited[level + 1][k] = false;
			else break;
		}
	}

	return;
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
			if (i == 1 && j == 0) {
				printf("");
			}
			long long p_ball_loc = capture[1][j];
			long long p_ball_speed = capture[1][j] - capture[0][i];
			long long same_index = std::distance(capture[1].begin(), std::lower_bound(capture[1].begin(), capture[1].end(), p_ball_loc));
			auto equal = std::equal_range(capture[1].begin() + same_index, capture[1].end(), p_ball_loc);

			for (long long k = same_index; k < same_index + (equal.second - equal.first); k++) {
				if (!visited[1][k]) {
					calculate(p_ball_loc, p_ball_speed, 1, k);
					break;
				}
			}

			if (flag) {
				flag = false;
				pq.emplace(std::make_pair(-1 * capture[0][i], p_ball_speed));
				break;
			}
		}
	}

	for (int k = 0; k < N; k++) {
		auto front = pq.front();
		pq.pop();
		printf("%lld %lld\n", front.first * -1, front.second);
	}
}