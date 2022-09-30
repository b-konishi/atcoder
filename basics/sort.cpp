#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;

  vector<pair<int, int>> p;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    p.push_back(make_pair(b, a));
  }

  sort(p.begin(), p.end());

  for (pair<int, int> pi : p) {
    cout << pi.second << " " << pi.first << endl;
  }
}


