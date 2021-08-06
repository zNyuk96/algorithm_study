#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> candidate;
vector<char> path;
int dat[26];
int L, C;

void run(int level, int idx) {
	if (level == L)
	{
		int mo = dat['a' - 'a'] + dat['e' - 'a'] + dat['i' - 'a'] + dat['o' - 'a'] + dat['u' - 'a'];
		int ja = L - mo;

		if (mo >= 1 && ja >= 2)
		{
			for (char c : path) cout << c;
			cout << "\n";
		}	

		return;
	}

	for (int i = idx + 1; i < candidate.size(); i++)
	{
		dat[candidate[i] - 'a']++;
		path.push_back(candidate[i]);
		run(level + 1, i);
		path.pop_back();
		dat[candidate[i] - 'a']--;
	}
}

int main()
{
	cin >> L >> C;

	for (int i = 0; i < C; i++)
	{
		char buf;
		cin >> buf;
		candidate.push_back(buf);
	}

	sort(candidate.begin(), candidate.end());

	run(0, -1);

	return 0;
}