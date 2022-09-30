#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());

  int X, Y, Z;
  cin >> X >> Y >> Z;

  bool accessible = 1;
  bool hammer = 0;

  // ゴールが壁の外にある場合
  if (!((X>0) ^ (Y>0)) && abs(Y) < abs(X)) {
    hammer = 1;
    
    // ハンマーが壁の外にある場合
    if (!((Z>0) ^ (Y>0)) && abs(Y) < abs(Z)) {
      accessible = 0;
    }
  }

  if (!accessible) {
    cout << -1 << endl;
  }
  else {
    if (hammer) {
      // ゴールとハンマーが同一方向の場合
      if (!((X>0) ^ (Z>0))) {
        cout << abs(X) << endl;
      }
      else {
        cout << 2*abs(Z) + abs(X) << endl;
      }
    }
    else {
      cout << abs(X) << endl;
    }
  }
  
}
