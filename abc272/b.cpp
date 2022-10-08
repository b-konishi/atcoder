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
template<class T> inline void pvec2(vector<vector<T>> &vec) { for (auto v : vec) { for (auto h : v) { cout << h << " "; } cout << endl; }} //

int main() {

  // DEBUG
  ifstream in("/home/konishi/workspace_atcoder/input.txt"); cin.rdbuf(in.rdbuf()); //

  int N, M;
  cin >> N >> M;

  vector<vector<bool>> X(N, vector<bool>(N, false));
  for (int i = 0; i < N; i++) {
    X.at(i).at(i) = true;
  }

  for (int i = 0; i < M; i++) {
    int k;
    cin >> k;

    vector<int> check;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      check.push_back(x-1);

      for (auto c : check) {
        X.at(x-1).at(c) = true;
        X.at(c).at(x-1) = true;
      }
    }
  }
  pvec2(X);//

  bool attend = true;
  for (int i = 0; attend && i < N; i++) {
    for (int j = 0; attend && j < N; j++) {
      
      if (X.at(i).at(j) == false) { 
        attend = false;

      }
    }
  }



  YesNo(attend);
}
