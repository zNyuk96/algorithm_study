#include <iostream>
#include <vector>
#include <limits.h>

long long N, M;
bool cycle = false;
std::vector < std::vector<std::pair<long long, long long> > > connected;
std::vector<long long> weight;

void calculate() {
	weight[1] = 0;

	for (long long i = 1; i <= N; i++) {
		for (long long j = 1; j <= N; j++) {
			for (long long k = 0; k < connected[j].size(); k++) {
				if (weight[j] != LLONG_MAX && weight[connected[j][k].first] > weight[j] + connected[j][k].second) {
					weight[connected[j][k].first] = weight[j] + connected[j][k].second;
					if (i == N) cycle = true;
				}
			}
		}
	}

}

int main() {
	scanf("%lld %lld", &N, &M);
	connected.assign(N + 1, std::vector<std::pair<long long, long long> >());
	weight.assign(N + 1, LLONG_MAX);
	for (int k = 0; k < M; k++) {
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		connected[a].emplace_back(std::make_pair(b, c));
	}

	calculate();
	if (cycle) printf("-1\n");
	else {
		for (int k = 2; k <= N; k++) {
			if (weight[k] == LLONG_MAX) printf("-1\n");
			else printf("%lld\n", weight[k]);
		}
	}

}