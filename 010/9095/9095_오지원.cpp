#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> express = { 1, 2, 4 };	// #각 배열의 인덱스는 그 인덱스에 해당하는 숫자+1의 표현가능한 가지수를 저장함
	int test_case;

	cin >> test_case;

	for (int i = 3; i < 11; i++)
		// ##num은 1 + (num-1)의 표현, 2 + (num-2)의 표현, 3 + (num-3)의 표현 로 이루어짐
		express.push_back(express[i - 1] + express[i - 2] + express[i - 3]);	

	for (int i = 0, data; i < test_case; i++) {
		cin >> data;
		cout << express[data - 1] << "\n";
	}

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

	int T;
	std::vector<int> data;
	std::vector<int> dp = { 0, 1,2,4 };

	void calculate(int value) {
		dp.assign(value + 1, 0);
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int k = 4; k <= value; k++) {
			dp[k] = dp[k - 1] + dp[k - 2] + dp[k - 3];
		}
	}

	int main() {
		scanf("%d", &T);
		for (int k = 0; k < T; k++) {
			int value;
			scanf("%d", &value);
			data.emplace_back(value);
		}
		calculate(*std::max_element(data.begin(), data.end()));
		for (int k = 0; k < T; k++) {
			printf("%d\n", dp[data[k]]);
		}
	}
	return 0;
}