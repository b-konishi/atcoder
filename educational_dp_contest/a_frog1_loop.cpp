#include <bits/stdc++.h>
using namespace std;

int dp(vector<int> &hs, int N) {
  vector<int> costs(N, -1);

  costs.at(0) = 0;
  costs.at(1) = abs(hs.at(0) - hs.at(1));
  
  for (int i = 2; i < N; i++) {
    if (costs.at(i) == -1) {
      costs.at(i) = min(costs.at(i-2) + abs(hs.at(i) - hs.at(i-2)), costs.at(i-1) + abs(hs.at(i) - hs.at(i-1)));
    }
  }
  return costs.at(N-1);
}

int main() {
  int N;
  cin >> N;

  vector<int> heights(N);
  for (int i = 0; i < N; i++) {
    cin >> heights.at(i);
  }
  cout << dp(heights, N) << endl;
}
