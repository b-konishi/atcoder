# atcoder

## Educational DP Contest

### A-Frog1
- 1次元DP

### B-Frog2
- 1次元DP

### C-Vacation
- 2次元DPを使用（縦:活動したときの瞬間幸福度 $A(i)$ (3種類:a/b/c), 横:日数 $N(j)$, 幸福度 $H(i,j)$ ）
- $H(i,j)$ <= $N(j-1)$ 日目の $A(i)$ 以外の活動の累積幸福度から最も高いものと、今日の活動 $A(i)$ の和
- 条件： $1\leq N \leq 10^5$, $1 \leq A_i \leq 10^4$
- 愚直計算量: $\mathcal{O}(2^N)$
- DP計算量: $\mathcal{O}(3N)=\mathcal{O}(N)$

### D-Knapsack1
- 2次元DPを使用(縦:商品インデックス $i < N$, 横:重さ $j < W$, 価値 $V(i,j)$ )
- 条件: $1 \leq N \leq 100$, $1 \leq v_i \leq 10^9$ であるため、 $1 \leq V(i,j) \leq 10^{11}$ となるため、 $-2 \times 10^9 \sim +2 \times 10^9$ 程度しか扱えない`int`(32bit)ではなく、`int64_t`を使用する


## Tips

### 基本テンプレート

```cpp
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1e9;
```
