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

int main() {

  // DEBUG
  ifstream in("/home/konishi/workspace_atcoder/input.txt"); cin.rdbuf(in.rdbuf()); //

  int N, M;
  cin >> N >> M;


  vector<int> parents(N*N, -1);

  pair<int, int> st = {0,0};
  queue<pair<int,int>> visited;
  visited.push(st);


  int cnt = 0;
  // Queueを使うと計算量がN^4>10^9になってしまう
  while (!visited.empty()) {
    pair<int, int> v = visited.front();
    visited.pop();

    for (int k = 0; k < N; k++) {
      for (int l = 0; l < N; l++) {

        // まだ親が決まっていないノードの親を決める
        if ( parents.at(N*k+l) == -1  && (v.first-k)*(v.first-k) + (v.second-l)*(v.second-l) == M ) {
          parents.at(N*k+l) = N*v.first + v.second;
          visited.push({k, l});
        }
      }
    }
    cout << (cnt++) << endl;
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
