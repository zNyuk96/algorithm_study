﻿#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <math.h>
#include <limits.h>

int N;
std::vector<long long> value;
std::vector<long long> ans(3, 0);
long long ans_val = LLONG_MAX;

void calculate() {

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			long long two_sum = value[i] + value[j];
			//이거 앞뒤 전후에 최적 값이 들어가 있음.
			int three_index = std::distance(value.begin(), std::lower_bound(value.begin(), value.end(), two_sum * -1));
			if (three_index < N && i != three_index && j != three_index) {
				if (llabs(two_sum + value[three_index]) < ans_val) {
					ans[0] = value[i];
					ans[1] = value[j];
					ans[2] = value[three_index];
					ans_val = llabs(two_sum + value[three_index]);
				}
			}

			if (three_index > 0 && i != three_index - 1 && j != three_index - 1) {
				if (llabs(two_sum + value[three_index - 1]) < ans_val) {
					ans[0] = value[i];
					ans[1] = value[j];
					ans[2] = value[three_index - 1];
					ans_val = llabs(two_sum + value[three_index - 1]);
				}
			}


		}
	}
	std::sort(ans.begin(), ans.end());
	return;
}

int main() {
	scanf("%d", &N);
	value.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%lld", &value[k]);
	}
	std::sort(value.begin(), value.end());

	calculate();
	printf("%lld %lld %lld", ans[0], ans[1], ans[2]);

}