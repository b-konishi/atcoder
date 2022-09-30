#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1e9;

int dp(vector<int> &hs, int N, int K) {
  vector<int> costs(N, INF);
  costs.at(0) = 0;
  
  for (int i = 1; i < N; i++) {
    if (costs.at(i) != INF)  continue;

    for (int k = 1; k <= K; k++) {
      if (i-k < 0)  break;
      chmin( costs.at(i), costs.at(i-k) + abs(hs.at(i) - hs.at(i-k)) );
    }
  }
  return costs.at(N-1);
}

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> heights(N);
  for (int i = 0; i < N; i++) {
    cin >> heights.at(i);
  }
  cout << dp(heights, N, K) << endl;
}

