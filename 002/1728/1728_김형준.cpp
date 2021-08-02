#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <limits>
using namespace std;

int N;
int minimum = INT32_MAX;
int maximum = INT32_MIN;
vector<vector<int>> pic;
vector<tuple<bool,int,int>> result;
bool success = false;

tuple<bool,int,int> BSearch(int x, int low, int high, int low2, int high2) {
  int mid = (low + high) / 2; // 시작지점
  int mid2 = (low2 + high2) / 2; // 속도

  cout << "mid: " << mid << ", mid2: " << mid2 << "\n";

  if (low >= high) return {false,0,0};
  if (low2 >= high2) {
    if (mid + mid2 >= pic[x][N-1])
      return BSearch(x, low, mid, minimum, maximum);
    else if (mid + mid2 < pic[x][0])
      return BSearch(x, mid+1, high, minimum, maximum);
    else {
      bool ok = false;
      bool ok2 = false;
      for (int i = 0; i < N+1; i++)
      {
          for (int j = 0; j < N; j++)
          {
            int item = pic[i][j];
            if ((item - mid) % mid2 == 0) 
            {
                ok = true;
                break;
            }
          }
          if (!ok) break;
          if (i == N) ok2 = true;
      }

      if (ok2) return {true, mid, mid2};
    }
  }

  if (mid + mid2 >= pic[x][N-1])
    return BSearch(x, low, high, low2, mid2);
  else if (mid + mid2 < pic[x][0])
    return BSearch(x, low, high, mid2+1, high2);
  else {
      bool ok = false;
      bool ok2 = false;
      for (int i = 0; i < N+1; i++)
      {
          for (int j = 0; j < N; j++)
          {
            int item = pic[i][j];
            if ((item - mid) % mid2 == 0) 
            {
                ok = true;
                break;
            }
          }
          if (!ok) break;
          if (i == N) ok2 = true;
      }

      if (ok2) return {true, mid, mid2};
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N+1; i++) {
    vector<int> item;
    for (int j = 0; j < N; j++) {
      int buf;
      cin >> buf;
      item.push_back(buf);
      if (minimum > buf) minimum = buf;
      if (maximum < buf) maximum = buf;
    }
    pic.push_back(item);
  }

  while(true)
  {
      for (int i = 0; i < N; i++)
      {
        tuple<bool,int,int> buf = BSearch(i, minimum, maximum, minimum, maximum);
        if (get<0>(buf)) result.push_back(buf);
        cout << get<1>(buf) << " " << get<2>(buf);
      }
      if (result.size() == N) break;
  }
  
  return 0;
}