#include <iostream>
using namespace std;

/*
입력 받을 때마다 누적합을 저장하는 long long sum[100000]을 만들고,
i~j 는 sum[j]-sum[i-1]이런식으로 구할 수는 있겠다.. 근데 이걸 어떻게 활용함?.?
누적합으로 일단 BS를 위한 기울기는 만들어 졌고,
축은 무엇으로 할 것인가... 는 블루레이 길이의 최소값!
근데 굳이 입력에서 누적합 할 필요는 없네!

최소값을 넘지 않을 때까지 담아가면서 담은 그룹이 총 M개가 되어야 한다
최소로 가기 위해서 M개를 만족시키는 블루레이 길이를 BS과정에서 작은값으로 밀어야한다
가즈아~
*/


int N, M;
int arr[100000];
int count_cd(int x) {
	int idx = 0; 
	int sum = 0;
	int cnt = 1;
	while (idx < N) {
		if (sum + arr[idx] <= x) {
			sum += arr[idx++];
		}
		else {
			if (x < arr[idx]) return 1e9;
			cnt++;
			sum = arr[idx++];
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);;
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int s = 1, e = N * 10000;
	while (s < e) {
		int m = s + e >> 1;
		int temp = count_cd(m);
		if (temp <= M) {   // 같은 애들중에서 '민다'라는 개념 생각해보자.
			e = m;
		}
		else {
			s = m + 1;
		}
	}
	cout << e;
	return 0;
}