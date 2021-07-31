/*
 예전엔 어케푼겨.. ㄷㄷ
 일단 counting sort 생각해봤는데 아무리 숫자가 겹친다해도 좀 그럼..
 10^10/2 정도 길이의 배열은 에바..
 k 가 타겟, N^2 에서 서치하는데,
 서치의 룰을 오름차순으로 쌓아가며 만들어야 하는데.. 어케해야하지
 k가 m^2 과 (m+1)^2 사이의 수라는 것을 얻어 내면..이건 아니고..
 N^2 자체가 그 자체 값이라는 개념에서 놀아보자.
 그렇다면, search 하는 값 m 의 개수 세는 룰은 1~N까지 나누면서 min(몫, N)을 더해가면
 되네!
 */
#include <iostream>

using namespace std;

int N, K;

int main() {
	cin >> N >> K;
	long long s = 1, e = N * N, m;
	long long count;
	while (s < e) {
		count = 0;
		m = s + e >> 1;
		for (int i = 1; i <= N; i++) {
			int x = (m / i <= N) ? m / i:N;
			count += x;
		}
		if (count >= K) {
			e = m;
		}
		else { s = m + 1; }
	}
	cout << e;
}