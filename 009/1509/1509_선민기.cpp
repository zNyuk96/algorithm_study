#include<iostream>
#include<vector>

using namespace std;

int main() {
	string text;
	vector<vector<int>> memo;
	vector<int> answer;

	cin >> text;

	memo = vector<vector<int>>(text.length(), vector<int>(text.length(), 0));
	answer = vector<int>(text.length(), 2500);

	for (int col = 0; col < text.length(); col++) {
		for (int row = 0; row < text.length() - col; row++) {
			if (col == 0) {
				memo[row][row + col] = 1;
				continue;
			}

			if (text[row] == text[row + col] && memo[row + 1][row + col - 1] != -1)
				memo[row][row + col] = memo[row + 1][row + col - 1] + 2;
			else
				memo[row][row + col] = -1;
		}
	}

	for (int col = 0; col < text.length(); col++) {
		for (int row = 0; row < text.length(); row++) {
			if (memo[row][col] != -1) {
				if (col - memo[row][col] >= 0)
					answer[col] = min(answer[col], answer[col - memo[row][col]] + 1);
				else
					answer[col] = min(answer[col], 1);
			}
		}
	}

	cout << answer[text.length() - 1] << endl;

	return 0;
}