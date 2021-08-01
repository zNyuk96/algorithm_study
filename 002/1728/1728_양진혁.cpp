/*
y1= a1+x1+d1 이라 할 때,
주어지는 것은 y1과 d1 이고 x1은 같은 간격 이라는 조건 하에
x1==x2==x3...==xn 이다.

알 수 있는 것은
a1+a2+a3+...+an = 첫번쨰 줄과 두번째 줄의 차이값.
쉽게 말하면 결국 똑같은 방정식이 n+1 개 만큼 주어진 것.
일단 이렇게 가보자.
arr[n+1] 에 길이 들이 저장되어 있고,
기울기의 max 가 20억이라고 할때,
-20억에서 20억까지 가능한 기울기를 찾자
기울기에 대하여 BS
기울기 가져와서 count는 arr[0]부터arr[n]까지 돌면서 기울기의 룰을 따르는 값이 모두 있는지
모두 있다면 방정식안에서 그 기울기는 유일하고 다른 기울기를 간섭하지 않는다 라고 특정된다. n개의 기울기와 n 개의 식이 있으니까!

근데 counting 한 개수의 기울기가 있을까..?
이거 어케 극복..? 기울기 결과값이랑 계산해서 margin을..?

걍 맨 첨에 한 시작점마다 500개의 기울기 후보군이 있고
500개의 기울기 후보군에 대하여 500의 사진들에 대하여 자신의 다음 값이 있는지 확인하는것
근데 그럼 500(시작점)*500(기울기 후보)*500(사진개수)*500(사진 하나당 서치)
인데, 여기서 마지막 사진 하나당 서치를 log로 최적화 가능하다.

*/

#include <iostream>
#include <algorithm>
#include <vector>

#define MAX (int)0x7FFFFFFF;
#define MIN (int)0x80000000;

using namespace std;
int N;
vector<vector<int>> arr;
vector<pair<int, int>> res;
int slope[500];
int bs(int target, int idx) {
	int s = 0;
	int e = N - 1;
	int m;
	while (s < e) {
		m = s + e >> 1;
		if (arr[idx][m] < target) {
			s = m + 1;
		}
		else e = m;
	}
	if (arr[idx][e] == target) return 1;
	else return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	arr.assign(N+1, vector<int>());
	int temp;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			arr[i].push_back(temp);
		}
	}
	for (int i = 0; i <= N; i++) {
		sort(arr[i].begin(), arr[i].end());
	}
	int x;
	for (int i = 0; i < N; i++) {
		x = arr[0][i];
		int candidate;
		for (int j = 0; j < N; j++) {
			candidate = arr[1][j] - x;
			int flag = 0;
			for (int k = 2; k <= N; k++) {
				if (bs(candidate*k+x, k)) continue;
				else {
					flag = 1;
					break;
				}
			}
			if (flag) continue;
			else {
				arr[1].erase(arr[1].begin()+j);
				break;
			}
		}
		res.push_back({ x,candidate });
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].first << " " << res[i].second << endl;
	}

	return 0;
}