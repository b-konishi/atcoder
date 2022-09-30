#include <bits/stdc++.h>
using namespace std;

template <typename T> inline T dist(T& a, T& b) {
  return max(a, b) - min(a, b);
}


int dp(vector<int> &costs, vector<int> &hs, int n) {

  if (n == 0) {
    costs.at(0) = 0;
  }
  else if (n == 1) {
    costs.at(1) = dist(hs.at(1), hs.at(0));
  }
  else if (costs.at(n) == -1) {
    costs.at(n) = min(dp(costs, hs, n-1) + dist(hs.at(n), hs.at(n-1)), dp(costs, hs, n-2) + dist(hs.at(n), hs.at(n-2)));
  }
  return costs.at(n);
}


int main() {
  int N;
  cin >> N;

  vector<int> heights(N);
  for (int i = 0; i < N; i++) {
    cin >> heights.at(i);
  }
  vector<int> costs(N, -1);
  cout << dp(costs, heights, N-1) << endl;
}
