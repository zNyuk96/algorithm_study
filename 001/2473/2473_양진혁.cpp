#include <iostream>
#include <algorithm>

using namespace std;
int n;
long long arr[5001];
int res[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	long long min = 0xFFFFFFFFFFFF;
	int s, e, m;
	long long target;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n-1; j++) {
			s = j + 1;
			e = n-1;
			target = arr[i] + arr[j];
			while (s <= e) {
				m = s + e >> 1;
				if (e == s) {
					if (min > abs(arr[s] + target)) {
						min = abs(arr[s] + target);
						res[0] = i;
						res[1] = j;
						res[2] = s;
					}
					if (e + 1 < n) {
						if (min > abs(arr[e+1] + target)) {
							min = abs(arr[e+1] + target);
							res[0] = i;
							res[1] = j;
							res[2] = e+1;
						}
					}
					if (s - 1 > j) {
						if (min > abs(arr[s- 1] + target)) {
							min = abs(arr[s- 1] + target);
							res[0] = i;
							res[1] = j;
							res[2] = s-1;
						}
					}
					break;
				}
				if (arr[m] + target < 0) {
					s = m + 1;
				}
				else e = m;
			}
		}
	}
	cout << arr[res[0]]<<" " << arr[res[1]]<< " " << arr[res[2]];
}