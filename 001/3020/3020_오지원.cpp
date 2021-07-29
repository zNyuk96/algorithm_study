#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

std::vector<int> top;
std::vector<int> bottom;
int N, H;

std::pair<int, int> calculate() {
	int ans = INT_MAX;
	int count = 0;
	for (int k = 1; k <= H; k++) {
		int bottom_value = std::distance(std::lower_bound(bottom.begin(), bottom.end(), k), bottom.end());
		int top_value = std::distance(std::lower_bound(top.begin(), top.end(), H - k + 1), top.end());
		if (ans == bottom_value + top_value) count++;
		else if (ans > bottom_value + top_value) {
			ans = bottom_value + top_value;
			count = 1;
		}
	}
	return std::make_pair(ans, count);
}

int main() {
	scanf("%d %d", &N, &H);
	for (int k = 0; k < N; k++) {
		int value;
		scanf("%d", &value);
		if (k % 2 == 0) bottom.emplace_back(value);
		else top.emplace_back(value);
	}
	std::sort(top.begin(), top.end());
	std::sort(bottom.begin(), bottom.end());
	auto rst = calculate();

	printf("%d %d", rst.first, rst.second);

}