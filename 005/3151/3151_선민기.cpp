#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, answer = 0;
	vector<int> member;
	int diff, high, low;

	cin >> n;
	
	member = vector<int>(n);
	
	for (int i = 0; i < n; i++) {
		cin >> member[i];
	}

	sort(member.begin(), member.end());
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			diff = -(member[i] + member[j]);
			high = upper_bound(member.begin() + i + 1, member.end() + j, diff) - member.begin();
			low = lower_bound(member.begin() + i + 1, member.begin() + high, diff) - member.begin();
			answer += high - low;
		}
	}
	cout << answer << endl;

	cout << lower_bound(member.begin() + 3, member.begin() + 3, diff) - member.begin() << endl;

	return 0;
}