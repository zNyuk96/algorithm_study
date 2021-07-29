#include <iostream>
#include <algorithm>

using namespace std;
int N, H;
int bottom[100000] = { 0, };
int top[100000] = { 0, };

// dp로 하려다가 시간복잡도.. 
// BS 를 구현, 1 서치당 비용 N
// BS를 할려면 기울기가 필요한데 얘는 모르겠어.. 정리가 안돼
// 심플하게 아래서부터 위로 서치하면 줄어드는 기울기여야하니까 
// 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> H;
	for (int i = 0; i < N / 2; i++) {
		std::cin >> bottom[i] >> top[i];
	}
	sort(bottom, bottom + N / 2);
	sort(top, top + N / 2);
	int l, r;
	int min, mnum;
	min = 987654321;
	mnum = 0;
	for (int i = 1; i <= H; i++) {
		//l = bs1(0, N / 2, i);
		int s = 0, e = N / 2, target = i;
		while (s <= e) {
			if (s == e) {
				l = N / 2 - s;
				break;
			}
			int m = s + e >> 1;
			if (bottom[m] > target) {
				e = m;
			}
			else {
				s = m + 1;
			}
		}
		s = 0, e = N / 2, target = i;
		//r = bs2(0, N / 2, i);
		while (s <= e) {
			if (s == e) {
				r= N / 2 - s;
				break;
			}
			int m = s + e >> 1;
			if (H - top[m] > target) {
				s = m + 1;
			}
			else {
				e = m;
			}
		}
		if (min > l + r) {
			min = l + r;
			mnum = 1;
		}
		else if (l + r == min) {
			mnum++;
		}
	}
	std::cout << min << " " << mnum;
}