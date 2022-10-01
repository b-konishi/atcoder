#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline void pvec(vector<T> &vec) { for (T _vec : vec) { cout << _vec << " "; } cout << endl; } //

#define INF 1e9+1
#define MAX_SIZE 3e5

int main() {

  // DEBUG
  ifstream in("/home/konishi/workspace_atcoder/input.txt"); cin.rdbuf(in.rdbuf()); //

  int N;
  cin >> N;

  vector<bool> vols(N, 0);
  int spare = 0;
  for (int i = 0; i < N; i++) {
    int v;
    cin >> v;

    if (v <= N && !vols.at(v-1)) {
      vols.at(v-1) = 1;
    }
    else {
      spare ++;
    }
  }
  pvec(vols);//

  int res = N;
  for (int i = 0; i < res; i++) {
    if (spare == 0 && !vols.at(i)) {
      res = i+1;
      break;
    }

    if (!vols.at(i)) {
      vols.at(i) = 1;
      spare --;
      res --;
    }
  }

  pvec(vols);//
  cout << res << endl;
}
