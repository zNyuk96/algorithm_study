#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 3회 시도하였으나 시간초과입니다... 으악

int BSearch(vector<int> arr, int target, int low_idx, int high_idx) {
    if (low_idx > high_idx) return -1;

    int mid_idx = (low_idx + high_idx) / 2;

    if (arr[mid_idx] >= target)
    {
        // 내가 타겟값보다 크면 나보다 더 작은 애가 있는지 찾아본다
        int buf = BSearch(arr, target, low_idx, mid_idx - 1);

        if (buf == -1)
            return mid_idx; // 나보다 더 작은애가 없으면 나를 반환(조건을 만족하는 인덱스 중 가장 왼쪽)
        else
            return buf; // 내 왼쪽에 타겟이 있거나 내 왼쪽애랑 내가 같으면 걔를 반환(조건을 만족하는 인덱스 중 가장 왼쪽)
    }
    else
    {   
        // 내가 타겟값보다 작으면 내 오른쪽에 나보다 더 큰 애가 있는지 찾아본다
        int buf = BSearch(arr, target, mid_idx + 1, high_idx);

        if (buf == -1)
            return mid_idx + 1; // 내 오른쪽에도 타겟이 없으면 그냥 내 오른쪽 애의 인덱스를 반환(조건을 만족하는 인덱스 중 가장 왼쪽)
        else
            return buf; // 내 오른쪽에도 타겟이 있거나 내 오른쪽 애랑 내가 같은애면 걔를 반환 ???
    }
}

int main() {
    int N; // 동굴의 길이, 짝수, 2 <= N <= 200000
    int H; // 동굴의 높이, 2 <= H <= 500000
    vector<int> seoksoon;
    vector<int> jongyuseok;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // 동굴 길이, 높이 입력
    cin >> N >> H;

    // 석순 종유석 길이 나눠서 입력받기
    for (int i = 0; i < N; i++)
    {
        int buf;
        cin >> buf;

        if (i % 2 == 0)
            seoksoon.push_back(buf);
        else
            jongyuseok.push_back(buf);
    }

    // 석순 길이와 종유석 길이 오름차순 정렬
    // 순서 상관 X
    sort(seoksoon.begin(), seoksoon.end());
    sort(jongyuseok.begin(), jongyuseok.end());

    int min_val = 500001;
    int min_count = 0;

    int seoksoon_len = seoksoon.size();
    int jongyuseok_len = jongyuseok.size();

    // 이진탐색
    for (int i = 1; i <= H; i++)
    {
        int s = BSearch(seoksoon, i, 0, seoksoon_len - 1);
        int j = BSearch(jongyuseok, H-(i-1), 0, jongyuseok_len - 1);
        int sum = 0;

        if (s != -1) sum += seoksoon_len - s;
        if (j != -1) sum += jongyuseok_len - j;

        if (min_val > sum)
        {
            min_val = sum;
            min_count = 1;
        } 
        else if (min_val == sum)
        {
            min_count++;
        }
    }

    cout << min_val << " " << min_count;

    return 0;
}