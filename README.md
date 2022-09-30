# atcoder

## Educational DP Contest

### A-Frog1

### B-Frog2

### C-Vacation
- 2次元DPを使用（縦:活動したときの瞬間幸福度A(i)(3種類:a/b/c), 横:日数N(j), 幸福度H(i,j)）
- H(i,j) <= N(j-1)日目のA(i)以外の活動の累積幸福度から最も高いものと、今日の活動A(i)の和
- 条件： $1\leq N \leq 10^5$, $1 \leq A_i \leq 10^4$
- 愚直計算量: $\mathcal{O}(2^N)$
- DP計算量: $\mathcal{O}(3N)=\mathcal{O}(N)$

