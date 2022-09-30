#include <bits/stdc++.h>
using namespace std;

vector<tuple<bool,bool,bool>> table = 
{
  {0,0,0},
  {1,0,0},
  {0,1,0},
  {1,1,0},
  {0,0,1},
  {1,0,1},
  {0,1,1},
  {1,1,1}
};

vector<int> points = {1,2,4};

int main() {
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());

  int A, B;
  cin >> A >> B;

  tuple<bool,bool,bool> tuple_a = table.at(A);
  tuple<bool,bool,bool> tuple_b = table.at(B);

  int sum = points.at(0) * (get<0>(tuple_a) | get<0>(tuple_b)) +
            points.at(1) * (get<1>(tuple_a) | get<1>(tuple_b)) +
            points.at(2) * (get<2>(tuple_a) | get<2>(tuple_b));

  cout << sum << endl;
}
