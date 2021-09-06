#include<iostream>
#include<map>

using namespace std;

int main() {
	int n_stock, limit, answer = 0;
	int weight, satisfaction, cnt, package, cur_package;
	map<int, int> backpack, prev_backpack;

	cin >> n_stock >> limit;
	backpack[0] = 0;

	for (int i = 0; i < n_stock; i++) {
		scanf("%d %d %d", &weight, &satisfaction, &cnt);
		package = 1;

		while (cnt > 0) {
			prev_backpack = map<int, int>(backpack);
			cur_package = min(package, cnt);

			for (auto e : prev_backpack) {
				if (e.first + cur_package * weight > limit)
					continue;

				if (backpack.find(e.first + cur_package * weight) == backpack.end())
					backpack[e.first + cur_package * weight] = 0;

				backpack[e.first + cur_package * weight] = max(backpack[e.first + cur_package * weight], cur_package * satisfaction + e.second);
			}

			cnt -= cur_package;
			package <<= 1;
		}
	}

	for (auto e : backpack) {
		if (e.second > answer)
			answer = e.second;
	}

	cout << answer << endl;

	return 0;
}