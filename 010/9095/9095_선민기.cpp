#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> express = { 1, 2, 4 };	// #�� �迭�� �ε����� �� �ε����� �ش��ϴ� ����+1�� ǥ�������� �������� ������
	int test_case;

	cin >> test_case;

	for (int i = 3; i < 11; i++)
		// ##num�� 1 + (num-1)�� ǥ��, 2 + (num-2)�� ǥ��, 3 + (num-3)�� ǥ�� �� �̷����
		express.push_back(express[i - 1] + express[i - 2] + express[i - 3]);	

	for (int i = 0, data; i < test_case; i++) {
		cin >> data;
		cout << express[data - 1] << "\n";
	}


	return 0;
}