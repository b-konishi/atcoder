#include <bits/stdc++.h>
using namespace std;


template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

// Prime factorization (pair<value, ex>)
template<class T> inline vector<pair<T, T>> pf(T N) { vector<pair<T, T>> factors; for (T i = 2; i*i <= N; i++) { if (N % i == 0) { N /= i; T ex = 1; while (N % i == 0) { ex++; N /= i; } factors.push_back({i,ex}); } } if (N != 1) factors.push_back({N, 1}); return factors; }

// 文字列sに文字cが含まれるか
inline bool chkchar(string &s, char c) { return s.find(c) != string::npos; }

inline void YESNO(bool c) { cout << (c ? "YES" : "NO") << endl; }
inline void YesNo(bool c) { cout << (c ? "Yes" : "No") << endl; }
inline void yesno(bool c) { cout << (c ? "yes" : "no") << endl; }
template<class T> inline void pvec1(vector<T> &vec) { for (T _vec : vec) { cout << _vec << " "; } cout << endl; } //
template<class T> inline void pvec2(vector<vector<T>> &vec) { for (T v : vec) { for (T h : v) { cout << h << " "; } cout << endl; }} //


vector<int> root_vec (int N) {
  vector<int> x(N+1, -1);
  for (int i = 0; i*i <= N; i++) {
    x.at(i*i) = i;
  }
  return x;
}

int main() {

  // DEBUG
  ifstream in("/home/konishi/workspace_atcoder/input.txt"); cin.rdbuf(in.rdbuf()); //

  int N, M;
  cin >> N >> M;


  vector<int> parents(N*N, -1);

  pair<int, int> st = {0,0};
  queue<pair<int,int>> visited;
  visited.push(st);

  vector<int> roots = root_vec(M);

  // 数学的制約を考慮せずに愚直に実装すると、計算量がN^4>10^9になってしまう
  // 片側軸を固定すれば、N^3に抑えられる

  int cnt = 0;
  while (!visited.empty()) {
    pair<int, int> v = visited.front();
    visited.pop();

    for (int k = 0; k < N; k++) {

      int m =  M - (k-v.first) * (k-v.first);
      if (m < 0 || roots.at(m) == -1) {
        continue;
      }
      int l1 = v.second + roots.at(m);
      int l2 = v.second - roots.at(m);

      if (l1 >= 0 && l1 < N && parents.at(N*k+l1) == -1) {
        parents.at(N*k + l1) = N*v.first + v.second;
        visited.push({k, l1});
      }
      if (l2 >= 0 && l2 < N && parents.at(N*k+l2) == -1) {
        parents.at(N*k + l2) = N*v.first + v.second;
        visited.push({k, l2});
      }
    }
  }


  cout << 0 << " ";
  for (int i = 1; i < N*N; i++) {
    if (parents.at(i) != -1) {
      int cnt = 1;
      int p = parents.at(i);
      while (p != 0) {
        cnt ++;
        p = parents.at(p);
      }
      cout << cnt;
    } else {
      cout << -1;
    }
    
    if ( (i+1) % N == 0) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  
}
