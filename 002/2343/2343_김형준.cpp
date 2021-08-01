#include <iostream>
#include <stack>
#include <limits>
using namespace std;

// 블루레이 1개 = N개의 레슨
// 순서대로 i~j번 레슨 쭈욱

//입력
//레슨수 N <=100000
//블루레이수 M <= N, 모두 같은 크기
//레슨길이가 분단위로 N개

//블루레이의 크기(녹화 가능한 길이)를 최소
//블루레이의 크기를 이진탐색

int M, N;
int arr[100000];
int total;
int maximum = INT32_MIN;
int minimum = INT32_MAX;
stack<int> buf;

int BSearch(int low, int high){
    if (low >= high) return low;
    int mid = (low + high) / 2;
    int sum = 0;
    int minute = 0;

    if (mid < maximum) return BSearch(mid+1, high);

    while(!buf.empty()) buf.pop();
    buf.push(0);

    for (int i = 0; i < N; i++)
    {
        if (arr[i] > mid) break;
        
        if (sum + arr[i] > mid)
        {
            sum = 0;
            buf.push(i);
        }

        sum += arr[i];
    }

    if (buf.size() > M) return BSearch(mid+1, high);
    else return BSearch(low, mid);
}

int main(){
    cin >> N >> M;
    for (int i = 0; i < N; i++) 
    {
        cin >> arr[i];
        total += arr[i];
        if (maximum < arr[i]) maximum = arr[i];
        if (minimum > arr[i]) minimum = arr[i];
    }
    cout << BSearch(maximum, total);
    return 0;
}
