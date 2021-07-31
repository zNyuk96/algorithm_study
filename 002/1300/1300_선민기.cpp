#include<iostream>
#include<numeric>
#include<math.h>

using namespace std;

int main() {
	long long n, k, less_cnt;
	long long start, middle, end;

	cin >> n;
	cin >> k;
	start = 1;
	end = powl(n, 2);

	while (start < end) {
		middle = (start + end) / 2;
		less_cnt = 0;

		for (int i = 1; i <= n; i++)
			less_cnt += min(n, (long long)(middle / i));

		if (less_cnt < k)
			start = middle + 1;
		else
			end = middle;
	}

	cout << start << endl;

	return 0;
}