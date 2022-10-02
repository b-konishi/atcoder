#include <bits/stdc++.h>
using namespace std;


template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
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

  bool finish = false;

  // a[i]=0(X%M=0)のときに、その時の桁の値を記録する
  vector<int> checks(N, 0);

  // 桁の数値が大きい方からループを回し記録する
  // 既に記録してある場合はなにもしない(dが大きい方が優先: ex. 55555 > 33333)
  // 計算量はO(10N)=O(N)<10^5
  int a;
  for (int d = 9; d >= 1; d--) {
    a = 0;
    for (int i = 1; i <= N; i++) {
      a = (10*a + d) % M;
      if (a == 0 && checks.at(i-1) == 0) {
        checks.at(i-1) = d;
      }
    }
  }
  for (int i = N-1; i >= 0; i--) {
    if (checks.at(i) == 0)  continue;
      
    for (int j = 0; j < i+1; j++) {
      cout << checks.at(i);
    }
    finish = true;
    break;
  }
  
  if (!finish) cout << -1;
  cout << endl;
}
