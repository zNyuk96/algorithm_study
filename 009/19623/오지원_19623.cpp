#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <limits.h>
#include <numeric>
#include <math.h>

//끝난시간, 시작시간, 사람들
std::vector< std::tuple<int, int, int> > data;
int N;

//끝난시간, 이제까지 사람들
std::vector< std::pair<int, int> > dp;

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	return a.first < b.first;
}

void calculate() {
	dp.emplace_back(std::make_pair(0, 0));
	for (int k = 0; k < data.size(); k++) {
		auto front = data[k];
		int p_finish, p_start, p_people;
		std::tie(p_finish, p_start, p_people) = front;

		auto index = std::lower_bound(dp.begin(), dp.end(), std::make_pair(p_start, 0), cmp) - 1;
		int max_people = std::max(p_people + index->second, dp.back().second);
		dp.emplace_back(std::make_pair(p_finish, max_people));
	}
	printf("%d", dp.back().second);
}

int main() {
	scanf("%d", &N);
	for (int k = 0; k < N; k++) {
		int start, finish, people;
		scanf("%d %d %d", &start, &finish, &people);
		data.emplace_back(std::make_tuple(finish, start, people));
	}
	std::sort(data.begin(), data.end());
	calculate();
}