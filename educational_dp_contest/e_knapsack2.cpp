#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<vector<int64_t>> &dp, vector<pair<int,int>> &wv, int N, int W) {

  for (int j = 0; j <= W; j++) {
    if (wv.at(0).first <= j)  dp.at(0).at(j) = wv.at(0).second;
  }

  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= W; j++) {

      if (j < wv.at(i).first) {
        dp.at(i).at(j) = dp.at(i-1).at(j);
      }
      else {
        dp.at(i).at(j) = dp.at(i-1).at(j);

        if (wv.at(i).second + dp.at(i-1).at(j-wv.at(i).first) > dp.at(i-1).at(j)) {
          dp.at(i).at(j) = wv.at(i).second + dp.at(i-1).at(j-wv.at(i).first);
        }
      }
    }
  }
  return dp.at(N-1).at(W);
}

int main() {
  int N, W;
  cin >> N >> W;

  vector<pair<int,int>> inputs(N);
  for (int i = 0; i < N; i++) { 
    cin >> inputs.at(i).first >> inputs.at(i).second;
  }

  vector<vector<int>> dp(N, vector<int>(W+1, 0));
  cout << knapsack(dp, inputs, N, W) << endl;
}
