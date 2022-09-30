#include <bits/stdc++.h>
using namespace std;

int dp(vector<vector<int>> &happiness, vector<tuple<int, int, int>> &abc, int N) {
  
  happiness.at(0).at(0) = get<0>(abc.at(0));
  happiness.at(1).at(0) = get<1>(abc.at(0));
  happiness.at(2).at(0) = get<2>(abc.at(0));

  for (int i = 1; i < N; i++) {
    happiness.at(0).at(i) = get<0>(abc.at(i)) + max(happiness.at(1).at(i-1), happiness.at(2).at(i-1));
    happiness.at(1).at(i) = get<1>(abc.at(i)) + max(happiness.at(0).at(i-1), happiness.at(2).at(i-1));
    happiness.at(2).at(i) = get<2>(abc.at(i)) + max(happiness.at(0).at(i-1), happiness.at(1).at(i-1));
  }

  return max(max(happiness.at(0).at(N-1), happiness.at(1).at(N-1)), happiness.at(2).at(N-1));
}


int main() {
  int N;
  cin >> N;

  vector<vector<int>> happiness(3, vector<int>(N, -1));
  vector<tuple<int, int, int>> inputs(N);
  for (int i = 0; i < N; i++) {
    cin >> get<0>(inputs.at(i)) >> get<1>(inputs.at(i)) >> get<2>(inputs.at(i));
  }

  cout << dp(happiness, inputs, N) << endl;
}
