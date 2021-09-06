#include <iostream>
#include <algorithm>
using namespace std;

struct Schedule
{
	long long start;
	long long end;
	long long count;

	bool operator<(Schedule x) { return end < x.end; }
};

struct Schedule s[100000];
long long max_count[100000]; // i번째 start 전에 존재할 수 있는 최대 인원수 + 현재 회의 인원수
long long max_index, max_value;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> s[i].start >> s[i].end >> s[i].count;
	sort(s, s + N);

	for (int i = 0; i < N; i++)
	{
		max_count[i] = s[i].count;
		for (int j = 0; j <= i; j++) // 시간 초과 O(N^2/2)? = 50억 // 매번 갱신 X
		//for (int j = max_index; j <= i; j++) // 틀림 아마 과거의 최대값이 최적값이 아니라서 그런듯
			if (s[i].start >= s[j].end)
			{
				if (max_count[i] < max_count[j] + s[i].count) max_count[i] = max_count[j] + s[i].count;
				if (max_value < max_count[i]) {
					//max_index = j;
					max_value = max_count[i];
				}
			}
	}

	cout << max_value;

	return 0;
}