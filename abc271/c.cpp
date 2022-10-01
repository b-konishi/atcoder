// 解けていない (Sample:3/3, All:13/29)

#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

void pvec(vector<int> &a) {
  for (int aa : a) {
    cout << aa << " ";
  }
  cout << endl;
}

#define INF 1e9+1
#define MAX_SIZE 3e5

int main() {

  // DEBUG
  ifstream in("/home/konishi/workspace_atcoder/input.txt"); cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;

  vector<int> a(N, INF);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }

  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  int spare = N-a.size();
  for (int i = 0; i < spare; i++) {
    a.push_back(INF+i);
  }

  int res = 0;
  int a_idx = 0;
  int a_max = a.size()-1;
  for (int i = 1; i < N; i++) {
    if (a.at(a_idx) == i) {
      res ++;
      a_idx ++;
    }
    else {
      if (a.at(a_max-1) > a.at(a_idx)) {
        a_max -= 2;
        res += 1;
      } else {
        break;
      }
    }
  }

  cout << res << endl;
}
