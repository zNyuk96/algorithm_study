#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> express = { 1, 2, 4 };	// #각 배열의 인덱스는 그 인덱스에 해당하는 숫자+1의 표현가능한 가지수를 저장함
	int test_case;

	cin >> test_case;

	for (int i = 3; i < 11; i++)
		// ##num은 1 + (num-1)의 표현, 2 + (num-2)의 표현, 3 + (num-3)의 표현 로 이루어짐
		express.push_back(express[i - 1] + express[i - 2] + express[i - 3]);	

	for (int i = 0, data; i < test_case; i++) {
		cin >> data;
		cout << express[data - 1] << "\n";
	}


	return 0;
}