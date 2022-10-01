#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main() {

  // DEBUG
  ifstream in("/home/konishi/workspace_atcoder/input.txt"); cin.rdbuf(in.rdbuf());

  int N, Q;
  cin >> N >> Q;

  vector<int> L(N);
  vector<vector<int>> a(N, vector<int>(0));
  for (int i = 0; i < N; i++) {
    cin >> L.at(i);
    for (int j = 0; j < L.at(i); j++) {
      int in;
      cin >> in;
      a.at(i).push_back(in);
    }
  }

  for (int i = 0; i < Q; i++) {
    int s, t;
    cin >> s >> t;
    cout << a.at(s-1).at(t-1) << endl;
  }
}
