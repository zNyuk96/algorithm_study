#include <iostream>
#include <algorithm>

using namespace std;
int N;
int arr[10000];
//dat 써볼까..?
//bs 추가해서 최적화 해보자
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr[i] = temp + 10000;
	}
	sort(arr, arr + N);
	long long cnt = 0;
	for (int i = 1; i < N; i++) {
 		int pivot = arr[i];
		int l = 0, r = N - 1;
		while (l<i && r>i) {
			if (arr[r] + arr[l] + pivot > 30000) r--;
			else if (arr[r] + arr[l] + pivot == 30000) { // 투포인터 하는데 문제점은 같은 값이 여러개일때이다
				int lnum = 1, rnum = 1;
				//cout<<i<<" " << arr[l]-10000<< " "<<pivot-10000<<" " << arr[r]-10000<<endl;
				while (r - 1 > i && arr[r] == arr[r - 1]) {
					r--; rnum++;
				}
				while (l + 1 < i && arr[l] == arr[l + 1]) {
					l++; lnum++;
				}
				cnt += rnum * lnum;
				r--;
				l++;
			}
			else l++;
		}
	}
	cout << cnt;
}