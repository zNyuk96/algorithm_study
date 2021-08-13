#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int N;
vector<int> vec;
vector<tuple<int, int, int>> result;
int answer;

// 27%에서 틀림
// 반례 못찾음

int main() {
	cin >> N;
	vec = vector<int>(N);

	for (int i = 0 ; i < N; i++) cin >> vec[i];
	sort(vec.begin(), vec.end());

	/*for (int i = 0; i < N; i++)
		cout << vec[i] << " ";

	cout << endl;*/

	for (int i = 0; i < N; i++)
	{
		int left = i + 1;
		int right = N - 1;

		while (left < right)
		{
			const int a = vec[i];
			const int b = vec[left];
			const int c = vec[right];

			if (a + b < 0)
			{
				if (a + b + c > 0) right--;
				else if (a + b + c < 0) left++;
				else
				{
					if (b == c) {
						answer += (right - left + 1) * (right - left) / 2;
						/*for (int j = 0; j < (right - left + 1) * (right - left) / 2; j++) 
							result.push_back({ a, b, c });*/
						break;
					}
					else
					{
						int l = 1, r = 1;
						while (vec[left] == vec[left + 1]) { l++; left++; }
						while (vec[right] == vec[right - 1]) { r++; right--; }
						
						answer += l * r;
						/*for (int j = 0; j < l * r; j++) 
							result.push_back({ a, b, c });*/

						left++;
						right--;
					}
				};
			}
			else break;
		}		
	}

	for (int i = 0; i < result.size(); i++)
		cout << "(" << get<0>(result[i]) << "," << get<1>(result[i]) << "," << get<2>(result[i]) << ")\n";

	cout << answer;
}