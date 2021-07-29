#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

long long N, M;
std::vector<long long> entrance;

long long calculate() {
	long long begin = 0;
	long long end = entrance[N - 1] * M;

	long long ans = LLONG_MAX;

	while (begin <= end) {
		long long mid = (begin + end) / 2;

		long long sum = 0;
		for (int k = 0; k < N; k++) sum += mid / entrance[k];

		if (sum >= M) {
			ans = std::min(ans, mid);
			end = mid - 1;
		}
		else {
			begin = mid + 1;
		}
	}
	return ans;
}

int main() {
	scanf("%d %d", &N, &M);
	entrance.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%d", &entrance[k]);
	}
	std::sort(entrance.begin(), entrance.end());
	printf("%lli", calculate());
}