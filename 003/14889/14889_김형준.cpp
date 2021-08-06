#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> S;
int ab_sum;
int used[20];
vector<int> a_path, b_path;
int minimum = 10000000;

int contain(int n)
{
	for (int j = 0; j < a_path.size(); j++)
		if (n == a_path[j]) return 1;
	return 0;
}

void run(int level) {
	if (level == N / 2)
	{
		// A팀 완성시 B팀은 자동 완성
		b_path.clear();

		for (int i = 0; i < N; i++)
			if (!contain(i)) b_path.push_back(i);

		int a_sum = 0;
		int b_sum = 0;

		// A팀 값
		for (int i = 0; i < a_path.size(); i++)
			for (int j = i + 1; j < a_path.size(); j++)
				a_sum += S[a_path[i]][a_path[j]] + S[a_path[j]][a_path[i]];

		// B팀 값
		for (int i = 0; i < b_path.size(); i++)
			for (int j = i + 1; j < b_path.size(); j++)
				b_sum += S[b_path[i]][b_path[j]] + S[b_path[j]][b_path[i]];

		minimum = min(minimum, abs(a_sum - b_sum));

		return;
	}

	// A팀 탐색

	for (int i = level; i < N; i++)
	{
		if (used[i]) continue;
		if (level > 0 && a_path[level-1] > i) continue;
		used[i]++;
		a_path.push_back(i);
		run(level + 1);
		a_path.pop_back();
		used[i]--;
	}
	
}

int main() {
	cin >> N;
	S.assign(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> S[i][j];

	run(0);

	cout << minimum;

	return 0;
}