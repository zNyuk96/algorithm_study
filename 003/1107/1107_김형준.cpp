#include <iostream>
#include <string>
using namespace std;

int N, M;
int channel = 100;
int brokenNumber[10] = { 0 };

int validChannel(int nChannel) {
	string sChannel = to_string(nChannel);
	int size = sChannel.length();

	for (int i = 0; i < size; i++)
		if (brokenNumber[sChannel[i] - '0']) return 0;
	return 1;
}

int run(int nChannel){
	int minimum = abs(channel - nChannel);

	for (int i = 0; i <= 1000000; i++)
		if ( validChannel(i) && minimum > (to_string(i).length() + abs(i - nChannel)) ) 
			minimum = to_string(i).length() + abs(i - nChannel);

	return minimum;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int buf;
		cin >> buf;
		brokenNumber[buf]++;
	}

	cout << run(N);
	
	return 0;
}